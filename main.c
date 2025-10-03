#include <stdio.h>
#include "inc/registers.h"

int main(void) {
    set_register_format(true);
    printf(get_gpr_name(30));
    return 0;
}