#include "gen/global.h"

class CActorManager_2c7f0 {
  public:
    bool action(const char*);
};
class Function_2c7f0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager_2c7f0*, const char**, bool*);
};

template <> void Method1<CActorManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c7f0 * obj = (CActorManager_2c7f0 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_2c7f0::*fn)(const char*) = (*(bool (CActorManager_2c7f0::**)(const char *))&this->f_1c);
    const char* val = *arg;
    bool r = (obj->*fn)(val);
    if (out)
        *out = r;
}
