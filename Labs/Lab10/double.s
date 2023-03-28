# CSCI 206 by Xianong Meng
# 2022-01-27
# Example of procedure use, double, non-leaf procedure
# Also used for a part of the lab exercise, exploring the stack.
# This should be used in combination with double_rev.c
# 2023-03-15
.text

    .globl double_value

double_value:   
    # a0 - parameter to be doubled
    # a0 - the squared value to return

    addi sp, sp, -8     # allocate 4 bytes for stack space
    sd  ra, 0(sp)       # store the value of ra in stack
    add a0, a0, a0      # add a0 to itself, save in a0
    jal extra           # extra is a do-nothing procedure
    ld  ra, 0(sp)       # retriee the value of ra
    addi sp, sp, 8      # pop the stack
#    addi ra, ra, 48    # skip to 'How are you?'
    jr  ra

extra:
    jr ra
