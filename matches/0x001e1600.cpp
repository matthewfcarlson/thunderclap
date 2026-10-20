#include "gen/global.h"

class CSPManager_1e1600 {
  public:
    int Fn(const char*);
};
class Function_1e1600 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

template <> void Closure1<CSPManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    CSPManager_1e1600* o = (*(CSPManager_1e1600 * *)&this->f_20);
    int (CSPManager_1e1600::*f)(const char*) = (*(int (CSPManager_1e1600::**)(const char *))&this->f_1c);
    int r = (o->*f)(*arg);
    if (out)
        *out = r;
}
