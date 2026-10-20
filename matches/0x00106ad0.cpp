#include "gen/global.h"

class CPatrolPathManager_106ad0 {
  public:
    bool Find(const char*);
};
class Function_106ad0 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method1<CPatrolPathManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CPatrolPathManager_106ad0 * obj = (CPatrolPathManager_106ad0 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CPatrolPathManager_106ad0::*f)(const char*) = (*(bool (CPatrolPathManager_106ad0::**)(const char *))&this->f_1c);
    const char* x = *arg;
    bool r = (obj->*f)(x);
    if (out)
        *out = r;
}
