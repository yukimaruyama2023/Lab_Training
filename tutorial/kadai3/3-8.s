	.file	"3-8.c"
	.text
	.section	.rodata
.LC0:
	.string	"pre_addr:%lx\n"
.LC1:
	.string	"ret = %lx caller: %c\n"
	.text
	.globl	f
	.type	f, @function
f:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movl	$-559038737, -92(%rbp)
	leaq	-92(%rbp), %rax
	addq	$4, %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	f(%rip), %rax
	movq	%rax, -40(%rbp)
	leaq	g(%rip), %rax
	movq	%rax, -48(%rbp)
	leaq	h(%rip), %rax
	movq	%rax, -56(%rbp)
	leaq	main(%rip), %rax
	movq	%rax, -64(%rbp)
	movb	$102, -160(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -152(%rbp)
	movb	$103, -144(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -136(%rbp)
	movb	$104, -128(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -120(%rbp)
	movb	$109, -112(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -104(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L6:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L3
.L5:
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$152, %rax
	movq	(%rax), %rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$152, %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jbe	.L4
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$160, %rax
	movzbl	(%rax), %eax
	movb	%al, -73(%rbp)
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$160, %rax
	movzbl	(%rax), %eax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rbp, %rdx
	subq	$160, %rdx
	movb	%al, (%rdx)
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	leaq	-160(%rax), %rdx
	movzbl	-73(%rbp), %eax
	movb	%al, (%rdx)
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$152, %rax
	movq	(%rax), %rax
	movq	%rax, -88(%rbp)
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$152, %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rbp, %rdx
	subq	$152, %rdx
	movq	%rax, (%rdx)
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	leaq	-152(%rax), %rdx
	movq	-88(%rbp), %rax
	movq	%rax, (%rdx)
.L4:
	addl	$1, -8(%rbp)
.L3:
	cmpl	$3, -8(%rbp)
	jle	.L5
	addl	$1, -4(%rbp)
.L2:
	cmpl	$3, -4(%rbp)
	jle	.L6
	movq	8(%rbp), %rax
	movq	%rax, -72(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L7
.L9:
	movl	-12(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$152, %rax
	movq	(%rax), %rax
	cmpq	%rax, -72(%rbp)
	jbe	.L8
	movl	-12(%rbp), %eax
	addl	$1, %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$152, %rax
	movq	(%rax), %rax
	cmpq	%rax, -72(%rbp)
	jnb	.L8
	movl	-12(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$160, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edx
	movq	-72(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L8:
	addl	$1, -12(%rbp)
.L7:
	cmpl	$2, -12(%rbp)
	jle	.L9
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	f, .-f
	.globl	g
	.type	g, @function
g:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L11
	movl	$0, %eax
	call	f
	jmp	.L13
.L11:
	movl	$0, %eax
	call	f
.L13:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	g, .-g
	.globl	h
	.type	h, @function
h:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1431655766, %rax, %rax
	shrq	$32, %rax
	movl	%edx, %ecx
	sarl	$31, %ecx
	subl	%ecx, %eax
	movl	%eax, %ecx
	addl	%ecx, %ecx
	addl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	testl	%eax, %eax
	jne	.L15
	movl	$0, %eax
	call	f
	jmp	.L18
.L15:
	movl	-4(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1431655766, %rax, %rax
	shrq	$32, %rax
	movl	%edx, %ecx
	sarl	$31, %ecx
	subl	%ecx, %eax
	movl	%eax, %ecx
	addl	%ecx, %ecx
	addl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	cmpl	$1, %eax
	jne	.L17
	movl	$0, %eax
	call	f
	jmp	.L18
.L17:
	movl	$0, %eax
	call	f
.L18:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	h, .-h
	.section	.rodata
.LC2:
	.string	"calling g(%10d)...\t"
.LC3:
	.string	"calling h(%10d)...\t"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$0, -4(%rbp)
	jmp	.L20
.L23:
	call	rand@PLT
	movl	%eax, -8(%rbp)
	call	rand@PLT
	movl	%eax, -12(%rbp)
	movl	-8(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L21
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	g
	jmp	.L22
.L21:
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	h
.L22:
	addl	$1, -4(%rbp)
.L20:
	cmpl	$9, -4(%rbp)
	jle	.L23
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
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
