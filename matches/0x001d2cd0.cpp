#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"

extern "C" void __cdecl FUN_00213360(int, int);
extern void __cdecl F2(int, int);
extern int __cdecl F3(int, int);
extern void __cdecl F4(int, int, hulk_intptr, int);
extern void __cdecl F5(int, int);
bool owners::C_1d2cd0::FUN_001d2cd0(int a, hulk_intptr b, int c) {
    FUN_00213360(field, a);
    F2(field, -2);
    int r = F3(field, -1);
    bool ok = true;
    if (!r)
        ok = false;
    else
        F4(((int)b), c, ((hulk_intptr)((char*)&DAT_003f3f38)), r);
    F5(field, -2);
    return ok;
}
