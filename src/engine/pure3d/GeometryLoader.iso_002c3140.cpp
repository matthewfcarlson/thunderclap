// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c26d0..0x002c31b0 (kind game, layer engine, confidence high), dominant class pure3d::GeometryLoader
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x002c3140 pure3d::Geometry::vfunc_4 (31 B): matches/0x002c3140.cpp [isolated: conflict: thunk_FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_4@Geometry@pure3d@@UAEPAXXZ
#include "gen/pure3d.h"

struct Geometry_nv_2c3140 {
    hulk_intptr run(pure3d::Geometry*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::Geometry::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return (void*)(((Geometry_nv_2c3140*)(((pure3d::Geometry*)(((pure3d::Geometry*)p)))))->run(this));
    return (void*)(0);
}

