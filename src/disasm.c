#include "../inc/disasm.h"

#include <time.h>

instruction_t decode_inst(uint32_t raw_inst) {
    instruction_t inst = (instruction_t){0};
    const uint8_t opcode = raw_inst & 0x7F;
    inst.opcode = opcode;

    switch (opcode) {

        case 0x33: {                // R-Type
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
        case 0x03:                  // I-Type
        case 0x13:
        case 0x67: {
            const uint8_t rd        = (raw_inst >> 7)  & 0x1F;
            const uint8_t funct3    = (raw_inst >> 12) & 0x07;
            const uint8_t rs1       = (raw_inst >> 15) & 0x1F;

            uint32_t imm            = (raw_inst >> 20) & 0xFFF;
            if (imm & 0x800) { imm |= 0xFFFFF000; }

            inst.format             = I_TYPE;
            inst.fields_t.i.rd      = rd;
            inst.fields_t.i.funct3  = funct3;
            inst.fields_t.i.rs1     = rs1;
            inst.fields_t.i.imm     = imm;
            return inst;
        }

        case 0x23: {                // S-Type
            const uint8_t imm_4_0   = (raw_inst >> 7) & 0x1F;
            const uint8_t funct3    = (raw_inst >> 12) & 0x07;
            const uint8_t rs1       = (raw_inst >> 15) & 0x1F;
            const uint8_t rs2       = (raw_inst >> 20) & 0x1F;
            const uint8_t imm_11_5  = (raw_inst >> 25) & 0x7F;

            uint32_t imm            = imm_4_0 | (imm_11_5 << 5);
            if (imm & 0x800) { imm |= 0xFFFFF000; }

            inst.format             = S_TYPE;
            inst.fields_t.s.rs1     = rs1;
            inst.fields_t.s.rs2     = rs2;
            inst.fields_t.s.funct3  = funct3;
            inst.fields_t.s.imm     = imm;
            return inst;
        }
        case 0x63: {                // B-Type
            const uint8_t imm_11    = (raw_inst >> 7) & 0x01;
            const uint8_t imm_4_1   = (raw_inst >> 8) & 0x0F;
            const uint8_t funct3    = (raw_inst >> 12) & 0x07;
            const uint8_t rs1       = (raw_inst >> 15) & 0x1F;
            const uint8_t rs2       = (raw_inst >> 20) & 0x1F;
            const uint8_t imm_10_5  = (raw_inst >> 25) & 0x3F;
            const uint8_t imm_12    = (raw_inst >> 31) & 0x01;

            uint16_t imm            = (imm_11 << 11) | (imm_4_1 << 1) |
                                      (imm_12 << 12) | (imm_10_5 << 5);
            if (imm & 0x1000){ imm |= 0xFFFFE000; }

            inst.format             = B_TYPE;
            inst.fields_t.b.rs1     = rs1;
            inst.fields_t.b.rs2     = rs2;
            inst.fields_t.b.funct3  = funct3;
            inst.fields_t.b.imm     = imm;
            return inst;
        }
        case 0x17:                  // U-Type
        case 0x37: {
            const uint8_t rd        = (raw_inst >> 7)  & 0x1F;
            const uint32_t imm      = (raw_inst >> 12) & 0xFFFFF;

            inst.format             = U_TYPE;
            inst.fields_t.u.rd      = rd;
            inst.fields_t.u.imm     = imm;
            return inst;
        }
        case 0x6F: {                 // J-Type
            const uint8_t rd         = (raw_inst >> 7)  & 0x1F;
            const uint32_t imm_19_12 = (raw_inst >> 12) & 0xFF;
            const uint32_t imm_11    = (raw_inst >> 20) & 0x01;
            const uint32_t imm_10_1  = (raw_inst >> 21) & 0x3FF;
            const uint32_t imm_20    = (raw_inst >> 31) & 0x01;

            uint32_t imm             = (imm_20 << 20) | (imm_10_1 << 1) |
                                       (imm_11 << 11) | (imm_19_12 << 12);
            if (imm & 0x10000) { imm |= 0xFFE00000; }

            inst.format              = J_TYPE;
            inst.fields_t.j.rd       = rd;
            inst.fields_t.j.imm      = imm;
            return inst;
        }
        case 0x73: {
            uint32_t imm            = (raw_inst >> 20) & 0xFFF;
            if (imm & 0x800) { imm |= 0xFFFFF000; }

            inst.format = I_TYPE;
            inst.fields_t.i.rd      = 0x00;
            inst.fields_t.i.funct3  = 0x00;
            inst.fields_t.i.rs1     = 0x00;
            inst.fields_t.i.imm     = imm;
            return inst;
        }

    }
    return (instruction_t){0};
}
