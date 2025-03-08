#include "../mix.h"

// Macro of JMP and JSJ
int jmp(s_Mix *mix, unsigned int addr, bool save_j);

// On / Not on OVERFLOW
int jov(s_Mix *mix, unsigned int addr);
int jnov(s_Mix *mix, unsigned int addr);

typedef enum e_Jump_Condition_Compare {
    LESS, EQUAL, GREATER, GREATER_OR_EQUAL, UNEQUAL, LESS_OR_EQUAL,
} e_Jump_Condition_Compare;

// Jump Condition - Comparison. A macro-instruction of jumps checking the comparison.
// JL, JE, JG, JGE, JNE, JLE
int jcc(s_Mix *mix, unsigned int addr, e_Jump_Condition_Compare cond);

typedef enum e_Jump_Condition_Register {
    NEGATIVE, ZERO, POSITIVE, NON_NEGATIVE, NON_ZERO, NON_POSITIVE
} e_Jump_Condition_Register;

// Jump Condition - A Register. A macro-instruction of jumps checking the A Register.
// JAN, JAZ, JANN, JANZ, JANP
int jca(s_Mix *mix, unsigned int addr, e_Jump_Condition_Register cond);

// Jump Condition - A Register. A macro-instruction of jumps checking the X Register.
// JXN, JXZ, JXNN, JXNZ, JXNP
int jcx(s_Mix *mix, unsigned int addr, e_Jump_Condition_Register cond);

// Jump Condition - A Register. A macro-instruction of jumps checking the i Register.
// JiN, JiZ, JiNN, JiNZ, JiNP
int jci(s_Mix *mix, unsigned int addr, unsigned int i, e_Jump_Condition_Register cond);
