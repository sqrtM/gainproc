#ifndef SM83
#define SM83

#include <stdint.h>

typedef enum {
    AF,
    BC,
    DE,
    HL,
    SP,
    PC,
} E_Sm83_Registers;

typedef struct {
    int16_t AF;
    int16_t BC;
    int16_t DE;
    int16_t HL;
    int16_t SP;
    int16_t PC;
} Sm83_Registers;

void init_registers(Sm83_Registers *regs);
void set_register(Sm83_Registers *regs, E_Sm83_Registers reg, int16_t value);
int16_t get_register(const Sm83_Registers *regs, E_Sm83_Registers reg);

#endif // MY_STRUCT_H
