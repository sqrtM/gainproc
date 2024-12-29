#include "enter.h"

int enta(s_Mix *mix, s_Small_Register m, bool negative) {
    mix->A->value = m.value;
    mix->A->sign &= m.sign & !negative;

    return 0;
}

int entx(s_Mix *mix, s_Small_Register m, bool negative) {
    mix->X->value = m.value;
    mix->X->sign &= m.sign & !negative;

    return 0;
}

int enti(s_Mix *mix, s_Small_Register m, unsigned int i, bool negative) {

    s_Small_Register *i_register;

    if (i == 1) {
        i_register = mix->I1;
    } else if (i == 2) {
        i_register = mix->I2;
    } else if (i == 3) {
        i_register = mix->I3;
    } else if (i == 4) {
        i_register = mix->I4;
    } else if (i == 5) {
        i_register = mix->I5;
    } else if (i == 6) {
        i_register = mix->I6;
    } else {
        // bad input
        return 1;
    }

    i_register->value = m.value;
    i_register->sign &= m.sign & !negative;

    return 0;
}
