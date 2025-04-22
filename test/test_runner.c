#include <string.h>

#include "test_comp.h"
#include "test_enter.h"
#include "test_incdec.h"
#include "test_jump.h"
#include "test_load.h"
#include "test_math.h"
#include "test_mix.h"
#include "test_store.h"
#include "test_utils.h"

int main(int argc, char *argv[]) {
    bool verbose = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = true;
        }
    }

    print_init_test_message();
    bool all_tests_ok = true;

    all_tests_ok &= test_init_mix();
    all_tests_ok &= test_shift_behavior(verbose);
    all_tests_ok &= test_generate_mask();

    all_tests_ok &= test_lda();
    all_tests_ok &= test_ldx();
    all_tests_ok &= test_ldi();

    all_tests_ok &= test_sta();
    all_tests_ok &= test_stx();
    all_tests_ok &= test_sti();
    all_tests_ok &= test_stj();
    all_tests_ok &= test_stz();

    all_tests_ok &= test_add();
    all_tests_ok &= test_sub();
    all_tests_ok &= test_mul();
    all_tests_ok &= test_div();

    all_tests_ok &= test_enter();

    all_tests_ok &= test_inc();
    all_tests_ok &= test_dec();

    all_tests_ok &= test_cmpa();
    all_tests_ok &= test_cmpx();
    all_tests_ok &= test_cmpi();

    all_tests_ok &= test_jmp();
    all_tests_ok &= test_jov();
    all_tests_ok &= test_jnov();
    all_tests_ok &= test_jcc();
    all_tests_ok &= test_jca();
    all_tests_ok &= test_jcx();
    all_tests_ok &= test_jci();

    all_tests_ok ? print_test_success() : print_test_failure();

    return 0;
}
