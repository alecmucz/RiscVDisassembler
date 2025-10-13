# Risc-V Disassembler
A disassembler translating machine code to Risc-V 32bit instructions.

## Features
- Supports all RV32I instruction formats
- Outputs standard RISC-V assembly syntax.
- Defaults to a ABI register naming convention.

## Usage
```sh
./rvdisasm <binary_file(s)>

# Single file
./rvdisasm program.bin

# Multiple files
./rvdisasm prog1.bin prog2.bin prog3.bin
```
## Example
```sh
alecmucz@fedora:~/Dev/rvdisasm$ rvdisasm fib.bin 
00010537	lui a0, 0x10
00000597	auipc a1, 0x00
00100293	addi t0, zero, 1
00100313	addi t1, zero, 1
00800393	addi t2, zero, 8
00628e33	add t3, t0, t1
001e1e93	slli t4, t3, 1
001edf13	srli t5, t4, 1
401edf93	srai t6, t4, 1
0ffe4613	xori a2, t3, 255
0f0e6693	ori a3, t3, 240
03fe7713	andi a4, t3, 63
0062a7b3	slt a5, t0, t1
0062b833	sltu a6, t0, t1
405e08b3	sub a7, t3, t0
00fe1433	sll s0, t3, a5
00fe54b3	srl s1, t3, a5
00ce6933	or s2, t3, a2
00ee79b3	and s3, t3, a4
00de4a33	xor s4, t3, a3
40fedab3	sra s5, t4, a5
01c03b33	sltu s6, zero, t3
01c52023	sw t3, 0x00(a0)
01c51223	sh t3, 0x04(a0)
01c50323	sb t3, 0x06(a0)
00052b83	lw s7, 0(a0)
00451c03	lh s8, 4(a0)
00455c83	lhu s9, 4(a0)
00650d03	lb s10, 6(a0)
00654d83	lbu s11, 6(a0)
006002b3	add t0, zero, t1
01c00333	add t1, zero, t3
fff38393	addi t2, t2, -1
00038463	beq t2, zero, 0x08
f80396e3	bne t2, zero, 0xffffff8c
008000ef	jal ra, 0x08
00000067	jalr
001e1513	slli a0, t3, 1
01c50533	add a0, a0, t3
06452593	slti a1, a0, 100
0c853613	sltiu a2, a0, 200
0aa54693	xori a3, a0, 170
05556713	ori a4, a0, 85
0ff57793	andi a5, a0, 255
00008067	jalr

```

## Status
