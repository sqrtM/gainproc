#include "test_comp.h"
#include "../src/instructions/comp.h"
#include "test_utils.h"

#include <stdbool.h>

bool test_cmpa() {
    print_start_test("test_cmpa");

    s_Mix mix;
    init_mix(&mix);

    mix.A->value = 100;

    mix.memory[0].value = 500;
    mix.memory[0].sign = true;
    cmpa(&mix, 0, 5);
    if (mix.comp != L) {
        print_ko("test_cmpa", "Test 1 failed, basic compare issue L");
        return false;
    }
    print_info("1 - basic comp L");

    init_mix(&mix);

    mix.A->value = 100;

    mix.memory[1].value = 500;
    mix.memory[1].sign = false;
    cmpa(&mix, 1, 5);
    if (mix.comp != G) {
        print_ko("test_cmpa", "Test 2 failed, basic compare issue G");
        return false;
    }
    print_info("2 - basic comp G");

    init_mix(&mix);

    mix.A->value = 0;

    mix.memory[2].value = 0;
    mix.memory[2].sign = false;
    cmpa(&mix, 2, 5);
    if (mix.comp != E) {
        print_ko("test_cmpa", "Test 3 failed, basic compare issue E");
        return false;
    }
    print_info("3 - basic comp E");

    init_mix(&mix);

    mix.A->value = 0b000000111111000001111111000000;
    mix.A->sign = false;

    mix.memory[3].value = 0b111111111111000000111111000000;
    mix.memory[3].sign = true;
    cmpa(&mix, 3, 28);
    if (mix.comp != G) {
        print_ko("test_cmpa", "Test 4 failed, field issue");
        return false;
    }
    print_info("4 - field");

    print_ok("test_cmpa");
    return true;
}

bool test_cmpx() {
    print_start_test("test_cmpx");

    s_Mix mix;
    init_mix(&mix);

    mix.X->value = 100;

    mix.memory[0].value = 500;
    mix.memory[0].sign = true;
    cmpx(&mix, 0, 5);
    if (mix.comp != L) {
        print_ko("test_cmpx", "Test 1 failed, basic compare issue L");
        return false;
    }
    print_info("1 - basic comp L");

    init_mix(&mix);

    mix.X->value = 100;

    mix.memory[1].value = 500;
    mix.memory[1].sign = false;
    cmpx(&mix, 1, 5);
    if (mix.comp != G) {
        print_ko("test_cmpx", "Test 2 failed, basic compare issue G");
        return false;
    }
    print_info("2 - basic comp G");

    init_mix(&mix);

    mix.X->value = 0;

    mix.memory[2].value = 0;
    mix.memory[2].sign = false;
    cmpa(&mix, 2, 5);
    if (mix.comp != E) {
        print_ko("test_cmpx", "Test 3 failed, basic compare issue E");
        return false;
    }
    print_info("3 - basic comp E");

    init_mix(&mix);

    mix.X->value = 0b000000111111000001111111000000;

    mix.memory[3].value = 0b111111111111000000111111000000;
    mix.memory[3].sign = false;
    cmpx(&mix, 3, 28);
    if (mix.comp != G) {
        print_ko("test_cmpx", "Test 4 failed, field issue");
        return false;
    }
    print_info("4 - field");

    print_ok("test_cmpx");
    return true;
}

bool test_cmpi() {
    print_start_test("test_cmpi");

    s_Mix mix;
    init_mix(&mix);

    mix.I3->value = 100;

    mix.memory[0].value = 500;
    mix.memory[0].sign = true;
    cmpi(&mix, 0, 3, 5);
    if (mix.comp != L) {
        print_ko("test_cmpi", "Test 1 failed, basic compare issue L");
        return false;
    }
    print_info("1 - basic comp L");

    init_mix(&mix);

    mix.I4->value = 100;

    mix.memory[1].value = 500;
    mix.memory[1].sign = false;
    cmpi(&mix, 1, 4, 5);
    if (mix.comp != G) {
        print_ko("test_cmpi", "Test 2 failed, basic compare issue G");
        return false;
    }
    print_info("2 - basic comp G");

    init_mix(&mix);

    mix.I5->value = 0;

    mix.memory[2].value = 0;
    mix.memory[2].sign = false;
    cmpi(&mix, 2, 5, 5);
    if (mix.comp != E) {
        print_ko("test_cmpi", "Test 3 failed, basic compare issue E");
        return false;
    }
    print_info("3 - basic comp E");

    init_mix(&mix);

    mix.I1->value = 0b011111000000;

    mix.memory[3].value = 0b111111111111000000000011000000;
    mix.memory[3].sign = false;
    cmpi(&mix, 3, 1, 28);
    if (mix.comp != G) {
        print_ko("test_cmpi", "Test 4 failed, field issue");
        return false;
    }
    print_info("4 - field");

    print_ok("test_cmpi");
    return true;
}
