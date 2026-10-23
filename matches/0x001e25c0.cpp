#include "gen/global.h"

struct CSPManager_1e25c0 {
    bool Invoke(const char*, float, float, int);
};
class Function_1e25c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(void*, void*, void*);
};

template <> void Closure4<CSPManager, bool, const char *, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * p = (void *)__p1; void * out = (void *)__p2;

    CSPManager_1e25c0* o = (*(CSPManager_1e25c0 *volatile *)&this->f_20);
    bool (CSPManager_1e25c0::*f)(const char*, float, float, int) = (*(bool (CSPManager_1e25c0::**)(const char *, float, float, int))&this->f_1c);
    unsigned* a = (unsigned*)p;
    const char* s = (const char*)*a++;
    float x = *(float*)a++;
    float y = *(float*)a++;
    int n = *a++;
    bool r = (o->*f)(s, x, y, n);
    if (out)
        *(bool*)out = r;
}
