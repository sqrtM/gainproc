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

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[2].value = 0b000001000010000011000100000101;
    mix.memory[2].sign = false;
    sta(&mix, 2, 5);
    if (mix.memory[2].value != 0b000110000111001000001001000000 || mix.memory[2].sign != true) {
        print_ko("test_sta", "Test 3 failed, book test 1 issue");
        return false;
    }
    print_info("3 - book test 1");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[3].value = 0b000001000010000011000100000101;
    mix.memory[3].sign = false;
    sta(&mix, 3, 13);
    if (mix.memory[3].value != 0b000110000111001000001001000000 || mix.memory[3].sign != false) {
        print_ko("test_sta", "Test 4 failed, book test 2 issue");
        return false;
    }
    print_info("4 - book test 2");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[4].value = 0b000001000010000011000100000101;
    mix.memory[4].sign = false;
    sta(&mix, 4, 45);
    if (mix.memory[4].value != 0b000001000010000011000100000000 || mix.memory[4].sign != false) {
        print_ko("test_sta", "Test 5 failed, book test 3 issue");
        return false;
    }
    print_info("5 - book test 3");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[5].value = 0b000001000010000011000100000101;
    mix.memory[5].sign = false;
    sta(&mix, 5, 18);
    if (mix.memory[5].value != 0b000001000000000011000100000101 || mix.memory[5].sign != false) {
        print_ko("test_sta", "Test 6 failed, book test 4 issue");
        return false;
    }
    print_info("6 - book test 4");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[6].value = 0b000001000010000011000100000101;
    mix.memory[6].sign = false;
    sta(&mix, 6, 19);
    if (mix.memory[6].value != 0b000001001001000000000100000101 || mix.memory[6].sign != false) {
        print_ko("test_sta", "Test 6 failed, book test 5 issue");
        return false;
    }
    print_info("7 - book test 5");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[7].value = 0b000001000010000011000100000101;
    mix.memory[7].sign = false;
    sta(&mix, 7, 1);
    if (mix.memory[7].value != 0b000000000010000011000100000101 || mix.memory[7].sign != true) {
        print_ko("test_sta", "Test 8 failed, book test 6 issue");
        return false;
    }
    print_info("8 - book test 6");

    print_ok("test_sta");
    return true;
}
