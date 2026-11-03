#include "gen/owners.h"
extern "C" void* __cdecl FUN_00240750();
extern "C" void __cdecl FUN_002416c0(void*, void*, float);
void owners::Thing_1e8d00::FUN_001e8d00(unsigned int n) {
    if (FUN_00240750()) {
        void* p = FUN_00240750();
        FUN_002416c0(p, value, (float)n);
    }
}