// Same code shape as 0x0008a610 (propagated; names are from that function)
#include "gen/global.h"

struct Vector_9b450 {
    int x, y, z;
};
class CGameFlowManager_9b450 {
  public:
    virtual Vector_9b450* Get(Vector_9b450*);
};
typedef Vector_9b450* (CGameFlowManager_9b450::*Fn_9b450)(Vector_9b450*);

template <> void Method0<CCameraManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_9b450 * mgr = (CGameFlowManager_9b450 *)__p0; Vector_9b450 * out = (Vector_9b450 *)__p2;

    Fn_9b450 fn = (*(Fn_9b450 *)&this->f_1c);
    Vector_9b450 temp;
    volatile Vector_9b450 r;
    Vector_9b450* p = (mgr->*fn)(&temp);
    r.x = p->x;
    r.y = p->y;
    r.z = p->z;
    if (out) {
        out->x = r.x;
        out->y = r.y;
        out->z = r.z;
    }
}
