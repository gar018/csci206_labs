.text
.globl check_primes

check_primes:
    add s2, zero, a2 #index 0 of *r

    add s3, zero, a0
    add s4, zero, a1
    
forAtoB:
    sub t0, s4, s3  
    blt t0,zero,complete

    addi sp, sp, -8
    sd ra, 0(sp)
    
    add a0, zero, s3
    jal is_prime

    ld ra, 0(sp)
    addi sp, sp, 8

    sw a0, 0(s2)
    addi s2, s2, 4
    
    addi s3,s3,1

    j forAtoB
    
complete:
    jr ra

    

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
