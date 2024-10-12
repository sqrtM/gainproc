#include <stdio.h>
#include "../src/sm83.h"

void test_init_registers() {
    Sm83_Registers regs;
    init_registers(&regs);

    if (regs.AF != 0 || regs.BC != 0 || regs.DE != 0 ||
        regs.HL != 0 || regs.SP != 0 || regs.PC != 0) {
        printf("test_init_registers failed: Registers not initialized to 0\n");
    } else {
        printf("test_init_registers passed\n");
    }
}

void test_set_get_register() {
    Sm83_Registers regs;
    init_registers(&regs);

    set_register(&regs, AF, 0x1234);
    if (get_register(&regs, AF) != 0x1234) {
        printf("test_set_get_register failed: AF not set correctly\n");
    } else {
        printf("test_set_get_register AF passed\n");
    }

    set_register(&regs, BC, 0x5678);
    if (get_register(&regs, BC) != 0x5678) {
        printf("test_set_get_register failed: BC not set correctly\n");
    } else {
        printf("test_set_get_register BC passed\n");
    }
}
