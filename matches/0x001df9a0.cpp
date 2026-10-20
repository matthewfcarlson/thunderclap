#include "gen/global.h"

class CSPManager_1df9a0 {
  public:
    int method(const char*);
};
class Function_1df9a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};

template <> void Method1<CSPManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1df9a0 * obj = (CSPManager_1df9a0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CSPManager_1df9a0::*f)(const char*) = (*(int (CSPManager_1df9a0::**)(const char *))&this->f_1c);
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}
