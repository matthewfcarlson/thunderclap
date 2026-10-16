#include "gen/global.h"

class Function_2ebc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
void __cdecl invoke(int, int, int, int);

template <> void Closure7<CActorManager, bool, const char *,math::Vector, float, const char *, const char *, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int x = (int)__p0; int y = (int)__p1; int z = (int)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}
