#include "../inc/registers.h"

static bool register_format = true;

static const char* abi_names[32] = {
#define X(arch, abi) abi,
    REGISTERS
#undef X
};

static const char* arch_names[32] = {
    #define X(arch, abi) #arch,
        REGISTERS
    #undef X
};

void set_register_format(const bool opt) {
    register_format = opt;
}

const char* get_gpr_name(const int reg) {
    if (reg < 0 || reg > 31)
        return nullptr;
    if (register_format)
        return abi_names[reg];
    return arch_names[reg];
}