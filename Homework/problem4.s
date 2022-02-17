	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_test          
	.p2align	4, 0x90
_test:
    pushq %rbp
    movq %rsp, %rbp

    movq $0, %r9 # i
    movl $0, %eax
    movq (%rbx, %r9, 4), %r10

    movl %esi, %ecx
    movq %rdi, %rbx

    top:
    cmpl %ecx, %r9d # compares r9d(i) to the size 
    jl Start # Goes to start if i is less than size
    # cmpl %ecx, %r9d # compares rcx(i) to the size 
    jmp end # goes to the end if they are greater than or equal
    # jge end

    Start:
    cmpl $0, %r9d # compares the i to 0
    je equal # goes to equal if they are the same
    cmp (%rbx, %rax, 4), %r10 # compares the value in the array to the value in the array at eax
    jg greater # if r10 value is greater goes to greater
    incq %r9 # if it is not greate it adds 1 to i
    movq (%rbx, %r9, 4), %r10 # changes r10 to the value at index i
    jmp top # goes back to start


    equal:
    movl %r9d, %eax # moves i into eax
    movq (%rbx, %r9, 4), %r10 # moves value of i into r10
    incq %r9 # increments r9 by 1
    jmp top # goes back to the start

    greater:
    movl %r9d, %eax # moves the index of r9 into eax
    movq (%rbx, %r9, 4), %r10 # moves the value at r9 into r10
    incq %r9 # increase r9 by 1
    jmp top # goes back to the top

    end:
    popq %rbp
    ret

