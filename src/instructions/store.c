#include "store.h"
#include <stdio.h>

int sta(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word contents_a = *mix->A;
    s_Word contents_m = mix->memory[addr];
    s_Field f = to_field(field);

    contents_m.value &= ~generate_mask(f.l, f.r);

    if (f.l == 0) {
        contents_a.value &= generate_mask(5 - (f.r - 1), 5);
        contents_m.value |= contents_a.value;
        contents_m.sign = contents_a.sign;
    } else {
        contents_a.value &= generate_mask(5 - (f.r - f.l), 5);
        contents_m.value |= (contents_a.value << (5 - f.r) * 6);
    }
    mix->memory[addr] = contents_m;
    return 0;
}

int stx(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word contents_x = *mix->X;
    s_Word contents_m = mix->memory[addr];
    s_Field f = to_field(field);

    contents_m.value &= ~generate_mask(f.l, f.r);

    if (f.l == 0) {
        contents_x.value &= generate_mask(5 - (f.r - 1), 5);
        contents_m.value |= contents_x.value;
        contents_m.sign = contents_x.sign;
    } else {
        contents_x.value &= generate_mask(5 - (f.r - f.l), 5);
        contents_m.value |= (contents_x.value << (5 - f.r) * 6);
    }
    mix->memory[addr] = contents_m;
    return 0;
}


// int sti(s_Mix *mix, unsigned int addr, unsigned int i, unsigned int field);
// int stj(s_Mix *mix, unsigned int addr, unsigned int field);
// int stz(s_Mix *mix, unsigned int addr, unsigned int field);
