#include "sm83.h"

void init_registers(Sm83_Registers *regs) {
    regs->AF = 0;
    regs->BC = 0;
    regs->DE = 0;
    regs->HL = 0;
    regs->SP = 0;
    regs->PC = 0;
}

void set_register(Sm83_Registers *regs, E_Sm83_Registers reg, int16_t value) {
    switch (reg) {
        case AF:
            regs->AF = value;
            break;
        case BC:
            regs->BC = value;
            break;
        case DE:
            regs->DE = value;
            break;
        case HL:
            regs->HL = value;
            break;
        case SP:
            regs->SP = value;
            break;
        case PC:
            regs->PC = value;
            break;
    }
}

int16_t get_register(const Sm83_Registers *regs, E_Sm83_Registers reg) {
    switch (reg) {
        case AF:
            return regs->AF;
        case BC:
            return regs->BC;
        case DE:
            return regs->DE;
        case HL:
            return regs->HL;
        case SP:
            return regs->SP;
        case PC:
            return regs->PC;
    }
}
