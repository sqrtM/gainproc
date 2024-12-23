#include "test_store.h"
#include "../src/instructions/store.h"
#include "test_utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool test_sta() {
    print_start_test("test_lda");

    s_Mix mix;
    init_mix(&mix);

    mix.A->value = 0b001100111111000000111111000000;
    mix.A->sign = true;
    mix.memory[0].value = 0b001000111111000100111111111101;
    mix.memory[0].sign = true;
    sta(&mix, 0, 5);
    if (mix.memory[0].value != 0b001100111111000000111111000000) {
        print_ko("test_sta", "Test 1 failed, basic store issue");
        return false;
    }
    print_info("1 - basic store");

    mix.A->value = 0b111111010101010101010101111111;
    mix.A->sign = false;
    mix.memory[1].value = 0b101010111111000000111111000000;
    mix.memory[1].sign = true;
    sta(&mix, 1, 20);
    if (mix.memory[1].value != 0b101010010101010101111111000000 || mix.memory[1].sign != true) {
        print_ko("test_sta", "Test 2 failed, store with shift issue");
        return false;
    }
    print_info("2 - store with shift");

    print_ok("test_sta");
    return true;
}
