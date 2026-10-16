#include "gen/global.h"

class CActorManager_2ffa0 {
  public:
    virtual float f(const char*, const char*);
};

template <> void Closure2<CActorManager, float, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned int * x = (unsigned int *)__p0; unsigned int * args = (unsigned int *)__p1; float * out = (float *)__p2;

    CActorManager_2ffa0* o = (*(CActorManager_2ffa0 * *)&this->f_20);
    float (CActorManager_2ffa0::*fn)(const char*, const char*) = (*(float (CActorManager_2ffa0::**)(const char *, const char *))&this->f_1c);
    const char* a = (const char*)args[0];
    const char* b = (const char*)args[1];
    float r = (o->*fn)(a, b);
    if (out)
        *out = r;
}
