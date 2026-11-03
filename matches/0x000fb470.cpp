#include "gen/owners.h"
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);


owners::Thing_fb470* owners::Thing_fb470::FUN_000fb470(const char* s) {
    strncpy(text, s, 0x20);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    value = 1.0f;
    return this;
}