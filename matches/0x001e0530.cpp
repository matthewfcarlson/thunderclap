#include "gen/global.h"

class CSPManager_1e0530 {
  public:
    bool fn(const char*);
};
class Function_1e0530 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

template <> void Method1<CSPManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0530 * obj = (CSPManager_1e0530 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1e0530::*f)(const char*) = (*(bool (CSPManager_1e0530::**)(const char *))&this->f_1c);
    const char* a = *arg;
    bool r = (obj->*f)(a);
    if (out)
        *out = r;
}
