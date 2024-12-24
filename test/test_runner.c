#include "test_load.h"
#include "test_mix.h"
#include "test_store.h"
#include "test_utils.h"

int main() {
    print_init_test_message();
    bool all_tests_ok = true;

    all_tests_ok &= test_init_mix();
    all_tests_ok &= test_shift_behavior();
    all_tests_ok &= test_generate_mask();

    all_tests_ok &= test_lda();
    all_tests_ok &= test_ldx();
    all_tests_ok &= test_ldi();

    all_tests_ok &= test_sta();
    all_tests_ok &= test_stx();
    all_tests_ok &= test_sti();
    all_tests_ok &= test_stj();
    all_tests_ok &= test_stz();

    all_tests_ok ? print_test_success() : print_test_failure();

    return 0;
}
