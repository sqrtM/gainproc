#include "../src/instructions/enter.h"
#include "test_enter.h"
#include "test_utils.h"

#include <stdbool.h>

bool test_enter() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    s_Small_Register ma;
    s_Small_Register mx;
    s_Small_Register mi;

    ma.value = 10;
    ma.sign = true;

    mx.value = 20;
    mx.sign = false;

    mi.value = 30;
    mi.sign = true;

    enta(&mix, ma, false);
    entx(&mix, mx, false);
    enti(&mix, mi, 3, false);
    if (mix.A->value != 10 || mix.X->value != 20 || mix.X->sign != false ||
        mix.I3->value != 30) {
        print_ko(__func__, "Test 1 failed, basic enter issue");
        return false;
    }
    print_info("1 - basic enter");

    ma.value = 10;
    ma.sign = true;

    mx.value = 20;
    mx.sign = false;

    mi.value = 30;
    mi.sign = true;

    enta(&mix, ma, true);
    entx(&mix, mx, true);
    enti(&mix, mi, 5, true);
    if (mix.A->value != 10 || mix.A->sign != false || mix.X->value != 20 ||
        mix.X->sign != false || mix.I5->value != 30) {
        print_ko(__func__, "Test 2 failed, enter with negative");
        return false;
    }
    print_info("2 - enter with negative");

    print_ok(__func__);
    return true;
}
