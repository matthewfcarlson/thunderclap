#include "gen/pure3d.h"

struct Result_31b860 {
    void done();
};
struct Maker_31b860 {
    Result_31b860* make(void*, pure3d::d3dDevice*);
};
extern Maker_31b860* __cdecl FUN_0008d690(int);

void* pure3d::d3dDevice::vfunc_8(void* __p0) { void * p = (void *)__p0;

    Maker_31b860* m = FUN_0008d690(0x450);
    Result_31b860* r;
    if (m)
        r = m->make(p, this);
    else
        r = 0;
    r->done();
    return (void*)(r);
}
