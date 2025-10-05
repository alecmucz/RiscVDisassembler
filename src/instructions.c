#include "../inc/instructions.h"

typedef struct r_type_def_t {
    uint8_t opcode;
    uint8_t funct3;
    uint8_t funct7;
    char*   mnemonic;
} r_type_op_t;

typedef struct i_type_def_t {
    uint8_t opcode;
    uint8_t funct3;
    char*   mnemonic;
} i_type_op_t;

typedef struct s_type_def_t {
    uint8_t opcode;
    uint8_t funct3;
    char*   mnemonic;
} s_type_op_t;

typedef struct b_type_def_t {
    uint8_t opcode;
    uint8_t funct3;
    char*   mnemonic;
} b_type_op_t;

typedef struct u_type_def_t {
    uint8_t opcode;
    char*   mnemonic;
} u_type_op_t;

typedef struct j_type_def_t {
    uint8_t opcode;
    char*   mnemonic;
} j_type_op_t;

r_type_op_t r_type_ops[] = {
    {0b0110011, 0b000, 0b0000000, "add"},
    {0b0110011, 0b000, 0b0100000, "sub"},
    {0b0110011, 0b001, 0b0000000, "sll"},
    {0b0110011, 0b010, 0b0000000, "slt"},
    {0b0110011, 0b011, 0b0000000, "sltu"},
    {0b0110011, 0b100, 0b0000000, "xor"},
    {0b0110011, 0b101, 0b0000000, "srl"},
    {0b0110011, 0b101, 0b0100000, "sra"},
    {0b0110011, 0b110, 0b0000000, "or"},
    {0b0110011, 0b111, 0b0000000, "and"}
};

i_type_op_t i_type_ops[] = {
    {0b1100111, 0b000, "jalr"},

    {0b0000011,0b000,"lb"},
    {0b0000011,0b001,"lh"},
    {0b0000011,0b010,"lw"},
    {0b0000011,0b100,"lbu"},
    {0b0000011,0b101,"lhu"},

    {0b0010011,0b000,"addi"},
    {0b0010011,0b010,"slti"},
    {0b0010011,0b011,"sltiu"},
    {0b0010011,0b100,"xori"},
    {0b0010011,0b110,"ori"},
    {0b0010011,0b111,"andi"},
    {0b0010011,0b001,"slli"},
    {0b0010011,0b101,"srli"},
    //{0b0010011,0b101,"srai"}  SRAI is handled as an SRLI edge case while decoding
};

s_type_op_t s_type_ops[] = {
    {0b0100011, 0b000,"sb"},
    {0b0100011, 0b001,"sh"},
    {0b0100011, 0b010,"sw"}
};

b_type_op_t b_type_ops[] = {
    {0b1100011, 0b000, "beq"},
    {0b1100011, 0b001, "bne"},
    {0b1100011, 0b100, "blt"},
    {0b1100011, 0b101, "bge"},
    {0b1100011, 0b110, "bltu"},
    {0b1100011, 0b111, "bgeu"}
};

u_type_op_t u_type_ops[] = {
    {0b0110111,"lui"},
    {0b0010111,"auipc"}
};

j_type_op_t j_type_ops[] = {
    {0b1101111,"jal"}
};