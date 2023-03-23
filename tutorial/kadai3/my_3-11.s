.text
.global caller_int3

caller_int3:
    pushq %rbp
    movq %rsp, %rbp

    movq $111, %rdi
    movq $222, %rsi
    movq $333, %rdx

    callq callee_int3

    addq $1000, %rax
    movq %rax, %rdi

    call check_ret
    
    movq %rbp, %rsp
    popq %rbp
    retq
    