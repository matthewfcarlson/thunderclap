#include "gen/owners.h"
extern void __cdecl F1(int, int);
extern void __cdecl F2(int, int);
extern void __cdecl F3(int, int);
bool owners::Obj_1d1d90::FUN_001d1d90(hulk_intptr a, int b) {
    F1(member, ((int)a));
    F2(member, b);
    F3(member, -3);
    return true;
}