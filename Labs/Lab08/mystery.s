
# CSCI 206 Computer Organization & Programming
# Date: 2019-10-26
# Copyright (c) 2019 Bucknell University
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

#What mystery.s does
#mystery.s starts by loading t0 and s2 with zero values.
#it then moves into the loop label and stores the value of s2 and t0 added together into s2
#t0 is incremented by 1
#t3 register is given the value t0 + -10 (starts at -9)
#blez checks if t3 has a value less than zero (it does), then starts again at the loop label
#the loop adds 1+2+3+...+10 to s2, with a total sum of 55
#once t3 becomes 1 (less than zero) it continues
#t2 is given an address of x (89)
#the address t2 holds then stores our s2 value
# a0 (our return value) now holds s2
# a7 is given 93, the system call for Exit2
# ecall calls the exit!

	.data
	
unused:	.word 0xFEEDBEEF			
						
x:	.word 89				
						
	.text	
main:					# This tells the simulator
						# where start your program

	
	add		t0, zero, zero		
	add		s2, zero, zero		

loop:
	add		s2, s2, t0		
	addi	t0, t0, 1	
	addi	t3, t0, -10	
	blez	t3, loop		

	la		t2, x
	sw		s2, 0(t2)
	
	add		a0, zero, s2		# Move result into a0 for return code
	li		a7, 93			# Code (93) for system call Exit2
	ecall					# Exit!
	ebreak					# Break if something went wrong (should not get here!)

