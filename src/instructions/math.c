#include "math.h"

unsigned int mask_value(unsigned int field, unsigned int v) {
    s_Field f = to_field(field);
    v &= generate_mask(f.l, f.r);
    return v >> ((5 - f.r) * 6);
}

int add(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word a = *mix->A;
    s_Word v = mix->memory[addr];

    v.value = mask_value(field, v.value);

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

int sub(s_Mix *mix, unsigned int addr, unsigned int field) {
    s_Word a = *mix->A;
    s_Word v = mix->memory[addr];

    v.value = mask_value(field, v.value);

    s_Word result;

    if (a.sign == v.sign) {
        if (a.value >= v.value) {
            result.value = a.value - v.value;
        } else {
            result.value = v.value - a.value;
        }
        result.sign = a.value < v.value && !(a.sign && v.sign);
    } else {
        if (a.value > WORD_MAX - v.value) {
            mix->overflow = true;
        }
        result.value = a.value + v.value;
        result.sign = a.sign;
    }

    *mix->A = result;
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
