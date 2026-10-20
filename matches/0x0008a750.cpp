#include "gen/global.h"

class CGameFlowManager_8a750 {
  public:
    bool Invoke(const char*);
};
class Function_8a750 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method1<CGameFlowManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_8a750 * obj = (CGameFlowManager_8a750 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CGameFlowManager_8a750::*f)(const char*) = (*(bool (CGameFlowManager_8a750::**)(const char *))&this->f_1c);
    const char* value = *arg;
    bool r = (obj->*f)(value);
    if (out)
        *out = r;
}
