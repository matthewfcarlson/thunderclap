#include "gen/global.h"

class CSPManager_1dfd30 {
  public:
    int Fn(const char*, const char*);
};
struct Pair {
    const char* a;
    const char* b;
};
class Function_1dfd30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

template <> void Method2<CSPManager, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1dfd30 * o = (CSPManager_1dfd30 *)__p0; Pair * p = (Pair *)__p1; int * out = (int *)__p2;

    int (CSPManager_1dfd30::*fn)(const char*, const char*) = (*(int (CSPManager_1dfd30::**)(const char *, const char *))&this->f_1c);
    const char* a = p->a;
    const char* b = p->b;
    int r = (o->*fn)(a, b);
    if (out)
        *out = r;
}
