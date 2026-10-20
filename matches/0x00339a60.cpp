#include "compat/ptr.h"
extern "C" void __cdecl FUN_00339a40();
typedef unsigned int U_339a60;
extern int __cdecl FUN_00213b20(U_339a60, hulk_uintptr, U_339a60*, U_339a60);
int __cdecl FUN_00339a60(U_339a60 a, U_339a60 b, U_339a60 c, U_339a60 d) {
    U_339a60 locals[2];
    locals[0] = b;
    locals[1] = c;
    return FUN_00213b20(a, ((hulk_intptr)(void (__cdecl*)())&FUN_00339a40), locals, d);
}