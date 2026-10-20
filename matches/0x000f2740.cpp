#include "gen/global.h"
typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct FEPoseAnimationInvisible_nv_f2740 {
    int make(void*, void*);
};
struct Y_f2740 {
    int pad;
    void* field;
    void* slots[32];
    int f(void*);
};
int Y_f2740::f(void* p) {
    if (!field)
        return 0;
    FEPoseAnimationInvisible* x = (FEPoseAnimationInvisible*)FUN_0008d690(0x60);
    int r = x ? ((FEPoseAnimationInvisible_nv_f2740*)(x))->make(field, p) : 0;
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
