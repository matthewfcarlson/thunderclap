#include "gen/global.h"

class CWorldStreamManager_205360 {
  public:
    int Invoke(int, int);
};
struct Args {
    int a, b;
};
class Function_205360 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method2<CWorldStreamManager, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205360 * obj = (CWorldStreamManager_205360 *)__p0; Args * args = (Args *)__p1; int * result = (int *)__p2;

    int (CWorldStreamManager_205360::*fn)(int, int) = (*(int (CWorldStreamManager_205360::**)(int, int))&this->f_1c);
    int a = args->a;
    int b = args->b;
    int value = (obj->*fn)(a, b);
    if (result)
        *result = value;
}
