#include "gen/owners.h"
void owners::C_1d1f30::FUN_001d1f30(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int* q = p;
    if ((unsigned int)((char*)q - (char*)this + 8) < 0x40) {
        q[0] = a;
        q[1] = b;
        q[2] = c;
        p = (unsigned int*)((char*)p + 12);
    }
}