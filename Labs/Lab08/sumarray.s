# CSCI 206 Computer Organization & Programming
# Date: 2011-09-13
# Revised: 2019-10-31 for RISC-V
#
# Copyright (c) 2011 Bucknell University
#
# Permission is hereby granted, free of charge, to any individual or
# institution obtaining a copy of this software and associated
# documentation files (the "Software"), to use, copy, modify, and
# distribute without restriction, provided that this copyright and
# permission notice is maintained, intact, in all copies and
# supporting
# documentation.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#
# Student name: Gordon Rose
#
# This program calculates the sum of the values in array A and counts
# the number of values in the array.
#
# Similarly to a C-string, the array is terminated by sentinel value
# equal to zero.
#
# The sum is stored in $s0 and the count in $s1

	.data
A:	.word 5, 4, 3, 2, 4, 1, 0 # declare array int A[]={5,4,3,2,4,1,0};

    .globl main
	.text	
main:				# This symbols marks the first instruction of your program

#
# Add your code here
#
	
	add s2, zero, zero
	add s3, zero, zero
	
	add t1, zero, zero
	la t1, A
loop:
	lw t0, 0(t1)
	beqz t0, exit
	addi s3, s3, 1
	add s2, s2, t0
	
	addi t1, t1, 4
	j loop

exit:
	
	add a0, zero, s2
	add a1, zero, s3
	
	li	a7, 10		# system call for exit. 

	ecall			# Exit!
	ebreak
