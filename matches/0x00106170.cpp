#include "gen/owners.h"
bool owners::C_106170::FUN_00106170(int index, int a, int b, int c) {
    if (index < count) {
        int* p = (int*)((char*)items + index * 0x24);
        p[0] = a;
        p[1] = b;
        p[2] = c;
        return true;
    }
    return false;
}