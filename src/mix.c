#include "mix.h"
#include <stdlib.h>

void init_mix(s_Mix *regs) {
    regs->A = malloc(sizeof(s_Large_Register));
    regs->A->sign = true;
    regs->A->value = 0;

    regs->X = malloc(sizeof(s_Large_Register));
    regs->X->sign = true;
    regs->X->value = 0;

    regs->I1 = malloc(sizeof(s_Large_Register));
    regs->I1->sign = true;
    regs->I1->value = 0;

    regs->I2 = malloc(sizeof(s_Large_Register));
    regs->I2->sign = true;
    regs->I2->value = 0;

    regs->I3 = malloc(sizeof(s_Large_Register));
    regs->I3->sign = true;
    regs->I3->value = 0;

    regs->I4 = malloc(sizeof(s_Large_Register));
    regs->I4->sign = true;
    regs->I4->value = 0;

    regs->I5 = malloc(sizeof(s_Large_Register));
    regs->I5->sign = true;
    regs->I5->value = 0;

    regs->I6 = malloc(sizeof(s_Large_Register));
    regs->I6->sign = true;
    regs->I6->value = 0;

    regs->J = malloc(sizeof(s_Large_Register));
    regs->J->sign = true;
    regs->J->value = 0;

    regs->comp = E;
    regs->overflow = false;

    s_Word *mem = malloc(sizeof(s_Word) * 40);
    regs->memory = mem;
    regs->stack_pointer = 0;
}

s_Field to_field(unsigned int f) {
    s_Field *field = malloc(sizeof(s_Field));
    field->l = f / 8;
    field->r = f % 8;
    field->s = field->l == 0;

    return *field;
}

unsigned int generate_mask(uint8_t l, uint8_t r) {
    unsigned int mask = 0;

    if (l > r || l > 5 || r > 5) {
        return mask;
    }

    if (l == 0 && r != 0) {
        l = 1;
    }

    if (!(l == 0 && r == 0)) {
        for (unsigned int i = 0; i < ((r - l) + 1) * 6; i++) {
            mask |= (1 << i);
        }
    }

    if (r != 0) {
        mask = mask << ((5 - r) * 6);
    }

    return mask;
}

s_Small_Register *get_i_register(s_Mix *mix, unsigned int i) {
    s_Small_Register *i_register = NULL;

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
        i_register->value = 0;
        i_register->sign = false;
    }

    return i_register;
}
