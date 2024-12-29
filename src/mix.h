#ifndef MIX
#define MIX

#define WORD_MAX 0b111111111111111111111111111111
#define HALF_WORD_MAX 0b111111111111

#include <stdbool.h>
#include <stdint.h>

typedef struct s_Large_Register {
    bool sign;
    unsigned int value : 30;
} s_Large_Register;

typedef s_Large_Register s_Word;

typedef struct s_Small_Register {
    bool sign;
    uint16_t value : 12;
} s_Small_Register;

typedef enum { E, L, G } e_Comp;

typedef struct {
    s_Large_Register *A;
    s_Large_Register *X;
    s_Small_Register *I1;
    s_Small_Register *I2;
    s_Small_Register *I3;
    s_Small_Register *I4;
    s_Small_Register *I5;
    s_Small_Register *I6;
    s_Small_Register *J;
    e_Comp comp;
    bool overflow;
    s_Word *memory;
} s_Mix;

void init_mix(s_Mix *mix);

typedef struct s_Field {
    uint8_t l;
    uint8_t r;
    bool s;
} s_Field;

s_Field to_field(unsigned int f);
unsigned int generate_mask(uint8_t l, uint8_t r);
s_Small_Register *get_i_register(s_Mix *mix, unsigned int i);

#endif
