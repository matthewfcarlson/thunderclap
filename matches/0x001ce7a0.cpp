#include "gen/global.h"

class CScenarioManager_1ce7a0 {
  public:
    int run(const char*);
};
class Function_1ce7a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, int*);
};
class Method1_1ce7a0 : public Function_1ce7a0 {
  public:
    char pad[0x18];
    int (CScenarioManager_1ce7a0::*fn)(const char*);
    CScenarioManager_1ce7a0* obj;
};

template <> void Closure1<CScenarioManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * args = (void *)__p1; int * out = (int *)__p2;

    CScenarioManager_1ce7a0* o = (*(CScenarioManager_1ce7a0 * *)&this->f_20);
    int (CScenarioManager_1ce7a0::*f)(const char*) = (*(int (CScenarioManager_1ce7a0::**)(const char *))&this->f_1c);
    int r = (o->*f)(*(const char**)args);
    if (out)
        *out = r;
}
