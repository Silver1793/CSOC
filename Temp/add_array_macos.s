        # LEAVE THIS PART ALONE
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_add_array
	.p2align	4, 0x90

	
_add_array:

	# For Unix (including MacOS and Linux), the calling convention
	# is that the first six integer/pointer parameters (in order): %rdi,
	# %rsi, %rdx, %rcx, %r8, %r9 (or their 32-bit halves %edi, %rsi, etc.
	# for 32-bit parameters). The return value is put into %rax (or
	# %eax for a 32-bit return value).

	# In general, you can overwrite the 64-bit
	# registers %rax, %rcx, %rdx, %rsi, %rdi, %r8, %r9, %r10, %r11,
	# as well as their 32-bit halves, %eax, %ecx, %edx,
	# %esi, %edi, %r8d, %r9d, %r10d, %r11d as you like. These are
	# the "caller-saved" registers.

	pushq	%rbp         # LEAVE THIS ALONE
	movq	%rsp, %rbp   # LEAVE THIS ALONE

	# sum = 0   -- put %eax
	# for (i = 0 ; i < size; i++)   -- put i in %ecx
	#    sum += a[i]
	
	# %rdi holds the first parameter, which is a (address of the array)
	# %esi hold the size.

	movl	$0,%eax   # sum = 0
	movl	$0,%ecx	  # i = 0
TOP:				# top of loop
	cmpl	%esi,%ecx       # compare i (%ecx) to size (%esi) -- remember, read it "backwards"
	jge     DONE            # if i > size, jump out of loop.
	addl	(%rdi,%rcx,4),%eax     # sum += a[i].  The index, in this case %rcx, used in the
	                               # indexed addressing mode has to be 64 bits. Since i is
	                               # contained in %ecx, using %rcx will give us the value of i.
	                                              
	incl	%ecx        # i++
	jmp	TOP         # jump to top of loop

DONE:	
	# sum is alread in %eax, so no need to do anything eldse

	popq	%rbp    # LEAVE THIS ALONE
	retq            # LEAVE THIS ALONE

