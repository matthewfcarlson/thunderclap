#include "gen/global.h"

struct CWorldStreamManager_2053f0 {};
struct Function_2053f0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CWorldStreamManager, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_2053f0 * manager = (CWorldStreamManager_2053f0 *)__p0; int * input = (int *)__p1; int * result = (int *)__p2;

    int (CWorldStreamManager_2053f0::*fn)(int) = (*(int (CWorldStreamManager_2053f0::**)(int))&this->f_1c);
    int arg = *input;
    int value = (manager->*fn)(arg);
    if (result)
        *result = value;
}
