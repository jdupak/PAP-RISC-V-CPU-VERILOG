.globl start
.globl _start

start:
_start:

# https://en.wikipedia.org/wiki/Binary_GCD_algorithm

gcd:
lw	 	x1, 0x0(x0)
lw	 	x2, 0x4(x0)
beqz 	x1, ret_v    # if x1 == 0 return x2
beqz 	x2, ret_u    # if x2 == x1 return x1
move  	x4, x0   # x4 = 0
loop1:
or      x3, x1, x2       # x3 = x1 | x2
andi    x3, x3, 0x1   # x3 = x3 & 1
bnez 	x3, loop1_end  # if x3 != 0 break
addi 	x4, x4, 1 # x4 += 1
srli    x1, x1, 1         # x1 >>= 1
srli    x2, x2, 1         # x2 >>= 1
j       loop1
loop1_end:loop2:
andi    x3, x1, 0x1     # x3 = x1 & 1
bnez 	x3, loop2_end    # if x3 != 0 break
srli    x1, x1, 1         # x1 >>= 0
j       loop2
loop2_end:loop3:loop31:
    andi    x3, x2, 0x1     # x3 = x2 & 1
    bnez 	x3, loop31_end # if x3 != 0 break
    srli    x2, x2, 1         # x2 >>= 1
    j       loop31
    loop31_end:
    blt 	x2, x1, no_swap
    move    x3, x1
    move    x1, x2
    move  	x2, x3
    no_swap:
    sub	 	x2, x2, x1
    bnez    x2, loop3
loop3_end:
sll     x1, x1, x4
ret_u:
sw	 	x1, 0x8(x0)
ebreak
j gcd			# restart
ret_v:
sw	 	x2, 0x8(x0)
ebreak
j gcd			# restart
nop
.end start
