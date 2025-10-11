	.file	"bubble_sort.c"
	.text
	.p2align 4
	.globl	bubble_sort
	.type	bubble_sort, @function
bubble_sort:
.LFB23:
	.cfi_startproc
	endbr64
	testl	%esi, %esi
	jle	.L1
	movq	%rdi, %r8
	movl	%esi, %r10d
	movl	$1, %r9d
	cmpl	$1, %esi
	je	.L1
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%r9, %rax
	.p2align 4,,10
	.p2align 3
.L5:
	movl	(%r8), %edx
	movl	(%rdi,%rax,4), %ecx
	cmpl	%ecx, %edx
	jle	.L4
	movl	%ecx, (%r8)
	movl	%edx, (%rdi,%rax,4)
.L4:
	addq	$1, %rax
	cmpl	%eax, %esi
	jg	.L5
	addq	$1, %r9
	addq	$4, %r8
	cmpq	%r10, %r9
	jne	.L6
.L1:
	ret
	.cfi_endproc
.LFE23:
	.size	bubble_sort, .-bubble_sort
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
.LC1:
	.string	"%d "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	leaq	.LC0(%rip), %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	xorl	%ebx, %ebx
	subq	$824, %rsp
	.cfi_def_cfa_offset 880
	movq	%fs:40, %rax
	movq	%rax, 808(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %r12
	movq	%r12, %rbp
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L16:
	movl	0(%rbp), %eax
	movq	stdin(%rip), %rdi
	addq	$4, %rbp
	movl	%eax, 400(%rsp,%rbx,4)
	addq	$1, %rbx
	call	getc@PLT
	cmpb	$10, %al
	je	.L28
.L13:
	movl	%ebx, %r14d
	cmpq	$100, %rbx
	je	.L15
	xorl	%eax, %eax
	movq	%rbp, %rsi
	movq	%r13, %rdi
	call	__isoc99_scanf@PLT
	cmpl	$1, %eax
	je	.L16
.L14:
	movl	%ebx, %esi
	movq	%r12, %rdi
	call	bubble_sort
	testl	%ebx, %ebx
	je	.L12
.L20:
	movslq	%ebx, %r13
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	salq	$2, %r13
	leaq	400(%rsp), %r15
	leaq	.LC1(%rip), %r14
	.p2align 4,,10
	.p2align 3
.L19:
	movl	(%r12,%rbp), %edx
	movq	%r14, %rsi
	movl	$2, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	(%r15,%rbp), %eax
	cmpl	%eax, (%r12,%rbp)
	je	.L18
	addl	$1, %ebx
.L18:
	addq	$4, %rbp
	cmpq	%r13, %rbp
	jne	.L19
.L12:
	movq	808(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L29
	addq	$824, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L28:
	.cfi_restore_state
	leal	1(%r14), %ebx
	jmp	.L14
.L15:
	movl	$100, %esi
	movq	%r12, %rdi
	movl	$100, %ebx
	call	bubble_sort
	jmp	.L20
.L29:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
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
