# extra-corrected.s
#
# 2021-08-14
# by Xiannong Meng
# Example of procedure use, extra
# The non-leaf procedure double calls a do-nothing
# procedure extra to illustrate the changes in ra
# In this case, because we didn't save ra, the program
# won't be able to return to the correct place any more
# for CSCI 206
.text

    addi  a0, zero, 4
    jal   double         # a0 = result

    addi  a0, zero, 15
    jal   double
        
    li    a7, 10         # call for exit
    ecall
    
double:
    # a0 - parameter to be squared
    # a0 - the squared value to return

    addi  sp, sp, -4     # allocate 4 bytes for stack space
    sw    ra, 0(sp)      # store the value of ra in stack
    add   a0, a0, a0     # add a0 to itself, save in a0
    jal   extra          # extra is a do-nothing procedure
    lw    ra, 0(sp)      # retrieve the value of ra
    addi  sp, sp, 4      # pop the stack
    jr    ra

extra:
    jr  ra
