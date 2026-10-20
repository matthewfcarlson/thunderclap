#include "compat/ptr.h"
#include "gen/global.h"

class CCollisionManager_1b5c40 {
  public:
    void Run(float, float, float);
};
class Function_1b5c40 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CCollisionManager_1b5c40*, float*, int);
};

template <> void Method3<CCollisionManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCollisionManager_1b5c40 * obj = (CCollisionManager_1b5c40 *)__p0; float * args = (float *)__p1; hulk_intptr unused = (hulk_intptr)__p2;

    float* p = args;
    *(volatile int*)&args = *(int*)p;
    (obj->*(*(void (CCollisionManager_1b5c40::**)(float, float, float))&this->f_1c))(*(float*)&args, p[1], p[2]);
}
