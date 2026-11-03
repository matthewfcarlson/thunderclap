#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_0023fa40(int *, char *, unsigned int, int);
owners::Thing_23fd20* owners::Thing_23fd20::FUN_0023fd20(int arg) {
    a = 2;
    b = 0;
    FUN_0023fa40(&arg, (char *)(hulk_uintptr)(int)0, 0, arg);
    value = arg;
    return this;
}