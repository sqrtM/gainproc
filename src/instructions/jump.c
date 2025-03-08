#include "./jump.h"
#include <stdbool.h>

int _jump(s_Mix *mix, unsigned int addr, bool save_j) {
    if (!save_j) {
        mix->J->sign = true;
        mix->J->value = mix->stack_pointer + 1;
    }
    mix->stack_pointer = addr;
    return 0;
}

int jmp(s_Mix *mix, unsigned int addr, bool save_j) {
    return _jump(mix, addr, save_j);
}

int jov(s_Mix *mix, unsigned int addr) {
    if (mix->overflow) {
        return _jump(mix, addr, false);
    } else {
        return 0;
    }
}

int jnov(s_Mix *mix, unsigned int addr) {
    if (mix->overflow) {
        return 0;
    } else {
        return _jump(mix, addr, false);
    }
}

int jcc(s_Mix *mix, unsigned int addr, e_Jump_Condition_Compare cond) {
    switch (cond) {
        case LESS:
            if (mix->comp == L) {
                _jump(mix, addr, false);
            }
            break;
        case EQUAL:
            if (mix->comp == E) {
                _jump(mix, addr, false);
            }
            break;
        case GREATER:
            if (mix->comp == G) {
                _jump(mix, addr, false);
            }
            break;
        case GREATER_OR_EQUAL:
            if (mix->comp != L) {
                _jump(mix, addr, false);
            }
            break;
        case UNEQUAL:
            if (mix->comp != E) {
                _jump(mix, addr, false);
            }
            break;
        case LESS_OR_EQUAL:
            if (mix->comp != G) {
                _jump(mix, addr, false);
            }
            break;
    }
    return 0;
}

int jca(s_Mix *mix, unsigned int addr, e_Jump_Condition_Register cond) {
    switch (cond) {
        case NEGATIVE:
            if (!mix->A->sign && mix->A->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case ZERO:
            if (mix->A->value == 0) {
                _jump(mix, addr, false);
            }
            break;
        case POSITIVE:
            if (mix->A->sign && mix->A->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case NON_NEGATIVE:
            if (mix->A->sign) {
                _jump(mix, addr, false);
            }
            break;
        case NON_ZERO:
            if (mix->A->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case NON_POSITIVE:
            if (!mix->A->value) {
                _jump(mix, addr, false);
            }
            break;
    }
    return 0;
}

int jcx(s_Mix *mix, unsigned int addr, e_Jump_Condition_Register cond) {
    switch (cond) {
        case NEGATIVE:
            if (!mix->X->sign && mix->X->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case ZERO:
            if (mix->X->value == 0) {
                _jump(mix, addr, false);
            }
            break;
        case POSITIVE:
            if (mix->X->sign && mix->X->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case NON_NEGATIVE:
            if (mix->X->sign) {
                _jump(mix, addr, false);
            }
            break;
        case NON_ZERO:
            if (mix->X->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case NON_POSITIVE:
            if (!mix->X->value) {
                _jump(mix, addr, false);
            }
            break;
    }
    return 0;
}

int jci(s_Mix *mix, unsigned int addr, unsigned int i, e_Jump_Condition_Register cond) {
    s_Small_Register *i_register = get_i_register(mix, i);

    switch (cond) {
        case NEGATIVE:
            if (!i_register->sign && i_register->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case ZERO:
            if (i_register->value == 0) {
                _jump(mix, addr, false);
            }
            break;
        case POSITIVE:
            if (i_register->sign && i_register->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case NON_NEGATIVE:
            if (i_register->sign) {
                _jump(mix, addr, false);
            }
            break;
        case NON_ZERO:
            if (i_register->value != 0) {
                _jump(mix, addr, false);
            }
            break;
        case NON_POSITIVE:
            if (!i_register->value) {
                _jump(mix, addr, false);
            }
            break;
    }
    return 0;
}
