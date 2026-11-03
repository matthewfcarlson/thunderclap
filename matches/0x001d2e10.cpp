#include "gen/owners.h"
void FUN_002133d0(int L, int a);
void FUN_00213600(int L, int a);
int FUN_00212f00(int L, int a);
void FUN_00212d80(int L, int a);
extern "C" int __cdecl FUN_00339650(int, int);
bool owners::C_1d2e10::FUN_001d2e10(hulk_intptr a, int* out) {
    FUN_002133d0(L, ((int)a));
    FUN_00213600(L, -2);
    bool r = true;
    if (FUN_00212f00(L, -1) != 6) {
        r = false;
        FUN_00212d80(L, -2);
    } else {
        *out = FUN_00339650(L, -10000);
    }
    return r;
}
