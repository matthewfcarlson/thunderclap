#include "gen/global.h"

struct Vector_1e1cf0 {
    float x, y, z;
    Vector_1e1cf0() {}
    Vector_1e1cf0(const Vector_1e1cf0& v) : x(v.x), y(v.y), z(v.z) {}
};
class CSPManager_1e1cf0 {
  public:
    Vector_1e1cf0 method(const char*);
};
class Function_1e1cf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(void*, const char**, Vector_1e1cf0*);
};

template <> void Closure1<CSPManager,math::Vector, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** name = (const char **)__p1; Vector_1e1cf0 * out = (Vector_1e1cf0 *)__p2;

    CSPManager_1e1cf0* p = (*(CSPManager_1e1cf0 * *)&this->f_20);
    Vector_1e1cf0 (CSPManager_1e1cf0::*f)(const char*) = (*(Vector_1e1cf0 (CSPManager_1e1cf0::**)(const char *))&this->f_1c);
    Vector_1e1cf0 value = (p->*f)(*name);
    if (out)
        *out = value;
}
