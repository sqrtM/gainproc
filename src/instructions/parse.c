#include "parse.h"

void execute_opcode(int16_t opcode) {
    switch ((opcode >> 14) & 0x03) {
        case 0b00: break;
        case 0b01: {

        };
        case 0b10: break;
        case 0b11: break;
    }
}
