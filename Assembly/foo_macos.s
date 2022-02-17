# THIS IS THE UNIX (MACOS, LINUX) CALLING CONVENTION:
#
# Passing Parameters:
#  First six integer/pointer parameters (in order): %rdi, %rsi, %rdx, %rcx, %r8, %r9
#        (or correspoding 32-bit halves)

#  Additional parameters are passed on the stack, pushed in right-to-left (reverse) order.

# Return Value: %rax (for 64-bit result), %eax (for 32-bit result)

# Caller-Saved Registers (may be overwritten by called function):
#    %rax , %rcx , %rdx , %rdi , %rsi , %rsp , %r8, %r9, %r10, %r11

# Callee-Saved Registers (must be preserved – or saved and restored – by called function):
#    %rbx, %rbp, %r12, %r13, %r14, %r15


	.section	__TEXT,__text,regular,pure_instructions
	.globl	_go
	.p2align	4, 0x90

	# this function will have a local int variable x at -4(%rbp),
	# will call the C function write6, passing the *address* of x,
	# and then call printf to print the value of x
_go:
	push	%rbp
	movq	%rsp,%rbp

	subq	$16,%rsp    # making room for a 4 byte variable, but keeping 16-byte boundary
	                    # since calls to C are occurring.

	# getting ready to call write6, passing the address of x (namely the address of -4(%rbp)
	# in %rdi

	leaq	-4(%rbp),%rdi		# passing the *address of x*
	call	_write6

	# Now printing the value of x
	
	leaq	stringforx(%rip),%rdi	# first parameter is the format string
	movl	-4(%rbp),%esi		# second parameter is the value of x (32 bits)
	xorq	%rax,%rax		# printf requires that %rax is zero
	call	_printf

	# all done, nothing to return

	addq	$16,%rsp	# removing local space from stack
	
	pop	%rbp
	retq
	


// Each string is defined by a label, followed by ".asciz" and the string literal
// in the usual double quotes.

stringforx:                                 
	.asciz	"After call to write6, x = %d\n"
	

	

	.section	__TEXT,__text,regular,pure_instructions
	.globl	_foo
	.p2align	4, 0x90

	// This function implements the following simple C code, providing an
	// example of the use of the stack (and %rbp and %rsp):

	// int foo(int a, int b, int c, int d, int e, int f, int g, int h, int i)
	// {
	//   int x, y, z;
	//   x = g+1;
	//   y = h+1;
	//   z = i+1;
	// return x+y+z;
	// }
	
_foo: 


	pushq	%rbp 
	movq	%rsp, %rbp

	subq	$32,%rsp	#allocate space for %rbp plus three 4-byte local variables, keeping 16-byte alignment

	# return address is at %rbp + 8
	# g is at %rbp + 16    # these are 8 bytes apart due to pushes
	# h is at %rbp + 24
	# i is at %rbp + 32

	# simple translation, keep x, y, z in memory

	# storing %rbx at %rbp-8

	# x is at %rbp - 12     # these can be 4 bytes apart
	# y is at %rbp - 16
	# z is at %rbp - 20
	# result is at %rbp - 24
	
	# using a callee-saved register %rbx as a temporary

	movq	%rbx,-8(%rbp)	 # saving callee-saved register

	movl	16(%rbp),%ebx     # move g to %ebx
	inc	%ebx		 # increment %ebx
	movl	%ebx, -12(%rbp)   # move %ebx to x

	# calling print_int to print x
	# no caller-saved registers need saving

	movl	-12(%rbp),%edi
	call	_print_int

	movl	24(%rbp),%ebx     # move h to %ebx
	inc	%ebx		 # increment %ebx
	movl	%ebx, -16(%rbp)   # move %ebx to y

	# calling print_int to print y
	# no caller-saved registers need saving

	movl	-16(%rbp),%edi
	call	_print_int
	
	
	movl	32(%rbp),%ebx     # move i to %ebx
	inc	%ebx		 # increment %ebx
	movl	%ebx, -20(%rbp)   # move %ebx to z


	# calling print_int to print z
	# no caller-saved registers need saving

	movl	-20(%rbp),%edi
	call	_print_int

	# let's use %ecx to hold the result. It's premature
	# to put it in %eax, since we are calling _printf
	# below before returning

	movl	-12(%rbp),%ebx    # temp (in %ebx) = x 
	addl	-16(%rbp),%ebx    #                   + y
	addl	-20(%rbp),%ebx    #                       + z

	# Notice that since %ebx is callee-saved, we don't
	# have to worry about saving it before the call to printf
	
	# calling _printf directly from assembly
	# it expects %rax to be 0, and expects %rsp to be at a
	#  32-byte boundary (which it is, see above).

	xor	%rax,%rax		# fastest way of setting %rax = 0
	leaq	myString(%rip), %rdi	# address of format string in %rdi
	movl	%ebx,%esi	 	# the result is the second parameter to printf
	call	_printf			# calling printf

	mov	%ebx,%eax	# put result in %eax for return value.
	
	movq	-8(%rbp),%rbx	# restoring callee-saved register %rbx

	addq	$32,%rsp  # removing allocated space for local variables

	popq	%rbp  
	retq          


	.section	__TEXT,__cstring,cstring_literals

// Each string is defined by a label, followed by ".asciz" and the string literal
// in the usual double quotes.

myString:                                 
	.asciz	"Result is %d\n"
	



# The following assembly implements this C code:
   //  int stack_array()
   //  {
   //    int x = 0;
   //    int a[10];
   //  
   //    for(int i = 0; i < 10; i++) {
   //      a[i] = i;
   //    }
   //  
   //    for (int i = 0; i < 10; i++) {
   //      x += a[i];
   //    }
   //    return x;
   //  }
   //  	
   //  


	.section	__TEXT,__text,regular,pure_instructions
	.globl	_stack_array
	.p2align	4, 0x90

_stack_array:
	pushq	%rbp
	mov	%rsp,%rbp

	# x is at -4(%rbp)
	# a starts at -4(%rbp), so index from there.
	# use %ecx for i

	subq	$44,%rsp	# make room for x and a[]

	movl	$0,-4(%rbp)	# x = 0
	movl	$0,%ecx		# i = 0

TOP1:
	cmp	$10,%ecx	# if i >= 10
	jge	OUT1            #    jump out of loop

	mov	%ecx,-44(%rbp,%rcx,4)  	#otherwise, a[i] = i
	inc	%ecx			# i++
	jmp	TOP1

OUT1:
	
	movl	$0,%ecx		# i = 0

TOP2:
	cmp	$10,%ecx	# if i >= 10
	jge	OUT2            #    jump out of loop

	mov	-44(%rbp,%rcx,4),%edx   # x += a[i], requires two instructions
	add	%edx,-4(%rbp)		# temporarily using a register (%edx)

	inc	%ecx			# i++
	jmp	TOP2

OUT2:
	
	movl	-4(%rbp),%eax  # return x by moving it into %eax

	addq	$44,%rsp	# remove local variables

	popq	%rbp
	ret
	
