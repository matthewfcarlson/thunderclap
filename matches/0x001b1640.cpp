#include "gen/global.h"

class Function_1b1640 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Function2<void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int x = (int)__p0; unsigned int * p = (unsigned int *)__p1; int y = (int)__p2;

    (*(void (**)(float, float))&this->f_1c)(*(float*)p, *((float*)p + 1));
}
