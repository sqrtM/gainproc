#include <stdio.h>
#include "../src/mix.h"
#include "test_mix.h"

void test_init_mix() {
    s_Mix mix;
    init_mix(&mix);

    if (mix.A->value != 0 || mix.X->value != 0 || mix.I1->value != 0  || mix.I2->value != 0
        || mix.I3->value != 0 || mix.I4->value != 0 || mix.I5->value != 0 || mix.I6->value != 0) {
        printf("test_init_registers failed: Registers not initialized to 0\n");
    } else {
        printf("test_init_registers passed\n");
    }
}
