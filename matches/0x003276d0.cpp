#include "gen/pure3d.h"

namespace pure3d {
struct V3 {
    int a, b, c;
};
struct V2 {
    int a, b;
};
inline void Copy3(V3* dst, const V3* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
struct d3dPrimBufferStream_nv_3276d0 {
    void Advance();
};

} // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_14(int __p0, int __p1) { const V3 * p = (const V3 *)__p0; const V2 * t = (const V2 *)__p1;

    Copy3((*(V3 * *)&this->f_24), p);
    *(*(V2 * *)&this->f_38) = *t;
    ((d3dPrimBufferStream_nv_3276d0*)this)->Advance();
}
