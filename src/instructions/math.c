#include "math.h"

unsigned int mask_value(unsigned int field, unsigned int v) {
    s_Field f = to_field(field);
    v &= generate_mask(f.l, f.r);
    return v >> ((5 - f.r) * 6);
}

s_Word add_words(s_Word r, s_Word v) {
    s_Word result;

    if (r.sign == v.sign) {
        result.value = r.value + v.value;
        result.sign = r.sign;
    } else {
        if (r.value >= v.value) {
            result.value = r.value - v.value;
        } else {
            result.value = v.value - r.value;
        }
        result.sign = r.sign == (r.value >= v.value);
    }

    return result;
}

s_Word sub_words(s_Word r, s_Word v) {
    s_Word result;

    if (r.sign == v.sign) {
        if (r.value >= v.value) {
            result.value = r.value - v.value;
        } else {
            result.value = v.value - r.value;
        }
        result.sign = r.value < v.value && !(r.sign && v.sign);
    } else {
        result.value = r.value + v.value;
        result.sign = r.sign;
    }

    return result;
}

int add(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word a = *mix->A;
    s_Word v = mix->memory[addr];

    v.value = mask_value(field, v.value);

    if (a.value > WORD_MAX - v.value && a.sign == v.sign) {
        mix->overflow = true;
    }

    *mix->A = add_words(a, v);
    return 0;
}

int sub(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word a = *mix->A;
    s_Word v = mix->memory[addr];

    v.value = mask_value(field, v.value);

    if (a.sign != v.sign && a.value > WORD_MAX - v.value) {
        mix->overflow = true;
    }

    *mix->A = sub_words(a, v);
    return 0;
}

int mul(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Combined_Registers result;
    result.value = mix->A->value;
    result.sign = mix->A->sign;
    s_Word v = mix->memory[addr];

    v.value = mask_value(field, v.value);

    result.value *= v.value;
    result.sign = result.sign && v.sign;

    mix->A->value = result.value >> 30;
    mix->A->sign = result.sign;
    mix->X->value = result.value & WORD_MAX;
    mix->X->sign = result.sign;

    return 0;
}

int div(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Combined_Registers result;
    result.value = (unsigned long long)(mix->A->value) << 29;
    result.value |= mix->X->value;
    result.sign = mix->A->sign;
    s_Word v = mix->memory[addr];

    v.value = mask_value(field, v.value);

    // Go ahead and set sign of rX now before we do anything
    mix->X->sign = mix->A->sign;

    if (v.value == 0 || mix->A->value >= v.value)
        mix->overflow = true;

    // If an "overflow" has occurred, rA and rX are technically undefined.
    // Since this is the case, we still TRY and conduct the operation.
    mix->A->value = result.value / v.value;
    mix->X->value = result.value % v.value;
    mix->A->sign = result.sign && v.sign;
    return 0;
}
