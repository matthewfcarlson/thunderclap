#include "compat/ptr.h"
#include "gen/global.h"

class CSPManager_1e2790 {
  public:
    void Fn(int, float, float, float, float, int);
};
class Function_1e2790 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int, void*, int);
};

template <> void Closure6<CSPManager, void, int, float, float, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; void * arg = (void *)__p1; hulk_intptr y = (hulk_intptr)__p2;

    int* p = (int*)arg;
    int a = *p++;
    float b = *(float*)p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    float e = *(float*)p++;
    int f = *p++;
    ((*(CSPManager_1e2790 * *)&this->f_20)->*(*(void (CSPManager_1e2790::**)(int, float, float, float, float, int))&this->f_1c))(a, b, c, d, e, f);
}
