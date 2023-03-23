.text
.global caller_struct

caller_struct:
    pushq %rbp
    movq %rsp, %rbp

    callq callee_ret_struct

    addq $200, %rax
    addq $200, %rdx

    movq %rax, %rdi
    movq %rdx, %rsi

    callq callee_struct

    movq %rbp, %rsp
    popq %rbp
    retq
