ifndef X1
	X1 = 96
endif
ifndef X2
	X2 = 15
endif

all: gcd sim run

sim:
	iverilog -g2005-sv -Wall -DX1=$(X1) -DX2=$(X2) test_pipeline_cpu.sv */*.sv

gcd:
	pushd test_src; riscv32-elf-as stein_gcd.S
	riscv32-elf-objcopy --only-section=.text --output-target binary test_src/a.out gcd.bin
	#riscv32-elf-objcopy --only-section=.text --output-target binary test_src/a.out gcd_data.bin
run:
	./a.out