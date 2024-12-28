#include "../mix.h"

typedef struct s_Combined_Registers {
    unsigned long long value: 60;
    bool sign;
} s_Combined_Registers;

int add(s_Mix *mix, unsigned int addr, unsigned int field);
int sub(s_Mix *mix, unsigned int addr, unsigned int field);
int mul(s_Mix *mix, unsigned int addr, unsigned int field);
int div(s_Mix *mix, unsigned int addr, unsigned int field);