#include "gen/owners.h"
extern "C" int __cdecl FUN_00270ba0();
extern "C" int __cdecl FUN_0026fd50(int, int);
extern int __cdecl f66eb0(int, int, int);
void owners::Obj_277630::FUN_00277630(int a, hulk_intptr b, int c) {
    if (m1c == 0) {
        m20 = a;
        int x = FUN_0026fd50(FUN_00270ba0(), c);
        m18 = x;
        m14 = f66eb0(m20, x, ((int)b));
    }
    ++m1c;
}