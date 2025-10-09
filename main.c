#include <stdio.h>
#include <stdlib.h>

#include "inc/disasm.h"

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc;i++) {
        char* file = argv[i];
        FILE *fp = fopen(file,"rb");

        if (fp == NULL) {
            printf("rv32i_disasm: cannot open file");
            continue;
        }
        uint32_t inst;
        while (fread(&inst, sizeof(uint32_t), 1, fp) == 1) {
            printf("%08x\t",inst);
            print_inst(decode_inst(inst));
        }
        fclose(fp);
    }
    return 0;
}