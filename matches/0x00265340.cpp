#include "gen/owners.h"
typedef unsigned int u32_265340;
struct Pair_265340 {
    char data[24];
    void First(u32_265340);
    int Second(u32_265340, u32_265340);
};
extern unsigned long long __cdecl Parse(char*, int, int);
hulk_intptr owners::Thing_265340::FUN_00265340(char* text) {
    if (*text == '.')
        ++text;
    unsigned long long value = Parse(text, 0, 0);
    Pair_265340 local;
    local.First(field);
    return local.Second((u32_265340)value, (u32_265340)(value >> 32));
}