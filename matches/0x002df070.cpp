#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0042fa64[];
struct ShadowSkin_nv_2df070 {
    void Init(pure3d::ShadowSkin*);
};
extern void* __cdecl alloc(int);

void* pure3d::ShadowSkin::vfunc_4() {
    pure3d::ShadowSkin* q = (pure3d::ShadowSkin*)alloc(0x58);
    if (q) {
        ((ShadowSkin_nv_2df070*)(q))->Init(this);
        *(hulk_intptr*)q = ((hulk_intptr)DAT_0042fa64);
        return (void*)(q);
    }
    return (void*)(0);
}
