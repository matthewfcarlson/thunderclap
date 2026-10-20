#include "gen/global.h"

class CTriggerVolumeManager_1feaf0 {
  public:
    bool Fn(const char*, float);
};
class Function_1feaf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct Args {
    const char* s;
    float f;
};

template <> void Method2<CTriggerVolumeManager, bool, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1feaf0 * o = (CTriggerVolumeManager_1feaf0 *)__p0; Args * p = (Args *)__p1; bool * out = (bool *)__p2;

    bool (CTriggerVolumeManager_1feaf0::*f)(const char*, float) = (*(bool (CTriggerVolumeManager_1feaf0::**)(const char *, float))&this->f_1c);
    const char* s = p->s;
    float x = p->f;
    bool v = (o->*f)(s, x);
    if (out)
        *out = v;
}
