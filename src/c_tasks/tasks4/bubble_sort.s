	.file	"bubble_sort.c"
	.text
	.globl	bubble_sort
	.type	bubble_sort, @function
bubble_sort:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L2
.L6:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.L3
.L5:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L4
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rsi
	movq	-24(%rbp), %rax
	addq	%rsi, %rax
	xorl	%ecx, %edx
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rsi
	movq	-24(%rbp), %rax
	addq	%rsi, %rax
	xorl	%ecx, %edx
	movl	%edx, (%rax)
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rsi
	movq	-24(%rbp), %rax
	addq	%rsi, %rax
	xorl	%ecx, %edx
	movl	%edx, (%rax)
.L4:
	addl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L5
	addl	$1, -8(%rbp)
.L2:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L6
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	bubble_sort, .-bubble_sort
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
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
