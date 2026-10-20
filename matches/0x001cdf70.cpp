#include "gen/global.h"

class CScenarioManager_1cdf70 {
  public:
    int SetState(int);
};
class Arg {
  public:
    int value;
};
class Function_1cdf70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(CScenarioManager_1cdf70*, Arg*, int*);
};

template <> void Method1<CScenarioManager,eMissionObjectiveState, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CScenarioManager_1cdf70 * obj = (CScenarioManager_1cdf70 *)__p0; Arg * arg = (Arg *)__p1; int * out = (int *)__p2;

    int (CScenarioManager_1cdf70::*fn)(int) = (*(int (CScenarioManager_1cdf70::**)(int))&this->f_1c);
    int v = arg->value;
    int r = (obj->*fn)(v);
    if (out)
        *out = r;
}
