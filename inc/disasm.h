#ifndef RVDISASM_DISASM_H
#define RVDISASM_DISASM_H

#include "instructions.h"

instruction_t decode_inst(uint32_t raw_inst);

#endif //RVDISASM_DISASM_H#include "inc/instructions.h"
