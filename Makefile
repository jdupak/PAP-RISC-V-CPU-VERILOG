all: gcd sim run

sim:
	iverilog test_dmem_cpu.v */*.v gcd.bin

gcd:
	pushd test_src; riscv32-elf-as stein_gcd.S
	riscv32-elf-objcopy --only-section=.text --output-target binary test_src/a.out gcd.bin
run:
	./a.out