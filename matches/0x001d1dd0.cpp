#include "gen/owners.h"
extern "C" void __cdecl F1(int, int);
extern "C" void __cdecl F2(int, float);
extern "C" void __cdecl F3(int, int);
bool owners::Obj_1d1dd0::FUN_001d1dd0(hulk_intptr a, int b) {
    F1(field, ((int)a));
    F2(field, (float)b);
    F3(field, -3);
    return true;
}