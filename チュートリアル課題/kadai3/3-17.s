	.file	"3-17.c"
	.text
	.section	.rodata
.LC0:
	.string	"callee_ret_struct:"
.LC1:
	.string	"\t.x = %ld\n"
.LC2:
	.string	"\t.y = %ld\n"
.LC3:
	.string	"\t.z = %ld\n"
.LC4:
	.string	"\t.w = %ld\n"
	.text
	.globl	callee_ret_struct2
	.type	callee_ret_struct2, @function
callee_ret_struct2:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	$123, -32(%rbp)
	movq	$456, -24(%rbp)
	movq	$789, -16(%rbp)
	movq	$321, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-40(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, 16(%rcx)
	movq	%rdx, 24(%rcx)
	movq	-40(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	callee_ret_struct2, .-callee_ret_struct2
	.section	.rodata
.LC5:
	.string	"callee_struct2:"
	.text
	.globl	callee_struct2
	.type	callee_struct2, @function
callee_struct2:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	callee_struct2, .-callee_struct2
	.globl	caller_struct2
	.type	caller_struct2, @function
caller_struct2:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	callee_ret_struct2
	movq	-48(%rbp), %rax
	addq	$100, %rax
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rax
	addq	$100, %rax
	movq	%rax, -40(%rbp)
	movq	-32(%rbp), %rax
	addq	$100, %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$100, %rax
	movq	%rax, -24(%rbp)
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	call	callee_struct2
	addq	$32, %rsp
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	caller_struct2, .-caller_struct2
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	caller_struct2
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
