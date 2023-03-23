.text
.global caller_int3

caller_int3:
    pushq %rbp
    movq %rsp, %rbp

    subq $16, %rsp
    movq $111, %rdi
    movq $222, %rsi
    movq $333, %rdx
    movq $444, %rcx
    movq $555, %r8
    movq $666, %r9
    movq $777, 0(%rsp)

    #pushq $888
    #pushq $777

    callq callee_int3

    addq $1000, %rax
    movq %rax, %rdi

    callq check_ret
    
    movq %rbp, %rsp
    popq %rbp
    retq
