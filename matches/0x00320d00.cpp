#include "gen/owners.h"
bool owners::Holder_320d00::FUN_00320d00(int value) {
    int i = 0;
    int* p = (int*)((char*)this + 0x184);
    do {
        int x = *p;
        if (x == -1)
            return false;
        if (x == value)
            return true;
        ++i;
        ++p;
    } while (i < 0x20);
    return false;
}