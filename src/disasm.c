#include "../inc/disasm.h"

#include <stddef.h>


instruction_t decode_inst(uint32_t raw_inst) {
    instruction_t inst = (instruction_t){0};
    const uint8_t opcode = raw_inst & 0x7F;

    switch (opcode) {

        case 0x33: {    // R-Type
            const uint8_t rd        = (raw_inst >> 7)  & 0x1F;
            const uint8_t funct3    = (raw_inst >> 12) & 0x07;
            const uint8_t rs1       = (raw_inst >> 15) & 0x1F;
            const uint8_t rs2       = (raw_inst >> 20) & 0x1F;
            const uint8_t funct7    = (raw_inst >> 25) & 0x7F;

            inst.format             = R_TYPE;
            inst.fields_t.r.rd      = rd;
            inst.fields_t.r.funct3  = funct3;
            inst.fields_t.r.rs1     = rs1;
            inst.fields_t.r.rs2     = rs2;
            inst.fields_t.r.funct7  = funct7;

            return inst;
        }
        case 0x03:      // I-Type
        case 0x13:
        case 0x67: {
            const uint8_t rd        = (raw_inst >> 7)  & 0x1F;
            const uint8_t funct3    = (raw_inst >> 12) & 0x07;
            const uint8_t rs1       = (raw_inst >> 15) & 0x1F;
            const uint32_t imm       = (raw_inst >> 20) & 0xFFF;

            inst.format = I_TYPE;
            inst.fields_t.i.rd      = rd;
            inst.fields_t.i.funct3  = funct3;
            inst.fields_t.i.rs1     = rs1;
            inst.fields_t.i.imm     = imm;
            return inst;
        }

        case 0x23: {    // S-Type

            return inst;
        }
        case 0x63: {    // B-Type

            return inst;
        }
        case 0x17:      // U-Type
        case 0x37: {
            const uint8_t rd        = (raw_inst >> 7)  & 0x1F;
            const uint32_t imm      = (raw_inst >> 12) & 0xFFFFF;

            inst.format = U_TYPE;
            inst.fields_t.u.rd      = rd;
            inst.fields_t.u.imm     = imm;
            return inst;
        }
        case 0x6F: {    // J-Type

            return inst;
        }
    }
    return (instruction_t){0};
}