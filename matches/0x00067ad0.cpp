#include "gen/owners.h"
void* owners::C_67ad0::FUN_00067ad0(unsigned int x) {
    if (x == 0)
        return 0;
    int i = (int)(x & 255);
    if (slots[i] != x)
        return 0;
    if (i < 0)
        return 0;
    return (char*)this + i * 32 + 0x108;
}
