.text
.global caller_struct

caller_struct:
    pushq %rbp
    movq %rsp, %rbp

    movq $111, %rdi
    movq $222, %rsi

    callq callee_struct

    movq %rbp, %rsp
    popq %rbp
    retq
