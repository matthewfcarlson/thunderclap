#include "gen/global.h"

namespace math {
struct Vector_cf0e0 {
    float x, y, z;
};
} // namespace math
class HUDOverlay_cf0e0 {
  public:
    int x;
};
typedef int (HUDOverlay_cf0e0::*Fn_cf0e0)(int, int, math::Vector_cf0e0, math::Vector_cf0e0);
template <class T> inline T Pop(char*& p) {
    T v = *(T*)p;
    p += sizeof(T);
    return v;
}
class Function_cf0e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(HUDOverlay_cf0e0* o, char* a, int* out);
    int pad[5];
};

template <> void Method4<HUDOverlay, int, int, int,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cf0e0 * o = (HUDOverlay_cf0e0 *)__p0; char * args = (char *)__p1; int * out = (int *)__p2;

    Fn_cf0e0 fn = (*(Fn_cf0e0 *)&this->f_1c);
    char* p = args;
    int a1 = Pop<int>(p);
    int a2 = Pop<int>(p);
    math::Vector_cf0e0 a3 = Pop<math::Vector_cf0e0>(p);
    math::Vector_cf0e0 a4 = Pop<math::Vector_cf0e0>(p);
    int r = (o->*fn)(a1, a2, a3, a4);
    if (out)
        *out = r;
}
