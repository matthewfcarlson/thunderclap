#include "gen/global.h"

struct Vec_2d330 {
    unsigned x, y, z;
};
class CActorManager_2d330 {
  public:
    int Act(Vec_2d330 v);
};
typedef int (CActorManager_2d330::*ActFn_2d330)(Vec_2d330);
class Function_2d330 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CActorManager, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d330 * obj = (CActorManager_2d330 *)__p0; Vec_2d330 * v = (Vec_2d330 *)__p1; unsigned int * out = (unsigned int *)__p2;

    ActFn_2d330 fn = (*(ActFn_2d330 *)&this->f_1c);
    int r = (obj->*fn)(*v);
    if (out)
        *out = r;
}
