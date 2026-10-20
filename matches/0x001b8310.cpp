#include "gen/global.h"

class CFMVManager_1b8310 {
  public:
    void Run(float, float, float, float);
};
class Function_1b8310 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const float*, void*);
};

template <> void Closure4<CFMVManager, void, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const float * p = (const float *)__p1; void * b = (void *)__p2;

    volatile int x = *(int*)p++;
    volatile int y = *(int*)p++;
    ((*(CFMVManager_1b8310 * *)&this->f_20)->*(*(void (CFMVManager_1b8310::**)(float, float, float, float))&this->f_1c))(*(float*)&x, *(float*)&y, *p, *(p + 1));
}
