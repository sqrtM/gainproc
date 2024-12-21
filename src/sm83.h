#ifndef SM83
#define SM83

#include <stdint.h>

typedef int16_t sm83_register;
typedef int8_t  sm83_half_register;

sm83_half_register hi(sm83_register *reg);
sm83_half_register lo(sm83_register *reg);

typedef enum {
    BC,
    DE,
    HL,
    SP,
    PC,
    AF
} E_Sm83_Registers;

typedef struct {
    sm83_register AF;
    sm83_register BC;
    sm83_register DE;
    sm83_register HL;
    sm83_register SP;
    sm83_register PC;
} Sm83_Registers;

void init_registers(Sm83_Registers *regs);
void set_register(Sm83_Registers *regs, E_Sm83_Registers reg, int16_t value);
const sm83_register *get_register(const Sm83_Registers *regs, E_Sm83_Registers reg);

#endif
