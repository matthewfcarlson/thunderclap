#include "compat/ptr.h"
#include "gen/global.h"

class Function_1dfc90 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Pair_1dfc90 {
    int a;
    int b;
};
class CSPManager_1dfc90 {
  public:
    int Fn(int, int);
};

template <> void Method2<CSPManager, int, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; Pair_1dfc90 * p = (Pair_1dfc90 *)__p1; int * out = (int *)__p2;

    int (CSPManager_1dfc90::*fn)(int, int) = (*(int (CSPManager_1dfc90::**)(int, int))&this->f_1c);
    CSPManager_1dfc90* m = (CSPManager_1dfc90*)x;
    int a = p->a;
    int b = p->b;
    int r = (m->*fn)(a, b);
    if (out)
        *out = r;
}
