#include <stdio.h>
#include "test_utils.h"

void print_ok(const char* test) {
    printf(COLOR_GREEN CHECK_MARK " %s passed" COLOR_RESET "\n", test);
}

void print_ko(const char* test, const char* message) {
    printf(COLOR_RED CROSS_MARK " %s " RIGHT_ARROW " FAILED: %s" COLOR_RESET "\n", test, message);
}

void print_row_of_suns() {
    printf(COLOR_YELLOW SUN " " SUN " " SUN " " SUN " " SUN " " SUN " " SUN "\n" COLOR_RESET);
}

void print_init_test_message() {
    printf(COLOR_YELLOW "Running tests...\n" COLOR_RESET);
    print_row_of_suns();
}

void print_test_success() {
    printf(COLOR_YELLOW "Testing Complete!\n" COLOR_RESET);
    printf(COLOR_GREEN SUN " " SUN " All tests passing ! " SUN " " SUN COLOR_RESET "\n");
}

void print_test_failure() {
    printf(COLOR_YELLOW "Testing Complete!\n" COLOR_RESET);
    printf(COLOR_RED CLOUD " " CLOUD " Tests failed ... " CLOUD " " CLOUD COLOR_RESET "\n");
}
