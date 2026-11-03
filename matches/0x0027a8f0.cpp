#include "gen/owners.h"
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
char owners::Thing_27a8f0::FUN_0027a8f0(const char* a, const char* b) {
    if (count + 1 == 0x68)
        return 0;
    names[count * 32 + 31] = 0;
    strncpy(names + count * 32, a, 31);
    desc[count * 96 + 0x5f] = 0;
    strncpy(desc + count * 96, b, 95);
    ++count;
    return 1;
}