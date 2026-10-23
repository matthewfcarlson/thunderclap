#include "compat/ptr.h"
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
