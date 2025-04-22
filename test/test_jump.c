#include "../src/instructions/jump.h"
#include "test_jump.h"
#include "test_utils.h"

#include <stdbool.h>

bool test_jmp() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;

    jmp(&mix, 100, false);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 1 failed, basic jump issue");
        return false;
    }
    print_info("1 - basic jump");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;

    jmp(&mix, 100, true);
    if (mix.stack_pointer != 100 || mix.J->value != 50) {
        print_ko(__func__, "Test 2 failed, basic jump with save issue");
        return false;
    }
    print_info("2 - basic jump w/ save");

    print_ok(__func__);
    return true;
}

bool test_jov() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.overflow = true;

    jov(&mix, 100);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 1a failed, basic jov issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.overflow = false;

    jov(&mix, 100);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 1b failed, basic jov issue");
        return false;
    }
    print_info("basic jov");

    print_ok(__func__);
    return true;
}

bool test_jnov() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.overflow = false;

    jnov(&mix, 100);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 1a failed, basic jnov issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.overflow = true;

    jnov(&mix, 100);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 1b failed, basic jnov issue");
        return false;
    }
    print_info("basic jnov");

    print_ok(__func__);
    return true;
}

bool test_jcc() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = L;

    jcc(&mix, 100, LESS);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 1a failed, basic LESS issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = G;

    jcc(&mix, 100, LESS);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 1b failed, basic LESS issue");
        return false;
    }
    print_info("1 - basic jcc LESS");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = E;

    jcc(&mix, 100, EQUAL);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 2a failed, basic EQUAL issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = L;

    jcc(&mix, 100, EQUAL);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 2b failed, basic EQUAL issue");
        return false;
    }
    print_info("2 - basic jcc EQUAL");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = G;

    jcc(&mix, 100, GREATER);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 3a failed, basic GREATER issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = L;

    jcc(&mix, 100, GREATER);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 3b failed, basic GREATER issue");
        return false;
    }
    print_info("4 - basic jcc GREATER");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = G;

    jcc(&mix, 100, GREATER_OR_EQUAL);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 4a failed, basic GREATER_OR_EQUAL issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = L;

    jcc(&mix, 100, GREATER_OR_EQUAL);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 4b failed, basic GREATER_OR_EQUAL issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = E;

    jcc(&mix, 100, GREATER_OR_EQUAL);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 4c failed, basic GREATER_OR_EQUAL issue");
        return false;
    }
    print_info("4 - basic jcc GREATER_OR_EQUAL");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = G;

    jcc(&mix, 100, UNEQUAL);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 5a failed, basic UNEQUAL issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = E;

    jcc(&mix, 100, UNEQUAL);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 5b failed, basic UNEQUAL issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = L;

    jcc(&mix, 100, UNEQUAL);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 5c failed, basic UNEQUAL issue");
        return false;
    }
    print_info("5 - basic jcc UNEQUAL");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = L;

    jcc(&mix, 100, LESS_OR_EQUAL);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6a failed, basic LESS_OR_EQUAL issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = G;

    jcc(&mix, 100, LESS_OR_EQUAL);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 6b failed, basic LESS_OR_EQUAL issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.comp = E;

    jcc(&mix, 100, LESS_OR_EQUAL);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6c failed, basic LESS_OR_EQUAL issue");
        return false;
    }
    print_info("6 - basic jcc LESS_OR_EQUAL");

    print_ok(__func__);
    return true;
}

