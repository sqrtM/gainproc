#include "store.h"
#include <stdio.h>

s_Word get_stored_value(s_Word m, s_Word r, s_Field f) {
    m.value &= ~generate_mask(f.l, f.r);

    if (f.l == 0) {
        r.value &= generate_mask(5 - (f.r - 1), 5);
        m.sign = r.sign;
    } else {
        r.value &= generate_mask(5 - (f.r - f.l), 5);
    }

    m.value |= (r.value << (5 - f.r) * 6);
    return m;
}

int sta(s_Mix *mix, unsigned int addr, unsigned int field) {
    mix->memory[addr] = get_stored_value(mix->memory[addr], *mix->A, to_field(field));
    return 0;
}

int stx(s_Mix *mix, unsigned int addr, unsigned int field) {
    mix->memory[addr] = get_stored_value(mix->memory[addr], *mix->X, to_field(field));
    return 0;
}

int sti(s_Mix *mix, unsigned int addr, unsigned int i, unsigned int field) {
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

    s_Word contents_i;
    contents_i.value = 0;
    contents_i.value |= i_register->value;
    contents_i.sign = i_register->sign;

    mix->memory[addr] = get_stored_value(mix->memory[addr], contents_i, to_field(field));
    return 0;
}

// int stj(s_Mix *mix, unsigned int addr, unsigned int field);
// int stz(s_Mix *mix, unsigned int addr, unsigned int field);
