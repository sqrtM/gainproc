#include "math.h"

int add(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word a = *mix->A;
    s_Word v = mix->memory[addr];

    s_Field f = to_field(field);
    v.value &= generate_mask(f.l, f.r);
    v.value = v.value >> (5 - f.r);

    s_Word result;

    if (a.sign == v.sign) {
        if (a.value > WORD_MAX - v.value) {
            mix->overflow = true;
        }
        result.value = a.value + v.value;
        result.sign = a.sign;
    } else {
        if (a.value >= v.value) {
            result.value = a.value - v.value;
        } else {
            result.value = v.value - a.value;
        }
        result.sign = a.sign == a.value >= v.value;
    }

    *mix->A = result;
    return 0;
}

// int sub(s_Mix *mix, unsigned int addr, unsigned int field);
// int mul(s_Mix *mix, unsigned int addr, unsigned int i, unsigned int field);
// int div(s_Mix *mix, unsigned int addr, unsigned int field);
