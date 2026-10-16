#include "gen/pure3d.h"

typedef unsigned int U_327690;
struct d3dPrimBufferStream_nv_327690 {
    void finish();
};

void pure3d::d3dPrimBufferStream::vfunc_15(void* __p0, void* __p1) { U_327690 * a = (U_327690 *)__p0; U_327690 * b = (U_327690 *)__p1;

    U_327690* p = (*(U_327690 * *)&this->f_24);
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    vfunc_1(b[0], b[1], b[2]);
    ((d3dPrimBufferStream_nv_327690*)this)->finish();
}
