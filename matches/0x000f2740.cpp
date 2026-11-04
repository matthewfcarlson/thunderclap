#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct FEPoseAnimationInvisible_nv_f2740 {
    int make(void*, void*);
};
hulk_intptr owners::Y_f2740::FUN_000f2740(void* p) {
    if (!field)
        return 0;
    FEPoseAnimationInvisible* x = (FEPoseAnimationInvisible*)FUN_0008d690((int)sizeof(FEPoseAnimationInvisible));
    hulk_intptr r = x ? ((FEPoseAnimationInvisible_nv_f2740*)(((FEPoseAnimationInvisible*)(x))))->make(field, p) : 0;
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
