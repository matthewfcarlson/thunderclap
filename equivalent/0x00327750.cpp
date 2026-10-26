// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::d3dPrimBufferStream::vfunc_12 @ 0x00327750
#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {
struct Triple_327750 { unsigned x,y,z; };
struct Pair_327750 { unsigned x,y; };
struct d3dPrimBufferStream_nv_327750 {
    void FUN_00326f90();
};

}
void pure3d::d3dPrimBufferStream::vfunc_12(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { const Triple_327750 * p = (const Triple_327750 *)__p0; const Triple_327750 * n = (const Triple_327750 *)__p1; const Pair_327750 * uv = (const Pair_327750 *)__p2;

 Triple_327750* out=(*(Triple_327750 * *)&this->f_24);
 out->x=p->x;
 out->y=p->y;
 out->z=p->z;
 vfunc_1(n->x,n->y,n->z);
 Pair_327750* dest=(*(Pair_327750 * *)&this->f_38);
 dest->x=uv->x;
 dest->y=uv->y;
 ((d3dPrimBufferStream_nv_327750*)this)->FUN_00326f90();
}
