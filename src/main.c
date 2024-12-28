#include "mix.h"
#include <stdio.h>
#include <string.h>

#ifndef TEST_MODE

#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN "\033[36m"

int main() {
    char command[256];

    printf(COLOR_CYAN "> > Mix Term < <\n" COLOR_RESET);

    while (1) {
        printf(COLOR_YELLOW "> " COLOR_RESET);

        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "EXIT") == 0) {
            printf(COLOR_GREEN "< Exiting...\n" COLOR_RESET);
            break;
        } else {
            printf(COLOR_GREEN "< Ok\n" COLOR_RESET);
        }
    }

    return 0;
}
#endif
