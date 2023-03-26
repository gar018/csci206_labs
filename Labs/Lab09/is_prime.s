.text
.globl is_prime

is_prime:

    add t0, zero, a0
    li t1, 2
    li t2, 0
while:
    bge t1, t0, prime
    rem t2, t0, t1
    beqz t2, return
    addi t1, t1, 1
    j while

prime:
    li t2, 1

return:
    
    add a0, zero, t2
    jr ra

