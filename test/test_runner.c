#include <stdio.h>
#include "test_sm83.h"

int main() {
    printf("Running tests...\n");
    test_init_registers();
    test_set_get_register();
    return 0;
}
