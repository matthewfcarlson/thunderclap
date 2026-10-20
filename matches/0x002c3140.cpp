#include "gen/pure3d.h"

struct Geometry_nv_2c3140 {
    int run(pure3d::Geometry*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::Geometry::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return (void*)(((Geometry_nv_2c3140*)(((pure3d::Geometry*)p)))->run(this));
    return (void*)(0);
}
