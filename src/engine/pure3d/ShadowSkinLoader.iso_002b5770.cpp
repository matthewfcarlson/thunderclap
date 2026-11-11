// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b37a0..0x002b78a0 (kind game, layer engine, confidence high), dominant class pure3d::ShadowSkinLoader
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x002b5770 pure3d::ShadowSkinImpl::vfunc_4 (34 B): matches/0x002b5770.cpp [isolated: compile error C2440: 'initializing' : cannot convert from 'void *' to 'pure3d::ShadowSkinImpl *'; on include/gen/ and not mergeable]
// sym: ?vfunc_4@ShadowSkinImpl@pure3d@@UAEPAXXZ
#include "gen/pure3d.h"

typedef unsigned int u32_2b5770;
struct ShadowSkinImpl_nv_2b5770 {
    hulk_uintptr run_002b5610(pure3d::ShadowSkinImpl*);
};
extern pure3d::ShadowSkinImpl* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::ShadowSkinImpl::vfunc_4() {
    pure3d::ShadowSkinImpl* p = thunk_FUN_0008d690((int)sizeof(pure3d::ShadowSkinImpl));
    if (p)
        return (void*)(((ShadowSkinImpl_nv_2b5770*)(((pure3d::ShadowSkinImpl*)(p))))->run_002b5610(this));
    return (void*)(0);
}

