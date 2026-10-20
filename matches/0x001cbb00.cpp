#include "gen/global.h"

class CEventManager_1cbb00 {
  public:
    bool Test(const char*);
};
class Function_1cbb00 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method1<CEventManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEventManager_1cbb00 * obj = (CEventManager_1cbb00 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CEventManager_1cbb00::*f)(const char*) = (*(bool (CEventManager_1cbb00::**)(const char *))&this->f_1c);
    const char* value = *arg;
    bool r = (obj->*f)(value);
    if (out)
        *out = r;
}
