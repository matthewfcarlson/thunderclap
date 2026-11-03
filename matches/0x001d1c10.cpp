#include "gen/owners.h"
int __cdecl FUN_00212d70(int);
int __cdecl FUN_00212d80(int, int);
extern "C" int __cdecl FUN_00213c50(int, int);
bool owners::C_1d1c10::FUN_001d1c10(int p) {
    if (idx < 0)
        return false;
    int n = FUN_00212d70(obj);
    int v = vals[idx];
    if (n != v + 1) {
        FUN_00212d80(obj, v);
        return false;
    }
    return FUN_00213c50(obj, p) != 0;
}