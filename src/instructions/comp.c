#include "comp.h"

void compare(s_Mix *mix, s_Word w, s_Word m, bool signs_included) {
    if (signs_included) {
        if (w.sign == false && m.sign == false) {
            if (w.value > m.value) {
                mix->comp = L;
            } else if (w.value < m.value) {
                mix->comp = G;
            } else
                mix->comp = E;
        } else if (w.sign == true && m.sign == true) {
            if (w.value < m.value) {
                mix->comp = L;
            } else if (w.value > m.value) {
                mix->comp = G;
            } else
                mix->comp = E;
        } else if (w.sign == true && m.sign == false) {
            if (w.value != 0 && m.value != 0) {
                mix->comp = G;
            } else
                mix->comp = E;
        } else {
            if (w.value != 0 && m.value != 0) {
                mix->comp = L;
            } else
                mix->comp = E;
        }
    } else {
        // assume positive
        if (w.value < m.value) {
            mix->comp = L;
        } else if (w.value > m.value) {
            mix->comp = G;
        } else
            mix->comp = E;
    }
}

int cmpa(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Field f = to_field(field);
    unsigned int mask = generate_mask(f.l, f.r);

    s_Word a = *mix->A;
    s_Word m = mix->memory[addr];

    a.value &= mask;
    m.value &= mask;

    compare(mix, a, m, f.l == 0);

    return 0;
}

int cmpx(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Field f = to_field(field);
    unsigned int mask = generate_mask(f.l, f.r);

    s_Word x = *mix->X;
    s_Word m = mix->memory[addr];

    x.value &= mask;
    m.value &= mask;

    compare(mix, x, m, f.l == 0);

    return 0;
}

int cmpi(s_Mix *mix, unsigned int addr, unsigned int i, unsigned int field) {
    s_Field f = to_field(field);
    unsigned int mask = generate_mask(f.l, f.r);

    if (i > 6 || i < 1)
        return 1;

    s_Small_Register *i_register = get_i_register(mix, i);

    s_Word i_word;
    i_word.sign = i_register->sign;
    i_word.value = i_register->value;

    s_Word m = mix->memory[addr];

    i_word.value &= mask;
    m.value &= mask;

    compare(mix, i_word, m, f.l == 0);

    return 0;
}
