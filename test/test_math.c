#include "test_math.h"
#include "../src/instructions/math.h"
#include "test_utils.h"

#include <stdbool.h>
#include <stdio.h>

bool test_add() {
    print_start_test("test_add");

    s_Mix mix;
    init_mix(&mix);

    mix.memory[0].value = 1;
    mix.memory[0].sign = true;
    mix.A->value = 1;
    mix.A->sign = true;
    add(&mix, 0, 5);
    if (mix.A->value != 2) {
        print_ko("test_add", "Test 1 failed, 1 + 1 :(");
        return false;
    }
    print_info("1 - basic load");

    mix.memory[1].value = 0b111111000000111111000000111111;
    mix.memory[1].sign = true;
    mix.A->value = 0b000000111111000000111111000000;
    mix.A->sign = true;
    add(&mix, 1, 29);
    if (mix.A->value != 0b000000111111111111111111111111) {
        print_ko("test_add", "Test 2 failed, add with field");
        return false;
    }
    print_info("2 - add with field");

    mix.memory[2].value = 3;
    mix.memory[2].sign = false;
    mix.A->value = 2;
    mix.A->sign = true;
    add(&mix, 2, 5);
    if (mix.A->value != 1 || mix.A->sign != false) {
        printf("%u\n", mix.A->value);
        print_ko("test_add", "Test 3 failed, different signs basic");
        return false;
    }
    print_info("3 - different signs basic");

    mix.memory[3].value = 0b111111111111111111111111111111;
    mix.memory[3].sign = true;
    mix.A->value = 6;
    mix.A->sign = true;
    add(&mix, 3, 5);
    if (mix.A->value != 5 || mix.A->sign != true || mix.overflow != true) {
        print_ko("test_add", "Test 4 failed, overflow");
        return false;
    }
    print_info("4 - overflow");
    return true;
}
