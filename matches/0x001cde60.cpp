#include "gen/global.h"

class CScenarioManager_1cde60 {
  public:
    int Run(const char*);
};
class Function_1cde60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

template <> void Method1<CScenarioManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CScenarioManager_1cde60 * obj = (CScenarioManager_1cde60 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CScenarioManager_1cde60::*f)(const char*) = (*(int (CScenarioManager_1cde60::**)(const char *))&this->f_1c);
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}
