	.file	"c_mystery.c"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"%p\n%p\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-48
	sd	ra,40(sp)
	sd	s0,32(sp)
	addi	s0,sp,48
	li	a5,-17973248
	addi	a5,a5,-273
	sw	a5,-28(s0)
	sw	zero,-20(s0)
	sw	zero,-24(s0)
	sw	zero,-32(s0)
.L2:
	lw	a5,-24(s0)
	mv	a4,a5
	lw	a5,-20(s0)
	addw	a5,a4,a5
	sw	a5,-24(s0)
	lw	a5,-20(s0)
	addiw	a5,a5,1
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	addiw	a5,a5,-10
	sw	a5,-32(s0)
	lw	a5,-32(s0)
	sext.w	a5,a5
	ble	a5,zero,.L2
	lw	a5,-24(s0)
	sw	a5,-36(s0)
	lw	a4,-36(s0)
	lw	a5,-28(s0)
	mv	a2,a4
	mv	a1,a5
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	printf
	lw	a5,-36(s0)
	mv	a0,a5
	ld	ra,40(sp)
	ld	s0,32(sp)
	addi	sp,sp,48
	jr	ra
	.size	main, .-main
	.ident	"GCC: (g5964b5cd727) 11.1.0"
