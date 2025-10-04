#include <stdio.h>

#include "inc/instructions.h"
#include "inc/registers.h"

int main(void) {
    set_register_format(true);

    instruction_t inst = {
        .format = R_TYPE,
        .opcode = 0b0110011,
        .fields_t = {
            .r = {
                .rd = 28,
                .rs1 = 28,
                .rs2 = 5,
                .funct3 = 0b000,
                .funct7 = 0b0000000
            }
        }
    };
    printf("Opcode: 0x%02x\n", inst.opcode);
    printf("rd: %s\n", get_gpr_name(inst.fields_t.r.rd));
    printf("rs1: %s\n", get_gpr_name(inst.fields_t.r.rs1));
    printf("rs2: %s\n", get_gpr_name(inst.fields_t.r.rs2));
    return 0;
}