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

    if (i > 6 || i < 1)
        return 1;

    s_Small_Register *i_register = get_i_register(mix, i);

    i_register->value = m.value;
    i_register->sign &= m.sign & !negative;

    return 0;
}
