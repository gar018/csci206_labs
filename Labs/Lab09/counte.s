.data
    e: .word 'e'
.text
.globl counte

counte:
    #load byte val for 'e'
    la t1, e
    lb t0, 0(t1)
    #load counter return value
    li t2, 0
    #while not a null terminator, check for e's
while:
    lb t3, 0(a0)
    beq t3, zero, return
    bne t3, t0, skip
    addi t2, t2, 1
skip:
    addi a0, a0, 1
    j while

return:
    add a0, zero, t2
    jr ra

