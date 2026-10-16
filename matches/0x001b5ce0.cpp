#include "gen/global.h"

struct Vec_1b5ce0 {
    float x, y, z;
};
struct VecI {
    float x, y, z;
    int i;
};
class Callee_1b5ce0 {
  public:
    bool Call(Vec_1b5ce0 v, int i);
};
typedef bool (Callee_1b5ce0::*Fn_1b5ce0)(Vec_1b5ce0, int);

template <> void Method2<CCollisionManager, bool,math::Vector, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Callee_1b5ce0 * a = (Callee_1b5ce0 *)__p0; VecI * p = (VecI *)__p1; char * out = (char *)__p2;

    Fn_1b5ce0 f = (*(Fn_1b5ce0 *)&this->f_1c);
    bool r = (a->*f)(*(Vec_1b5ce0*)p, p->i);
    if (out)
        *out = r;
}
