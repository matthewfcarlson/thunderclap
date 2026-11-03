#include "gen/owners.h"
int owners::C_1b4420::FUN_001b4420(int key) {
    int result = 0;
    int* p = (int*)((char*)this + 0x4fc);
    for (int i = 0; i < 0x13; i++, p++)
        if (p[0x13] == key)
            result = p[0];
    return result;
}