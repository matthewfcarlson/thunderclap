#include "gen/global.h"

namespace math {
struct Vector_7d410 {
    float x, y, z;
};
} // namespace math
struct CAmbientsManager_7d410 {
    void f(const char*, int, const math::Vector_7d410, const math::Vector_7d410);
};
struct Function_7d410 {
    virtual void v0();
    virtual void v1();
};

template <> void Method4<CAmbientsManager, void, const char *, int, const ::math::Vector, const ::math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7d410 * o = (CAmbientsManager_7d410 *)__p0; char * a = (char *)__p1; int u = (int)__p2;

    char* p = a;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector_7d410 va = *(math::Vector_7d410*)p;
    p += 12;
    math::Vector_7d410 vb = *(math::Vector_7d410*)p;
    (o->*(*(void (CAmbientsManager_7d410::**)(const char *, int, const math::Vector_7d410, const math::Vector_7d410))&this->f_1c))(s, i, va, vb);
}
