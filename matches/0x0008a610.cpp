#include "gen/global.h"

struct Vector_8a610 {
    int x, y, z;
};
class CGameFlowManager_8a610 {
  public:
    virtual Vector_8a610* Get(Vector_8a610*);
};
typedef Vector_8a610* (CGameFlowManager_8a610::*Fn_8a610)(Vector_8a610*);

template <> void Method0<CGameFlowManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_8a610 * mgr = (CGameFlowManager_8a610 *)__p0; Vector_8a610 * out = (Vector_8a610 *)__p2;

    Fn_8a610 fn = (*(Fn_8a610 *)&this->f_1c);
    Vector_8a610 temp;
    volatile Vector_8a610 r;
    Vector_8a610* p = (mgr->*fn)(&temp);
    r.x = p->x;
    r.y = p->y;
    r.z = p->z;
    if (out) {
        out->x = r.x;
        out->y = r.y;
        out->z = r.z;
    }
}
