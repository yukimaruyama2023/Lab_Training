.text
.global caller_struct2

caller_struct2:
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp
    movq $111, -32(%rbp)
    movq $222, -24(%rbp)
    movq $333, -16(%rbp)
    movq $444, -8(%rbp)

    callq callee_struct2

    movq %rbp, %rsp
    popq %rbp
    retq
