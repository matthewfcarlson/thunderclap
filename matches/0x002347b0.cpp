#include "compat/ptr.h"
typedef hulk_uintptr U32_2347b0;
extern void* MakeTemp(int);
extern "C" void* FUN_00266da0(void*);
extern "C" void* FUN_0008d6d0(int);

extern "C" void FUN_002347b0(U32_2347b0** out, U32_2347b0* src, int count) {
    void* p = MakeTemp(0);
    p = FUN_00266da0(p);
    *out = (U32_2347b0*)FUN_0008d6d0(count * sizeof(U32_2347b0) + sizeof(U32_2347b0));
    int i;
    for (i = 0; i < count; ++i)
        (*out)[i] = src[i];
    (*out)[count] = 0;
    FUN_00266da0(p);
}
