#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {
struct V3 {
    int x, y, z;
};
struct V2 {
    int x, y;
};
struct d3dPrimBufferStream_nv_327710 {
    void advance();
};

} // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_13(hulk_intptr __p0, int c, hulk_intptr __p2) { const V3 * p = (const V3 *)__p0; const V2 * t = (const V2 *)__p2;

    V3* dest = (*(V3 * *)&this->f_24);
    dest->x = p->x;
    dest->y = p->y;
    dest->z = p->z;
    *(*(int * *)&this->f_30) = c;
    *(*(V2 * *)&this->f_38) = *t;
    ((d3dPrimBufferStream_nv_327710*)this)->advance();
}
