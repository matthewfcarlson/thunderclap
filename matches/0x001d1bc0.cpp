#include "gen/owners.h"
extern int __cdecl FUN_00212d70(int);
extern "C" void __cdecl FUN_00213320(int);
bool owners::Obj_1d1bc0::FUN_001d1bc0() {
    if (index < 7 && index >= -1) {
        ++index;
        items[index] = FUN_00212d70(value);
        FUN_00213320(value);
        return true;
    }
    return false;
}