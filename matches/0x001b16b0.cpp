// Same code shape as 0x001b1640 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class Function_1b16b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Function2<void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; unsigned int * p = (unsigned int *)__p1; hulk_intptr y = (hulk_intptr)__p2;

    (*(void (**)(float, float))&this->f_1c)(*(float*)p, *((float*)p + 1));
}
