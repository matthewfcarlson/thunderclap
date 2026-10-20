// Same code shape as 0x0002ebc0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class Function_9c800 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
void __cdecl invoke(int, hulk_intptr, hulk_intptr, int);

template <> void Closure7<CCameraManager, void, bool, bool, bool, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}
