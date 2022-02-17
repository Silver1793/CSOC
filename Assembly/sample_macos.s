

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


	# this function is called from C and takes no parameters.
	# it just calls add1(5) and adds 10 to the result, and
	# returns that value. It includes an example of
	# saving/restoring the callee-saved register %rbx
_go:

	pushq	%rbp
	movq	%rsp, %rbp
	
	pushq	%rbx		# save %rbx, since it is callee saved	
	
	mov	$10,%ebx	# callee saved register

	movl	$5,%edi  	# passing 5 to add1 by putting 5 in the %edi register
	call	_add1		# result will be in %eax,
	                        # guaranteed that _add1 will not modify %ebx

	add	%ebx,%eax   # adding to the return value (should total 16)
	
	popq	%rbx	# restoring %rbx
	
	popq	%rbp
	retq



	# this function is called from C and it's C prototype
	# is:
	#     void fill_in(PERSON *p, char *name, int age, int salary);
	# It fills in the PERSON struct pointed to by p with the
	# specified name, age, and salary parameters

	.globl	_fill_in
	.p2align	4, 0x90


	# p in %rdi
	# name in %rsi
	# age in %edx
	# salary in %rcx

_fill_in:

	# offset of name is 0, offset of age is 8, offset of salary is 12, offset of next is 16

	pushq	%rbp
	movq	%rsp, %rbp

	movq	%rsi,0(%rdi)	# p->name = name
	movl	%edx,8(%rdi)	# p->age = age
	movl	%ecx,12(%rdi)	# p->salary = salary

	popq	%rbp
	retq

	



	# This function searches down a linked list of PERSON structs
	# and returns the name field of the struct with the highest
	# age

	# The corresponding C code would be:

	#   char *oldest(PERSON *head)
	#   {
	##   if (head == NULL)
	#     return NULL;
	#   int max_age = head->age;
	#   char *oldest_name = head->name;
	#   PERSON *p = head->next;
	#   while (p != NULL) {
	##    if (p->age > max_age) {
	#       max_age = p->age;
	#       oldest_name = p->name;
	#     }
	#     p = p->next;
	#   }
	#   return oldest_name;
	#   }

	.globl	_oldest
	.p2align	4, 0x90

_oldest:	

	pushq	%rbp
	movq	%rsp, %rbp

	# offset of name is 0, offset of age is 8, offset of salary is 12, offset of next is 16	
	# head is in %rdi (parameter)
	# oldest_name in %rax  (since it's the return value)
	# max_age in %ecx
	# p in %rdx

	mov	$0,%rax   # initialize oldest_name to NULL (0)
	cmp	$0,%rdi   # if (head == NULL)
	je	DONE	  #   return NULL (already in %rax), by jumping to DONE

	movl	8(%rdi),%ecx	# max_age = head->age
	movq	0(%rdi),%rax	# oldest_name = head->name

	movq	16(%rdi),%rdx	# p = head->next
TOP:
	cmp	$0,%rdx		# if (p == NULL)
	je	DONE		#   jump out of loop
	cmpl	%ecx,8(%rdx)	# if (p->age <= max_age), don't change max_age
	jle	CONTINUE
	movl	8(%rdx),%ecx    # otherwise, max_age = p->age
	movq	0(%rdx),%rax	#            oldest_name = p->name
CONTINUE:	
	movq	16(%rdx),%rdx	# p = p->next
	jmp	TOP		# jump to top of loop
	
DONE:
	# oldest_name already in %rax, just return
	
	popq	%rbp
	retq

	
