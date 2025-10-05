#include <stdio.h>

#include "inc/disasm.h"
#include "inc/instructions.h"
#include "inc/registers.h"

int main(void) {
    set_register_format(false);

     instruction_t inst = decode_inst(0x003100B3);

    printf("Opcode: 0x%02x\n", inst.opcode);
    printf("Format: \n", inst.format);
    printf("rd: %s\n", get_gpr_name(inst.fields_t.r.rd));
    printf("rs1: %s\n", get_gpr_name(inst.fields_t.r.rs1));
    printf("rs2: %s\n", get_gpr_name(inst.fields_t.r.rs2));
    return 0;
}