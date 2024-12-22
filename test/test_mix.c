#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/mix.h"
#include "test_mix.h"
#include "test_utils.h"

bool test_init_mix() {
    s_Mix mix;
    init_mix(&mix);

    if (mix.A->value != 0 || mix.X->value != 0 || mix.I1->value != 0  || mix.I2->value != 0
        || mix.I3->value != 0 || mix.I4->value != 0 || mix.I5->value != 0 || mix.I6->value != 0) {
        print_ko("test_init_mix", "registers not initialized to 0");
        return false;
    } else {
        print_ok("test_init_mix");
        return true;
    }
}

bool test_shift_behavior() {
    s_Word* t = (s_Word*)malloc(sizeof(s_Word));
    t->value = 0b1000000000000000000000000;

    unsigned int expected_values[] = {
        0b1000000000000000000000000,
        0b0100000000000000000000000,
        0b0010000000000000000000000,
        0b0001000000000000000000000,
        0b0000100000000000000000000,
        0b0000010000000000000000000,
        0b0000001000000000000000000,
        0b0000000100000000000000000,
        0b0000000010000000000000000,
        0b0000000001000000000000000,
        0b0000000000100000000000000,
        0b0000000000010000000000000,
        0b0000000000001000000000000,
        0b0000000000000100000000000,
        0b0000000000000010000000000,
        0b0000000000000001000000000,
        0b0000000000000000100000000,
        0b0000000000000000010000000,
        0b0000000000000000001000000,
        0b0000000000000000000100000,
        0b0000000000000000000010000,
        0b0000000000000000000001000,
        0b0000000000000000000000100,
        0b0000000000000000000000010,
        0b0000000000000000000000001,
        0b0000000000000000000000000
    };

    for (int i = 0; i <= 25; i++) {
        if (t->value != expected_values[i]) {
            char formatted_string[100];
            snprintf(formatted_string, sizeof(formatted_string),
                "expected %d, got %d",
                expected_values[i],
                t->value);
            print_ko("test_shift_behavior (right)", formatted_string);
            return false;
        }
        t->value = t->value >> 1;
    }

    t->value = 1;

    for (int i = 24; i >= 0; i--) {
        if (t->value != expected_values[i]) {
            char formatted_string[100];
            snprintf(formatted_string, sizeof(formatted_string),
                "expected %d, got %d",
                expected_values[i],
                t->value);
            print_ko("test_shift_behavior (right)", formatted_string);
            return false;
        }
        t->value = t->value << 1;
    }

    free(t);
    print_ok("test_shift_behavior");
    return true;
}
