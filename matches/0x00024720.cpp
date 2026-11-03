#include "gen/owners.h"
extern "C" void* memmove(void*, const void*, unsigned int);
bool owners::ItemList_24720::FUN_00024720(int a, int b) {
    int index = Find(a, b);
    if (index == -1)
        return false;
    int n = --count;
    memmove((char*)this + 0x228 + index * 8, (char*)this + 0x230 + index * 8, (n - index) * 8);
    return true;
}