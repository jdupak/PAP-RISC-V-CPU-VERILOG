.globl start
.globl _start

start:
_start:

# https://en.wikipedia.org/wiki/Binary_GCD_algorithm

gcd:
nop
nop
lw	 	x1, 0x0(x0)
lw	 	x2, 0x4(x0)
nop
beqz 	x1, ret_v    # if x1 == 0 return x2
nop
nop
beqz 	x2, ret_u    # if x2 == 0 return x1
nop
nop
beq     x1, x2, ret_u
nop
nop
move  	x4, x0   # x4 = 0
loop1:
nop
nop
or      x3, x1, x2       # x3 = x1 | x2
nop
nop
andi    x3, x3, 0x1   # x3 = x3 & 1
nop
nop
bnez 	x3, loop1_end  # if x3 != 0 break
nop
nop
addi 	x4, x4, 1 # x4 += 1
srli    x1, x1, 1         # x1 >>= 1
srli    x2, x2, 1         # x2 >>= 1
j       loop1
nop
nop
loop1_end:loop2:
nop
nop
andi    x3, x1, 0x1     # x3 = x1 & 1
nop
nop
bnez 	x3, loop2_end    # if x3 != 0 break
nop
nop
srli    x1, x1, 1         # x1 >>= 0
j       loop2
nop
nop
loop2_end:loop3:loop31:
nop
nop
    andi    x3, x2, 0x1     # x3 = x2 & 1
    nop
    nop
    bnez 	x3, loop31_end # if x3 != 0 break
    nop
    nop
    srli    x2, x2, 1         # x2 >>= 1
    j       loop31
    nop
    nop
    loop31_end:
    nop
    nop
    blt 	x2, x1, no_swap
    nop
    nop
    move    x3, x1
    move    x1, x2
    nop
    nop
    move  	x2, x3
    nop
    nop
    no_swap:
    nop
    nop
    sub	 	x2, x2, x1
    nop
    nop
    bnez    x2, loop3
    nop
    nop
loop3_end:
nop
nop
sll     x1, x1, x4
ret_u:
nop
nop
sw	 	x1, 0x8(x0)
nop
nop
ebreak
j gcd			# restart
ret_v:
nop
nop
sw	 	x2, 0x8(x0)
nop
nop
ebreak
j gcd			# restart
nop
nop
.end start
