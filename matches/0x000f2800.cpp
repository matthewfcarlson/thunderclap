#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
extern void* __cdecl Alloc(hulk_uintptr);
struct FEParticleAnimation_nv_f2800 {
    int Build(int, int, int);
};
hulk_intptr owners::Thing_f2800::FUN_000f2800(hulk_intptr a, hulk_intptr b) {
    if (ref == 0)
        return 0;
    FEParticleAnimation* p = (FEParticleAnimation*)Alloc(0x68);
    int result;
    if (p != 0)
        result = ((FEParticleAnimation_nv_f2800*)(((FEParticleAnimation*)(p))))->Build(ref, ((int)a), ((int)b));
    else
        result = 0;
    int i = 0;
    while (i < 32) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
        ++i;
    }
    return result;
}