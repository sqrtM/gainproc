#include "test_incdec.h"
#include "../src/instructions/incdec.h"
#include "test_utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool test_inc() {
    print_start_test("test_inc");

    s_Mix mix;
    init_mix(&mix);

    s_Small_Register ma;
    s_Small_Register mx;
    s_Small_Register mi;

    ma.value = 1;
    ma.sign = true;

    mx.value = 1;
    mx.sign = false;

    mi.value = 1;
    mi.sign = true;

    mix.A->value = 10;
    mix.X->value = 11;
    mix.I3->value = 12;

    inca(&mix, ma);
    incx(&mix, mx);
    inci(&mix, mi, 3);
    if (mix.A->value != 11 || mix.X->value != 10 || mix.X->sign != true ||
        mix.I3->value != 13) {
        print_ko("test_inc", "Test 1 failed, basic inc issue");
        return false;
    }
    print_info("1 - basic inc");

    ma.value = 6;
    ma.sign = true;

    mix.A->value = WORD_MAX;

    inca(&mix, ma);
    if (mix.A->value != 5 || mix.overflow != true) {
        print_ko("test_inc", "Test 2 failed, overflow issue");
        return false;
    }
    print_info("2 - overflow");

    init_mix(&mix);

    mi.value = 6;
    mi.sign = true;

    mix.I5->value = HALF_WORD_MAX;

    inci(&mix, mi, 5);
    if (mix.I5->value != 5 || mix.overflow != false) {
        print_ko("test_inc", "Test 3 failed, I undefined overflow issue");
        return false;
    }
    print_info("3 - I undefined overflow");
    return true;
}
