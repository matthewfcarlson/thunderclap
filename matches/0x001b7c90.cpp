#include "gen/global.h"

class CFMVManager_1b7c90 {
  public:
    void Fn(float, float, float, float);
};
class Function_1b7c90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CFMVManager_1b7c90*, float*, void*);
};

template <> void Method4<CFMVManager, void, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CFMVManager_1b7c90 * obj = (CFMVManager_1b7c90 *)__p0; float * p = (float *)__p1; void * b = (void *)__p2;

    float f0 = *p++;
    float f1 = *p++;
    (obj->*(*(void (CFMVManager_1b7c90::**)(float, float, float, float))&this->f_1c))(f0, f1, p[0], p[1]);
}
