#include "gen/global.h"

namespace math {
struct Vector_cedb0 {
    float x, y, z;
};
} // namespace math
class HUDOverlay_cedb0 {
  public:
    int go(int, math::Vector_cedb0);
};
class Function_cedb0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

template <> void Method2<HUDOverlay, int, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cedb0 * obj = (HUDOverlay_cedb0 *)__p0; int * args = (int *)__p1; int * out = (int *)__p2;

    int (HUDOverlay_cedb0::*call)(int, math::Vector_cedb0) = (*(int (HUDOverlay_cedb0::**)(int, math::Vector_cedb0))&this->f_1c);
    int a = *args;
    math::Vector_cedb0 v = *(math::Vector_cedb0*)++args;
    int r = (obj->*call)(a, v);
    if (out)
        *out = r;
}
