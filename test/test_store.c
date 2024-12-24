#include "test_store.h"
#include "../src/instructions/store.h"
#include "test_utils.h"
#include <stdbool.h>

bool test_sta() {
    print_start_test("test_sta");

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
    if (mix.memory[1].value != 0b101010010101010101111111000000 ||
        mix.memory[1].sign != true) {
        print_ko("test_sta", "Test 2 failed, store with shift issue");
        return false;
    }
    print_info("2 - store with shift");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[2].value = 0b000001000010000011000100000101;
    mix.memory[2].sign = false;
    sta(&mix, 2, 5);
    if (mix.memory[2].value != 0b000110000111001000001001000000 ||
        mix.memory[2].sign != true) {
        print_ko("test_sta", "Test 3 failed, book test 1 issue");
        return false;
    }
    print_info("3 - book test 1");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[3].value = 0b000001000010000011000100000101;
    mix.memory[3].sign = false;
    sta(&mix, 3, 13);
    if (mix.memory[3].value != 0b000110000111001000001001000000 ||
        mix.memory[3].sign != false) {
        print_ko("test_sta", "Test 4 failed, book test 2 issue");
        return false;
    }
    print_info("4 - book test 2");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[4].value = 0b000001000010000011000100000101;
    mix.memory[4].sign = false;
    sta(&mix, 4, 45);
    if (mix.memory[4].value != 0b000001000010000011000100000000 ||
        mix.memory[4].sign != false) {
        print_ko("test_sta", "Test 5 failed, book test 3 issue");
        return false;
    }
    print_info("5 - book test 3");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[5].value = 0b000001000010000011000100000101;
    mix.memory[5].sign = false;
    sta(&mix, 5, 18);
    if (mix.memory[5].value != 0b000001000000000011000100000101 ||
        mix.memory[5].sign != false) {
        print_ko("test_sta", "Test 6 failed, book test 4 issue");
        return false;
    }
    print_info("6 - book test 4");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[6].value = 0b000001000010000011000100000101;
    mix.memory[6].sign = false;
    sta(&mix, 6, 19);
    if (mix.memory[6].value != 0b000001001001000000000100000101 ||
        mix.memory[6].sign != false) {
        print_ko("test_sta", "Test 6 failed, book test 5 issue");
        return false;
    }
    print_info("7 - book test 5");

    mix.A->value = 0b000110000111001000001001000000;
    mix.A->sign = true;
    mix.memory[7].value = 0b000001000010000011000100000101;
    mix.memory[7].sign = false;
    sta(&mix, 7, 1);
    if (mix.memory[7].value != 0b000000000010000011000100000101 ||
        mix.memory[7].sign != true) {
        print_ko("test_sta", "Test 8 failed, book test 6 issue");
        return false;
    }
    print_info("8 - book test 6");

    print_ok("test_sta");
    return true;
}

