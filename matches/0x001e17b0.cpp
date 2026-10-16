// Same code shape as 0x0002ebc0 (propagated; names are from that function)
#include "gen/global.h"

class Function_1e17b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
void __cdecl invoke(int, int, int, int);

template <> void Closure6<CSPManager, void, const char *, const char *, int, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { int x = (int)__p0; int y = (int)__p1; int z = (int)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}
