#include "gen/global.h"

namespace math {
struct Vector_1e07a0 {
    float x, y, z;
};
} // namespace math
struct CAmbientsManager_1e07a0 {
    void f(const char*, int, const math::Vector_1e07a0, const math::Vector_1e07a0);
};
struct Function_1e07a0 {
    virtual void v0();
    virtual void v1();
};

template <> void Method4<CSPManager, void, const char *, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_1e07a0 * o = (CAmbientsManager_1e07a0 *)__p0; char * a = (char *)__p1; int u = (int)__p2;

    char* p = a;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector_1e07a0 va = *(math::Vector_1e07a0*)p;
    p += 12;
    math::Vector_1e07a0 vb = *(math::Vector_1e07a0*)p;
    (o->*(*(void (CAmbientsManager_1e07a0::**)(const char *, int, const math::Vector_1e07a0, const math::Vector_1e07a0))&this->f_1c))(s, i, va, vb);
}
