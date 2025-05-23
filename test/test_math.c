#include "../src/instructions/math.h"
#include "test_math.h"
#include "test_utils.h"

#include <stdbool.h>

bool test_add() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.memory[0].value = 1;
    mix.memory[0].sign = true;
    mix.A->value = 1;
    mix.A->sign = true;
    add(&mix, 0, 5);
    if (mix.A->value != 2) {
        print_ko(__func__, "Test 1 failed, 1 + 1 :(");
        return false;
    }
    print_info("1 - basic add");

    mix.memory[1].value = 0b111111000000111111000000111111;
    mix.memory[1].sign = true;
    mix.A->value = 0b000000111111000000111111000000;
    mix.A->sign = true;
    add(&mix, 1, 29);
    if (mix.A->value != 0b000000111111111111111111111111) {
        print_ko(__func__, "Test 2 failed, add with field");
        return false;
    }
    print_info("2 - add with field");

    mix.memory[2].value = 3;
    mix.memory[2].sign = false;
    mix.A->value = 2;
    mix.A->sign = true;
    add(&mix, 2, 5);
    if (mix.A->value != 1 || mix.A->sign != false) {
        print_ko(__func__, "Test 3 failed, different signs basic");
        return false;
    }
    print_info("3 - different signs basic");

    mix.memory[3].value = 0b111111111111111111111111111111;
    mix.memory[3].sign = true;
    mix.A->value = 6;
    mix.A->sign = true;
    add(&mix, 3, 5);
    if (mix.A->value != 5 || mix.A->sign != true || mix.overflow != true) {
        print_ko(__func__, "Test 4 failed, overflow");
        return false;
    }
    print_info("4 - overflow");
    return true;
}

bool test_sub() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.memory[0].value = 1;
    mix.memory[0].sign = true;
    mix.A->value = 2;
    mix.A->sign = true;
    sub(&mix, 0, 5);
    if (mix.A->value != 1) {
        print_ko(__func__, "Test 1 failed, 2 - 1 :(");
        return false;
    }
    print_info("1 - basic sub");

    mix.memory[1].value = 0b111111111111111111000000111111;
    mix.memory[1].sign = true;
    mix.A->value = 0b111111111111111111111111111111;
    mix.A->sign = true;
    sub(&mix, 1, 29);
    if (mix.A->value != 0b111111111111000000111111000000) {
        print_ko(__func__, "Test 2 failed, sub with field");
        return false;
    }
    print_info("2 - sub with field");

    mix.memory[2].value = 2000;
    mix.memory[2].sign = false;
    mix.A->value = 1234;
    mix.A->sign = false;
    sub(&mix, 2, 5);
    if (mix.A->value != 766 || mix.A->sign != true) {
        print_ko(__func__, "Test 3 failed, sign flip");
        return false;
    }
    print_info("3 - sign flip");

    mix.memory[3].value = 6;
    mix.memory[3].sign = true;
    mix.A->value = 0b111111111111111111111111111111;
    mix.A->sign = false;
    sub(&mix, 3, 5);
    if (mix.A->value != 5 || mix.A->sign != false || mix.overflow != true) {
        print_ko(__func__, "Test 4 failed, overflow");
        return false;
    }
    print_info("4 - overflow");
    return true;
}

bool test_mul() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.memory[0].value = 2;
    mix.memory[0].sign = true;
    mix.A->value = 2;
    mix.A->sign = true;
    mul(&mix, 0, 5);
    if (mix.A->value != 0 || mix.X->value != 4) {
        print_ko(__func__, "Test 1 failed, 2 * 2 :(");
        return false;
    }
    print_info("1 - basic mul");

    mix.memory[1].value = 0b111111000000000010001000000000;
    mix.memory[1].sign = true;
    mix.A->value = 2;
    mix.A->sign = true;
    mul(&mix, 1, 28);
    if (mix.A->value != 0 || mix.X->value != 272) {
        print_ko(__func__, "Test 2 failed, mul with field");
        return false;
    }
    print_info("2 - mul with field");

    mix.memory[2].value = 4;
    mix.memory[2].sign = true;
    mix.A->value = 4;
    mix.A->sign = false;
    mul(&mix, 2, 5);
    if (mix.A->value != 0 || mix.X->value != 16 || mix.A->sign != false ||
        mix.X->sign != false) {
        print_ko(__func__, "Test 3 failed, sign flip");
        return false;
    }
    print_info("3 - sign flip");

    mix.memory[3].value = WORD_MAX;
    mix.memory[3].sign = true;
    mix.A->value = 7;
    mix.A->sign = true;
    mul(&mix, 3, 5);
    if (mix.A->value != 0b110 ||
        mix.X->value != 0b111111111111111111111111111001 ||
        mix.A->sign != true || mix.X->sign != true) {
        print_ko(__func__, "Test 4 failed, across registers");
        return false;
    }
    print_info("4 - across registers");

    return true;
}

bool test_div() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.memory[0].value = 2;
    mix.memory[0].sign = true;
    mix.A->value = 0;
    mix.A->sign = true;
    mix.X->value = 4;
    mix.X->sign = false;
    div(&mix, 0, 5);
    if (mix.A->value != 2 || mix.X->value != 0) {
        print_ko(__func__, "Test 1 failed, 4 / 2 :(");
        return false;
    }
    print_info("1 - basic div");

    mix.memory[1].value = 0b111111000000000010001000000000;
    mix.memory[1].sign = true;
    mix.A->value = 0b111;
    mix.A->sign = true;
    mix.X->value = 0b00111010011110100001010001001;
    mix.X->sign = false;
    div(&mix, 1, 28);
    if (mix.A->value != 28534788 || mix.X->value != 105) {
        print_ko(__func__,
                 "Test 2 failed, big div with field (3880731273 / 136)");
        return false;
    }
    print_info("2 - div with field");

    mix.memory[2].value = 0b111111000000000010001000111111;
    mix.memory[2].sign = true;
    mix.A->value = 0b10110111111;
    mix.A->sign = true;
    mix.X->value = 0b01000100011110111011010001001;
    mix.X->sign = false;
    div(&mix, 2, 29);
    if (mix.A->value != 90097037 || mix.X->value != 7894) {
        print_ko(
            "test_div",
            "Test 3 failed, big div with field again (789880731273 / 8767)");
        return false;
    }
    print_info("3 - div with field again");

    mix.memory[3].value = 4;
    mix.memory[3].sign = true;
    mix.A->value = 0;
    mix.A->sign = false;
    mix.X->value = 16;
    mix.X->sign = true;
    div(&mix, 3, 5);
    if (mix.A->value != 4 || mix.X->value != 0 || mix.A->sign != false ||
        mix.X->sign != false) {
        print_ko(__func__, "Test 4 failed, sign flip");
        return false;
    }
    print_info("4 - sign flip");

    return true;
}
