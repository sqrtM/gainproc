#ifndef MIX
#define MIX

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
#endif
