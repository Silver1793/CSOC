	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_test          
	.p2align	4, 0x90
_test:
    	pushq	%rbp
	movq	%rsp, %rbp
    movq(%rdi),%rax
    popq %rbp
    ret

