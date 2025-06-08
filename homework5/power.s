	.file	"power.cpp"
	.text
	.globl	power
	.type	power, @function
power:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -4(%ebp)
	movl	$0, -8(%ebp)
.L2:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	.L4
	movl	-4(%ebp), %eax
	imull	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	addl	$1, -8(%ebp)
	jmp	.L2
.L4:
	movl	-4(%ebp), %eax
	leave
	ret
	.size	power, .-power
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$32, %esp
	movl	$3, -4(%ebp)
	movl	$2, -8(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	power
	movl	%eax, -12(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
