.text
.globl add_second

add_second:

lw t0, 0(a0)
lw t1, 4(a0)
lw t2, 8(a0)

addi t0, t0, 1
slti t3, t0, 60

blt zero, t3, skip #if second overflow move to minutes
add t0, zero, zero
addi t1,t1,1
slti t3, t1, 60

blt zero,t3, skip #if minute overflow move to hrs
add t1,zero, zero
addi t2,t2,1
slti t3, t2, 24

blt zero, t3, skip #if hr overflow just set hr to 0
add t2,zero,zero

skip:
sw t0, 0(a0)
sw t1, 4(a0)
sw t2, 8(a0)

jr ra