bool test_stx() {
    print_start_test("test_stx");

    s_Mix mix;
    init_mix(&mix);

    mix.X->value = 0b001100111111000000111111000000;
    mix.X->sign = true;
    mix.memory[0].value = 0b001000111111000100111111111101;
    mix.memory[0].sign = true;
    stx(&mix, 0, 5);
    if (mix.memory[0].value != 0b001100111111000000111111000000) {
        print_ko("test_stx", "Test 1 failed, basic store issue");
        return false;
    }
    print_info("1 - basic store");

    mix.X->value = 0b111111010101010101010101111111;
    mix.X->sign = false;
    mix.memory[1].value = 0b101010111111000000111111000000;
    mix.memory[1].sign = true;
    stx(&mix, 1, 20);
    if (mix.memory[1].value != 0b101010010101010101111111000000 ||
        mix.memory[1].sign != true) {
        print_ko("test_stx", "Test 2 failed, store with shift issue");
        return false;
    }
    print_info("2 - store with shift");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[2].value = 0b000001000010000011000100000101;
    mix.memory[2].sign = false;
    stx(&mix, 2, 5);
    if (mix.memory[2].value != 0b000110000111001000001001000000 ||
        mix.memory[2].sign != true) {
        print_ko("test_stx", "Test 3 failed, book test 1 issue");
        return false;
    }
    print_info("3 - book test 1");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[3].value = 0b000001000010000011000100000101;
    mix.memory[3].sign = false;
    stx(&mix, 3, 13);
    if (mix.memory[3].value != 0b000110000111001000001001000000 ||
        mix.memory[3].sign != false) {
        print_ko("test_stx", "Test 4 failed, book test 2 issue");
        return false;
    }
    print_info("4 - book test 2");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[4].value = 0b000001000010000011000100000101;
    mix.memory[4].sign = false;
    stx(&mix, 4, 45);
    if (mix.memory[4].value != 0b000001000010000011000100000000 ||
        mix.memory[4].sign != false) {
        print_ko("test_stx", "Test 5 failed, book test 3 issue");
        return false;
    }
    print_info("5 - book test 3");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[5].value = 0b000001000010000011000100000101;
    mix.memory[5].sign = false;
    stx(&mix, 5, 18);
    if (mix.memory[5].value != 0b000001000000000011000100000101 ||
        mix.memory[5].sign != false) {
        print_ko("test_stx", "Test 6 failed, book test 4 issue");
        return false;
    }
    print_info("6 - book test 4");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[6].value = 0b000001000010000011000100000101;
    mix.memory[6].sign = false;
    stx(&mix, 6, 19);
    if (mix.memory[6].value != 0b000001001001000000000100000101 ||
        mix.memory[6].sign != false) {
        print_ko("test_stx", "Test 6 failed, book test 5 issue");
        return false;
    }
    print_info("7 - book test 5");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[7].value = 0b000001000010000011000100000101;
    mix.memory[7].sign = false;
    stx(&mix, 7, 1);
    if (mix.memory[7].value != 0b000000000010000011000100000101 ||
        mix.memory[7].sign != true) {
        print_ko("test_stx", "Test 8 failed, book test 6 issue");
        return false;
    }
    print_info("8 - book test 6");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[8].value = 0b000001000010000011000100000101;
    mix.memory[8].sign = false;
    stx(&mix, 8, 1);
    if (mix.memory[8].value != 0b000000000010000011000100000101 ||
        mix.memory[8].sign != true) {
        print_ko("test_stx", "Test 9 failed, 0:1 issue");
        return false;
    }
    print_info("9 - 0:1");

    mix.X->value = 0b000110000111001000001001000000;
    mix.X->sign = true;
    mix.memory[9].value = 0b000001000010000011000100000101;
    mix.memory[9].sign = false;
    stx(&mix, 9, 2);
    if (mix.memory[9].value != 0b001001000000000011000100000101 ||
        mix.memory[9].sign != true) {
        print_ko("test_stx", "Test 10 failed, 0:2 issue");
        return false;
    }
    print_info("10 - 0:2");

    print_ok("test_stx");
    return true;
}

bool test_sti() {
    print_start_test("test_sti");

    s_Mix mix;
    init_mix(&mix);

    mix.I1->value = 0b111111000000;
    mix.I1->sign = true;
    mix.memory[0].value = 0b001000111111000100111111111101;
    mix.memory[0].sign = true;
    sti(&mix, 0, 1, 5);
    if (mix.memory[0].value != 0b0000000000000000000111111000000) {
        print_ko("test_sti", "Test 1 failed, basic store issue");
        return false;
    }
    print_info("1 - basic store");

    mix.I2->value = 0b111111000000;
    mix.I2->sign = true;
    mix.memory[1].value = 0b111111111111111111111111111111;
    mix.memory[1].sign = true;
    sti(&mix, 1, 2, 20);
    if (mix.memory[1].value != 0b111111000000111111000000111111) {
        print_ko("test_sti", "Test 2 failed, store with shift issue");
        return false;
    }
    print_info("2 - store with shift");

    mix.I3->value = 0b100000100000;
    mix.I3->sign = true;
    mix.memory[2].value = 0b111111000000111111000000111111;
    mix.memory[2].sign = false;
    sti(&mix, 2, 3, 3);
    if (mix.memory[2].value != 0b000000100000100000000000111111 ||
        mix.memory[2].sign != true) {
        print_ko("test_sti", "Test 3 failed, store with sign");
        return false;
    }
    print_info("3 - store with sign");

    mix.I4->value = 0b100000111111;
    mix.I4->sign = true;
    mix.memory[4].value = 0b111111000000111111000000111111;
    mix.memory[4].sign = false;
    sti(&mix, 4, 4, 36);
    if (mix.memory[4].value != 0b111111000000111111111111111111 ||
        mix.memory[4].sign != false) {
        print_ko("test_sti", "Test 4 failed, store one");
        return false;
    }
    print_info("4 - store one");

    print_ok("test_sti");
    return true;
}

