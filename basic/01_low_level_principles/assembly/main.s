	.file	"main.c"
	.text
	.globl	gdata1
	.data
	.align 4
	.type	gdata1, @object
	.size	gdata1, 4
gdata1:
	.long	10
	.globl	gdata2
	.bss
	.align 4
	.type	gdata2, @object
	.size	gdata2, 4
gdata2:
	.zero	4
	.comm	gdata3,4,4
	.data
	.align 4
	.type	gdata4, @object
	.size	gdata4, 4
gdata4:
	.long	11
	.local	gdata5
	.comm	gdata5,4,4
	.local	gdata6
	.comm	gdata6,4,4
	.globl	array
	.align 8
	.type	array, @object
	.size	array, 12
array:
	.string	"hello world"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$12, -8(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.local	g.1927
	.comm	g.1927,4,4
	.local	f.1926
	.comm	f.1926,4,4
	.data
	.align 4
	.type	e.1925, @object
	.size	e.1925, 4
e.1925:
	.long	13
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
