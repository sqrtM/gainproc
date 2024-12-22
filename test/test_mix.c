#include "test_mix.h"
#include "../src/mix.h"
#include "test_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool test_init_mix() {
    print_start_test("test_init_mix");

    s_Mix mix;
    init_mix(&mix);

    if (mix.A->value != 0 || mix.X->value != 0 || mix.I1->value != 0 ||
        mix.I2->value != 0 || mix.I3->value != 0 || mix.I4->value != 0 ||
        mix.I5->value != 0 || mix.I6->value != 0) {
        print_ko("test_init_mix", "registers not initialized to 0");
        return false;
    } else {
        print_ok("test_init_mix");
        return true;
    }
}

bool test_shift_behavior() {
    print_start_test("test_shift_behavior");

    s_Word *t = (s_Word *)malloc(sizeof(s_Word));
    t->value = 0b1000000000000000000000000;

    unsigned int expected_values[] = {
        0b1000000000000000000000000, 0b0100000000000000000000000,
        0b0010000000000000000000000, 0b0001000000000000000000000,
        0b0000100000000000000000000, 0b0000010000000000000000000,
        0b0000001000000000000000000, 0b0000000100000000000000000,
        0b0000000010000000000000000, 0b0000000001000000000000000,
        0b0000000000100000000000000, 0b0000000000010000000000000,
        0b0000000000001000000000000, 0b0000000000000100000000000,
        0b0000000000000010000000000, 0b0000000000000001000000000,
        0b0000000000000000100000000, 0b0000000000000000010000000,
        0b0000000000000000001000000, 0b0000000000000000000100000,
        0b0000000000000000000010000, 0b0000000000000000000001000,
        0b0000000000000000000000100, 0b0000000000000000000000010,
        0b0000000000000000000000001, 0b0000000000000000000000000};

    for (int i = 0; i <= 25; i++) {
        if (t->value != expected_values[i]) {
            char formatted_string[100];
            snprintf(formatted_string, sizeof(formatted_string),
                     "expected %d, got %d", expected_values[i], t->value);
            print_ko("test_shift_behavior (right)", formatted_string);
            return false;
        }
        t->value = t->value >> 1;
    }
    print_info("1 - forward");

    t->value = 1;
    for (int i = 24; i >= 0; i--) {
        if (t->value != expected_values[i]) {
            char formatted_string[100];
            snprintf(formatted_string, sizeof(formatted_string),
                     "expected %d, got %d", expected_values[i], t->value);
            print_ko("test_shift_behavior (right)", formatted_string);
            return false;
        }
        t->value = t->value << 1;
    }
    print_info("2 - backward");

    free(t);
    print_ok("test_shift_behavior");
    return true;
}

bool test_generate_mask() {
    print_start_test("test_generate_mask");

    struct {
        uint8_t l;
        uint8_t r;
        unsigned int expected;
    } test_cases[] = {
        {0, 0, 0},
        {1, 1, 0b111111000000000000000000000000},
        {1, 2, 0b111111111111000000000000000000},
        {1, 3, 0b111111111111111111000000000000},
        {1, 4, 0b111111111111111111111111000000},
        {1, 5, 0b111111111111111111111111111111},
        {2, 4, 0b000000111111111111111111000000},
        {3, 3, 0b000000000000111111000000000000},
        {1, 0, 0},
        {4, 0, 0},
        {39, 11, 0},
    };

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        unsigned int result = generate_mask(test_cases[i].l, test_cases[i].r);
        if (result != test_cases[i].expected) {
            char formatted_string[100];
            snprintf(formatted_string, sizeof(formatted_string),
                     "expected 0x%08X, got 0x%08X", test_cases[i].expected,
                     result);
            print_ko("test_generate_mask", formatted_string);
            return false;
        }
    }

    print_ok("test_generate_mask");
    return true;
}
