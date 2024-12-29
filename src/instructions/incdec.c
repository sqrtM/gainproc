#include "incdec.h"
#include "math.h"

int inca(s_Mix *mix, s_Small_Register m) {
    s_Word w;
    w.sign = m.sign;
    w.value = m.value;

    if (mix->A->value > WORD_MAX - w.value && mix->A->sign == w.sign) {
        mix->overflow = true;
    }

    *mix->A = add_words(*mix->A, w);
    return 0;
}

int incx(s_Mix *mix, s_Small_Register m) {
    s_Word w;
    w.sign = m.sign;
    w.value = m.value;

    if (mix->X->value > WORD_MAX - w.value && mix->X->sign == w.sign) {
        mix->overflow = true;
    }

    *mix->X = add_words(*mix->X, w);
    return 0;
}

int inci(s_Mix *mix, s_Small_Register m, unsigned int i) {
    s_Word w;
    w.sign = m.sign;
    w.value = m.value;

    if (i > 6 || i < 1)
        return 1;

    s_Small_Register *i_register = get_i_register(mix, i);

    s_Word i_word;
    i_word.sign = i_register->sign;
    i_word.value = i_register->value;

    i_word = add_words(i_word, w);

    i_register->value = i_word.value;
    i_register->sign = i_word.sign;
    return 0;
}

// int deca(s_Mix *mix, s_Small_Register m);
// int decx(s_Mix *mix, s_Small_Register m);
// int deci(s_Mix *mix, s_Small_Register m, unsigned int i);