bool test_jca() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 20;
    mix.A->sign = false;

    jca(&mix, 100, NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 1a failed, basic NEGATIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 20;
    mix.A->sign = true;

    jca(&mix, 100, NEGATIVE);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 1b failed, basic NEGATIVE issue");
        return false;
    }
    print_info("1 - basic jca NEGATIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 0;
    mix.A->sign = false;

    jca(&mix, 100, ZERO);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 2a failed, basic ZERO issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 1;
    mix.A->sign = false;

    jca(&mix, 100, ZERO);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 2b failed, basic ZERO issue");
        return false;
    }
    print_info("2 - basic jca ZERO");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 1;
    mix.A->sign = true;

    jca(&mix, 100, POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 3a failed, basic POSITIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 0;
    mix.A->sign = true;

    jca(&mix, 100, POSITIVE);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__,
                 "Test 3b failed, basic POSITIVE issue (should not proc on 0)");
        return false;
    }
    print_info("3 - basic jca POSITIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 1;
    mix.A->sign = true;

    jca(&mix, 100, NON_NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 4a failed, basic NON_NEGATIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 0;
    mix.A->sign = true;

    jca(&mix, 100, NON_NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__,
                 "Test 4b failed, basic NON_NEGATIVE issue (SHOULD proc on 0)");
        return false;
    }
    print_info("4 - basic jca NON_NEGATIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 1;
    mix.A->sign = true;

    jca(&mix, 100, NON_ZERO);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 5a failed, basic NON_ZERO issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 0;
    mix.A->sign = true;

    jca(&mix, 100, NON_ZERO);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 5b failed, basic NON_ZERO issue");
        return false;
    }
    print_info("5 - basic jca NON_ZERO");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 0;
    mix.A->sign = false;

    jca(&mix, 100, NON_POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6a failed, basic NON_POSITIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.A->value = 0;
    mix.A->sign = true;

    jca(&mix, 100, NON_POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6b failed, basic NON_POSITIVE issue (SHOULD "
                           "proc on 'positive 0'");
        return false;
    }
    print_info("6 - basic jca NON_POSITIVE");

    print_ok(__func__);
    return true;
}

bool test_jcx() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 20;
    mix.X->sign = false;

    jcx(&mix, 100, NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 1a failed, basic NEGATIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 20;
    mix.X->sign = true;

    jcx(&mix, 100, NEGATIVE);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 1b failed, basic NEGATIVE issue");
        return false;
    }
    print_info("1 - basic jcx NEGATIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 0;
    mix.X->sign = false;

    jcx(&mix, 100, ZERO);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 2a failed, basic ZERO issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 1;
    mix.X->sign = false;

    jcx(&mix, 100, ZERO);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 2b failed, basic ZERO issue");
        return false;
    }
    print_info("2 - basic jcx ZERO");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 1;
    mix.X->sign = true;

    jcx(&mix, 100, POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 3a failed, basic POSITIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 0;
    mix.X->sign = true;

    jcx(&mix, 100, POSITIVE);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__,
                 "Test 3b failed, basic POSITIVE issue (should not proc on 0)");
        return false;
    }
    print_info("3 - basic jcx POSITIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 1;
    mix.X->sign = true;

    jcx(&mix, 100, NON_NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 4a failed, basic NON_NEGATIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 0;
    mix.X->sign = true;

    jcx(&mix, 100, NON_NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__,
                 "Test 4b failed, basic NON_NEGATIVE issue (SHOULD proc on 0)");
        return false;
    }
    print_info("4 - basic jca NON_NEGATIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 1;
    mix.X->sign = true;

    jcx(&mix, 100, NON_ZERO);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 5a failed, basic NON_ZERO issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 0;
    mix.X->sign = true;

    jcx(&mix, 100, NON_ZERO);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 5b failed, basic NON_ZERO issue");
        return false;
    }
    print_info("5 - basic jcx NON_ZERO");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 0;
    mix.X->sign = false;

    jcx(&mix, 100, NON_POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6a failed, basic NON_POSITIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.X->value = 0;
    mix.X->sign = true;

    jcx(&mix, 100, NON_POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6b failed, basic NON_POSITIVE issue (SHOULD "
                           "proc on 'positive 0'");
        return false;
    }
    print_info("6 - basic jcx NON_POSITIVE");

    print_ok(__func__);
    return true;
}

bool test_jci() {
    print_start_test(__func__);

    s_Mix mix;
    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I1->value = 20;
    mix.I1->sign = false;

    jci(&mix, 100, 1, NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 1a failed, basic NEGATIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I1->value = 20;
    mix.I1->sign = true;

    jci(&mix, 100, 1, NEGATIVE);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 1b failed, basic NEGATIVE issue");
        return false;
    }
    print_info("1 - basic jci NEGATIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I2->value = 0;
    mix.I2->sign = false;

    jci(&mix, 100, 2, ZERO);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 2a failed, basic ZERO issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I2->value = 1;
    mix.I2->sign = false;

    jci(&mix, 100, 2, ZERO);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 2b failed, basic ZERO issue");
        return false;
    }
    print_info("2 - basic jci ZERO");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I3->value = 1;
    mix.I3->sign = true;

    jci(&mix, 100, 3, POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 3a failed, basic POSITIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I3->value = 0;
    mix.I3->sign = true;

    jci(&mix, 100, 3, POSITIVE);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__,
                 "Test 3b failed, basic POSITIVE issue (should not proc on 0)");
        return false;
    }
    print_info("3 - basic jci POSITIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I4->value = 1;
    mix.I4->sign = true;

    jci(&mix, 100, 4, NON_NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 4a failed, basic NON_NEGATIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I4->value = 1;
    mix.I4->sign = true;

    jci(&mix, 100, 4, NON_NEGATIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__,
                 "Test 4b failed, basic NON_NEGATIVE issue (SHOULD proc on 0)");
        return false;
    }
    print_info("4 - basic jci NON_NEGATIVE");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I5->value = 1;
    mix.I5->sign = true;

    jci(&mix, 100, 5, NON_ZERO);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 5a failed, basic NON_ZERO issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I5->value = 0;
    mix.I5->sign = true;

    jci(&mix, 100, 5, NON_ZERO);
    if (mix.stack_pointer != 200 || mix.J->value != 50) {
        print_ko(__func__, "Test 5b failed, basic NON_ZERO issue");
        return false;
    }
    print_info("5 - basic jci NON_ZERO");

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I6->value = 0;
    mix.I6->sign = false;

    jci(&mix, 100, 6, NON_POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6a failed, basic NON_POSITIVE issue");
        return false;
    }

    init_mix(&mix);

    mix.stack_pointer = 200;
    mix.J->value = 50;
    mix.I6->value = 0;
    mix.I6->sign = true;

    jci(&mix, 100, 6, NON_POSITIVE);
    if (mix.stack_pointer != 100 || mix.J->value != 201) {
        print_ko(__func__, "Test 6b failed, basic NON_POSITIVE issue (SHOULD "
                           "proc on 'positive 0'");
        return false;
    }
    print_info("6 - basic jci NON_POSITIVE");

    print_ok(__func__);
    return true;
}
