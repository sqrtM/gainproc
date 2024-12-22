#include "test_load.h"
#include "../src/instructions/load.h"
#include "test_utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool test_lda() {
    s_Mix mix;
    init_mix(&mix);

    mix.memory[0].value = 0b000000111111000000111111000000;
    mix.memory[0].sign = true;
    lda(&mix, 0, 5, false);
    if (mix.A->value != 0b111111000000111111000000) {
        print_ko("test_lda", "Test 1 failed, basic load issue");
        return false;
    }

    mix.A->value = 0;
    mix.A->sign = true;
    mix.memory[1].value = 0b000000111111000000111111000000;
    mix.memory[1].sign = true;
    lda(&mix, 1, 3, false);
    if (mix.A->value != 0b111111000000) {
        print_ko("test_lda", "Test 2 failed, shifted load problem");
        return false;
    }

    mix.A->value = 0;
    mix.A->sign = true;
    mix.memory[2].value = 0b000000111111000000111111000000;
    mix.memory[2].sign = false;
    lda(&mix, 2, 5, false);
    if (mix.A->value != 0b111111000000111111000000 || mix.A->sign != false) {
        print_ko("test_lda", "Test 3 failed, sign assignment incorrect");
        return false;
    }

    mix.A->value = 0;
    mix.A->sign = true;
    mix.memory[3].value = 0b000000111111000000101011000000;
    mix.memory[3].sign = true;
    lda(&mix, 3, 36, false);
    if (mix.A->value != 0b101011) {
        print_ko("test_lda", "Test 4 failed, single segment issue");
        return false;
    }

    mix.A->value = 0b101010101010;
    mix.A->sign = true;
    mix.memory[4].value = 0b000000111111000000101011000000;
    mix.memory[4].sign = false;
    lda(&mix, 4, 0, false);
    if (mix.A->value != 0 || mix.A->sign != false) {
        print_ko("test_lda", "Test 5 failed, take sign only issue");
        return false;
    }

    print_ok("test_lda");
    return true;
}
