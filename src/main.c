#include <stdio.h>
#include "sm83.h"

#ifdef TEST_MODE
int run_tests();
#else
int main() {
    printf("Running the main application.\n");
    return 0;
}
#endif
