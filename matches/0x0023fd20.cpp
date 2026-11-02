#include "compat/ptr.h"
struct Thing_23fd20 {
    int value;
    unsigned short a;
    unsigned short pad;
    unsigned short b;
    Thing_23fd20* run(int arg);
};
extern "C" void __cdecl FUN_0023fa40(int *, char *, unsigned int, int);
Thing_23fd20* Thing_23fd20::run(int arg) {
    a = 2;
    b = 0;
    FUN_0023fa40(&arg, (char *)(hulk_uintptr)(int)0, 0, arg);
    value = arg;
    return this;
}