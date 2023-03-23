.text
.global caller_struct2

caller_struct2:
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp
    movq %rsp, %rdi 

    callq callee_ret_struct2

    addq $100, 0(%rsp)
    addq $100, 8(%rsp)
    addq $100, 16(%rsp)
    addq $100, 24(%rsp)

    callq callee_struct2

    movq %rbp, %rsp
    popq %rbp
    retq
    