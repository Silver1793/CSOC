        # LEAVE THIS PART ALONE
	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_sum_squares            
	.p2align	4, 0x90

	# This is the definition of the sum_squares function.
	# See the declaration in sum_squares.h
	# The function takes one parameter:
	#   -- a 32-bit integer n in the %edi register
	# It returns the sum of squares of the numbers from 1 to n.
	# The return value, being 32 bits, must be placed in the %eax register.
	
_sum_squares:                            

	# In general, you can overwrite the 64-bit
	# registers %rax, %rcx, %rdx, %rsi, %rdi, %r8, %r9, %r10, %r11,
	# as well as their 32-bit halves, %eax, %ecx, %edx,
	# %esi, %edi, %r8d, %r9d, %r10d, %r11d as you like. These are
	# the "caller-saved" registers.

	# NOTE: In this assignment, you only need to use 32-bit
	# registers for the computation (i.e. %eax, %ecx, %edx, etc.)
	
	pushq	%rbp         # LEAVE THIS ALONE
	movq	%rsp, %rbp   # LEAVE THIS ALONE

	movl	%edi, -4(%rbp) # parameter
	movl	$0, -8(%rbp) # creates sum variable
	movl 	-8(%rbp), %eax	 # moves sum to eax register
	movl	$1, -12(%rbp)	# creates variable i

	L1:	# start of the loop
	movl -12(%rbp), %ecx # sets i to a register
	cmpl -4(%rbp), %ecx # compares the parameter to the number in the register (i)
	jg L2	# if the comparison is greater than, jumps out of the loop

	imull %ecx, %ecx # multiplies the register by the register
	addl %ecx, %eax	# adds the register to sum
	addl $1, -12(%rbp) 	# increments i by 1
	jmp L1	# jumps back to the start of the loop

	L2:	# out of the loop

	/* FILL THIS IN */  # sum = 0, since sum is to be returned,
	                    #          use %eax to hold sum.

	/* FILL THIS IN */  # i = 1

/* THIS IS THE TOP OF THE LOOP, NEED A LABEL */	

	/* FILL THIS IN */  # compare i to n
	/* FILL THIS IN */  # greater than n, jump out of loop

	/* FILL THIS IN */  # copy i into another register
	/* FILL THIS IN */  # multiply that register by i to get i*i
	/* FILL THIS IN */  # add that register to sum
	
	/* FILL THIS IN */  # i++
	/* FILL THIS IN */  # jump to top of loop

/* THIS IS OUTSIDE THE LOOP, NEED A LABEL */	

	                # the return value, sum, is already in %eax
					
	popq	%rbp    # LEAVE THIS ALONE
	retq            # LEAVE THIS ALONE

