#include "gen/pure3d.h"

struct Result_31b860 {
    void done();
};
struct d3dContext_nv_31b860 {
    Result_31b860* make(void*, pure3d::d3dDevice*);
};
extern pure3d::d3dContext* __cdecl FUN_0008d690(int);

void* pure3d::d3dDevice::vfunc_8(void* __p0) { void * p = (void *)__p0;

    pure3d::d3dContext* m = FUN_0008d690(0x450);
    Result_31b860* r;
    if (m)
        r = ((d3dContext_nv_31b860*)(m))->make(p, this);
    else
        r = 0;
    r->done();
    return (void*)(r);
}
