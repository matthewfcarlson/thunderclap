// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00295c40..0x002980b0 (kind game, layer engine, confidence high), dominant class pure3d::scenegraph::Scenegraph
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00297130 pure3d::scenegraph::Scenegraph::vfunc_4 (31 B): matches/0x00297130.cpp [isolated: conflict: alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_4@Scenegraph@scenegraph@pure3d@@UAEPAXXZ
#include "gen/pure3d.h"

struct Scenegraph_nv_297130 {
    hulk_intptr helper(pure3d::scenegraph::Scenegraph*);
};
extern pure3d::scenegraph::Scenegraph* alloc(int);

void* pure3d::scenegraph::Scenegraph::vfunc_4() {
    pure3d::scenegraph::Scenegraph* p = alloc(0x48);
    if (p)
        return (void*)(((Scenegraph_nv_297130*)(((pure3d::scenegraph::Scenegraph*)(p))))->helper(this));
    return (void*)(0);
}

