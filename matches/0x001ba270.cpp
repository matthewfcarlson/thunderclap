// Same code shape as 0x0008a610 (propagated; names are from that function)
#include "gen/global.h"

struct Vector_1ba270 {
    int x, y, z;
};
class CGameFlowManager_1ba270 {
  public:
    virtual Vector_1ba270* Get(Vector_1ba270*);
};
typedef Vector_1ba270* (CGameFlowManager_1ba270::*Fn_1ba270)(Vector_1ba270*);

template <> void Method0<CRenderManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_1ba270 * mgr = (CGameFlowManager_1ba270 *)__p0; Vector_1ba270 * out = (Vector_1ba270 *)__p2;

    Fn_1ba270 fn = (*(Fn_1ba270 *)&this->f_1c);
    Vector_1ba270 temp;
    volatile Vector_1ba270 r;
    Vector_1ba270* p = (mgr->*fn)(&temp);
    r.x = p->x;
    r.y = p->y;
    r.z = p->z;
    if (out) {
        out->x = r.x;
        out->y = r.y;
        out->z = r.z;
    }
}
