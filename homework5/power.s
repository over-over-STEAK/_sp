	.file	"power.s"
	.text
	.globl	power
	.type	power, @function
power:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp         # 建立堆疊空間

	movl	$1, -4(%ebp)      # int result = 1
	movl	$0, -8(%ebp)      # int i = 0

.Lloop:
	movl	-8(%ebp), %eax    # eax = i
	cmpl	12(%ebp), %eax    # 比較 i < exp
	jge	.Lend              # 若 i >= exp 跳到結束

	movl	-4(%ebp), %eax    # eax = result
	imull	8(%ebp), %eax     # eax *= base
	movl	%eax, -4(%ebp)    # result = eax

	addl	$1, -8(%ebp)      # i++
	jmp	.Lloop

.Lend:
	movl	-4(%ebp), %eax    # return result
	leave
	ret