bool test_stj() {
    print_start_test("test_stj");

    s_Mix mix;
    init_mix(&mix);

    mix.J->value = 0b111111000000;
    mix.J->sign = true;
    mix.memory[0].value = 0b001000111111000100111111111101;
    mix.memory[0].sign = true;
    stj(&mix, 0, 5);
    if (mix.memory[0].value != 0b0000000000000000000111111000000) {
        print_ko("test_stj", "Test 1 failed, basic store issue");
        return false;
    }
    print_info("1 - basic store");

    mix.J->value = 0b111111000000;
    mix.J->sign = true;
    mix.memory[1].value = 0b111111111111111111111111111111;
    mix.memory[1].sign = true;
    stj(&mix, 1, 20);
    if (mix.memory[1].value != 0b111111000000111111000000111111) {
        print_ko("test_stj", "Test 2 failed, store with shift issue");
        return false;
    }
    print_info("2 - store with shift");

    mix.J->value = 0b100000100000;
    mix.J->sign = true;
    mix.memory[2].value = 0b111111000000111111000000111111;
    mix.memory[2].sign = false;
    stj(&mix, 2, 3);
    if (mix.memory[2].value != 0b000000100000100000000000111111 ||
        mix.memory[2].sign != true) {
        print_ko("test_stj", "Test 3 failed, store with sign");
        return false;
    }
    print_info("3 - store with sign");

    mix.J->value = 0b100000111111;
    mix.J->sign = true;
    mix.memory[4].value = 0b111111000000111111000000111111;
    mix.memory[4].sign = false;
    stj(&mix, 4, 36);
    if (mix.memory[4].value != 0b111111000000111111111111111111 ||
        mix.memory[4].sign != false) {
        print_ko("test_stj", "Test 4 failed, store one");
        return false;
    }
    print_info("4 - store one");

    print_ok("test_stj");
    return true;
}

bool test_stz() {
    print_start_test("test_stz");

    s_Mix mix;
    init_mix(&mix);

    mix.memory[0].value = 0b001000111111000100111111111101;
    mix.memory[0].sign = true;
    stz(&mix, 0, 5);
    if (mix.memory[0].value != 0) {
        print_ko("test_stz", "Test 1 failed, basic store issue");
        return false;
    }
    print_info("1 - basic store");

    mix.memory[2].value = 0b111111111111111111111111111111;
    mix.memory[2].sign = false;
    stz(&mix, 2, 3);
    if (mix.memory[2].value != 0b111111111111 || mix.memory[2].sign != true) {
        print_ko("test_stz", "Test 2 failed, store issue");
        return false;
    }
    print_info("2 - left store");

    mix.memory[3].value = 0b111111111111111111111111111111;
    mix.memory[3].sign = false;
    stz(&mix, 3, 36);
    if (mix.memory[3].value != 0b111111111111111111000000111111 ||
        mix.memory[3].sign != false) {
        print_ko("test_stz", "Test 3 failed, single store issue");
        return false;
    }
    print_info("3 - single store");

    print_ok("test_stz");
    return true;
}
