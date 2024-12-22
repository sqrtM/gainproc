#include "load.h"
#include <stdio.h>

int lda(s_Mix *mix, unsigned int addr, unsigned int field, bool negative) {
    s_Word contents_m = mix->memory[addr];

    s_Field f = to_field(field);
    unsigned int mask = generate_mask(f.l, f.r);

    mix->A->value = (contents_m.value & mask) >> (5 - f.r) * 6;
    mix->A->sign &= contents_m.sign & f.s & !negative;

    return 0;
}

int ldx(s_Mix *mix, unsigned int addr, unsigned int field, bool negative) {
    s_Word contents_m = mix->memory[addr];

    s_Field f = to_field(field);
    unsigned int mask = generate_mask(f.l, f.r);

    mix->X->value = (contents_m.value & mask) >> (5 - f.r) * 6;
    mix->X->sign &= contents_m.sign & f.s & !negative;

    return 0;
}

// int ldi(s_Mix *mix, unsigned int addr, unsigned int i, unsigned int field, bool negative) {}
