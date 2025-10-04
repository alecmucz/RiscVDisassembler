#ifndef RVDISASM_REGISTERS_H
#define RVDISASM_REGISTERS_H

#define REGISTERS \
    X(x0, "zero") \
    X(x1, "ra")   \
    X(x2, "sp")   \
    X(x3, "gp")   \
    X(x4, "tp")   \
    X(x5, "t0")   \
    X(x6, "t1")   \
    X(x7, "t2")   \
    X(x8, "s0")   \
    X(x9, "s1")   \
    X(x10, "a0")  \
    X(x11, "a1")  \
    X(x12, "a2")  \
    X(x13, "a3")  \
    X(x14, "a4")  \
    X(x15, "a5")  \
    X(x16, "a6")  \
    X(x17, "a7")  \
    X(x18, "s2")  \
    X(x19, "s3")  \
    X(x20, "s4")  \
    X(x21, "s5")  \
    X(x22, "s6")  \
    X(x23, "s7")  \
    X(x24, "s8")  \
    X(x25, "s9")  \
    X(x26, "s10") \
    X(x27, "s11") \
    X(x28, "t3")  \
    X(x29, "t4")  \
    X(x30, "t5")  \
    X(x31, "t6")

// typedef enum {
//     #define X(arch, abi) arch,
//         REGISTERS
//     #undef X
// } gpr_t;

// ABI NAMES BY DEFAULT (TRUE)
void set_register_format(bool opt);
const char* get_gpr_name(int reg);


#endif //RVDISASM_REGISTERS_H