#ifndef RVDISASM_INSTRUCTIONS_H
#define RVDISASM_INSTRUCTIONS_H

#include <stdint.h>

typedef enum inst_format_t {
    R_TYPE, I_TYPE, S_TYPE,
    B_TYPE, U_TYPE, J_TYPE
} inst_format_t;

typedef struct r_type_t {
    uint8_t rd;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct3;
    uint8_t funct7;
} r_type_t;

typedef struct i_type_t {
    uint8_t rd;
    uint8_t rs1;
    uint8_t funct3;
    int32_t imm;    //12 bit immediate or 24 with Sign Extension
} i_type_t;

typedef struct s_type_t {
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct3;
    int16_t imm;
} s_type_t;

typedef struct b_type_t {
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct3;
    int16_t imm;
} b_type_t;

typedef struct u_type_t {
    uint8_t rd;
    uint32_t imm;
} u_type_t;

typedef struct j_type_t {
    uint8_t rd;
    int32_t imm;
} j_type_t;

typedef struct instruction_t {
    inst_format_t format;
    uint8_t opcode;
    union {
        r_type_t r;
        i_type_t i;
        s_type_t s;
        b_type_t b;
        u_type_t u;
        j_type_t j;
    } fields_t;
} instruction_t;

const char* get_mnemonic(instruction_t inst);
#endif //RVDISASM_INSTRUCTIONS_H