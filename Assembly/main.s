_test:
push %rsp
movq %rsp, %rbp
movq $10, %rcx
leaq(%rbx,%rcx, 4),%rax
subq %rbx, %rax
pop %rsp
retq