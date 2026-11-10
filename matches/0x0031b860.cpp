#include "gen/pure3d.h"

// The d3dContext (gen pure3d::d3dContext): 0x00324e00 builds it on the device, 0x00320d30 finishes it.
struct Result_31b860 {
    void FUN_00320d30();
};
struct d3dContext_nv_31b860 {
    Result_31b860* FUN_00324e00(void*, pure3d::d3dDevice*);
};
extern pure3d::d3dContext* __cdecl FUN_0008d690(int);

void* pure3d::d3dDevice::vfunc_8(void* __p0) { void * p = (void *)__p0;

    pure3d::d3dContext* m = FUN_0008d690((int)sizeof(pure3d::d3dContext));
    Result_31b860* r;
    if (m)
        r = ((d3dContext_nv_31b860*)(((pure3d::d3dContext*)(m))))->FUN_00324e00(p, this);
    else
        r = 0;
    r->FUN_00320d30();
    return (void*)(r);
}
