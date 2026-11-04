// Same code shape as 0x000f2740 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct FEShaderAnimation_nv_f28c0 {
    int make(void*, void*);
};
hulk_intptr owners::Y_f28c0::FUN_000f28c0(void* p) {
    if (!field)
        return 0;
    FEShaderAnimation* x = (FEShaderAnimation*)FUN_0008d690((int)sizeof(FEShaderAnimation));
    hulk_intptr r = x ? ((FEShaderAnimation_nv_f28c0*)(((FEShaderAnimation*)(x))))->make(field, p) : 0;
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (r)
                slots[i] = (void*)r;
            return r;
        }
        ++i;
    } while (i < 32);
    return r;
}
