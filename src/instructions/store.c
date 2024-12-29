#include "store.h"

s_Word construct_value_to_store(s_Word m, s_Word r, s_Field f) {
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
    mix->memory[addr] =
        construct_value_to_store(mix->memory[addr], *mix->A, to_field(field));
    return 0;
}

int stx(s_Mix *mix, unsigned int addr, unsigned int field) {
    mix->memory[addr] =
        construct_value_to_store(mix->memory[addr], *mix->X, to_field(field));
    return 0;
}

int sti(s_Mix *mix, unsigned int addr, unsigned int i, unsigned int field) {
    if (i > 6 || i < 1)
        return 1;

    s_Small_Register *i_register = get_i_register(mix, i);

    s_Word contents_i;
    contents_i.value = 0;
    contents_i.value |= i_register->value;
    contents_i.sign = i_register->sign;

    mix->memory[addr] = construct_value_to_store(mix->memory[addr], contents_i,
                                                 to_field(field));
    return 0;
}

int stj(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word contents_j;
    contents_j.value = 0;
    contents_j.value |= mix->J->value;
    contents_j.sign = true;

    mix->memory[addr] = construct_value_to_store(mix->memory[addr], contents_j,
                                                 to_field(field));
    return 0;
}

int stz(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word contents_z;
    contents_z.value = 0;
    // Zeroing out a sign is (I believe) undefined behavior,
    // so we assume it is a "positive zero" if it ever comes down to that.
    contents_z.sign = true;

    mix->memory[addr] = construct_value_to_store(mix->memory[addr], contents_z,
                                                 to_field(field));
    return 0;
}
