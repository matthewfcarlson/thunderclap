#include "gen/owners.h"
extern "C" void __stdcall FUN_00203e30(void*);
bool owners::Obj_2078d0::FUN_002078d0() {
    if (field) {
        FUN_00203e30(field);
        return FUN_00207410();
    }
    return false;
}