#ifndef MIX
#define MIX

#define MASK_5_5 0x00_00_00_00_FF
#define MASK_4_5 0x00_00_00_FF_FF
#define MASK_3_5 0x00_00_FF_FF_FF
#define MASK_2_5 0x00_FF_FF_FF_FF
#define MASK_1_5 0xFF_FF_FF_FF_FF

#define MASK_4_4 0x00_00_00_FF_00
#define MASK_3_4 0x00_00_FF_FF_00
#define MASK_2_4 0x00_FF_FF_FF_00
#define MASK_1_4 0xFF_FF_FF_FF_00

#define MASK_3_3 0x00_00_FF_00_00
#define MASK_2_3 0x00_FF_FF_00_00
#define MASK_1_3 0xFF_FF_FF_00_00

#define MASK_2_2 0x00_FF_00_00_00
#define MASK_1_2 0xFF_FF_00_00_00

#define MASK_1_1 0xFF_00_00_00_00

#include <stdbool.h>
#include <stdint.h>

typedef struct s_Large_Register {
    bool sign;
    unsigned int value : 25;
} s_Large_Register;

typedef s_Large_Register s_Word;

typedef struct s_Small_Register {
    bool sign;
    uint16_t value : 10;
} s_Small_Register;

typedef enum { A, X, AX, I1, I2, I3, I4, I5, I6, J } e_Registers;

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

#endif
