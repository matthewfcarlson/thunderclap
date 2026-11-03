#include "gen/owners.h"
void owners::C_36c90::FUN_00036c90(unsigned int index, unsigned int value) {
    if (index < 0x10)
        *(unsigned int*)(pad + 0x1e04 + index * 4) = value;
}