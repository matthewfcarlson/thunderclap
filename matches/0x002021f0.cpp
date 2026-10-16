#include "gen/global.h"

struct Vector_2021f0 {
    float x, y, z;
};
class CWorldCollisionManager_2021f0 {
  public:
    Vector_2021f0 Do(Vector_2021f0);
};
typedef Vector_2021f0 (CWorldCollisionManager_2021f0::*Method_2021f0)(Vector_2021f0);
class Function_2021f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
inline Vector_2021f0 Copy(const Vector_2021f0& v) {
    Vector_2021f0 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    return r;
}

template <> void Method1<CWorldCollisionManager,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldCollisionManager_2021f0 * obj = (CWorldCollisionManager_2021f0 *)__p0; const Vector_2021f0 * arg = (const Vector_2021f0 *)__p1; Vector_2021f0 * out = (Vector_2021f0 *)__p2;

    Method_2021f0 m = (*(Method_2021f0 *)&this->f_1c);
    Vector_2021f0 v = Copy((obj->*m)(*arg));
    if (out)
        *out = v;
}
