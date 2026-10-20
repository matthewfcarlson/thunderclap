#include "gen/global.h"

class CScenarioManager_1cdc50 {
  public:
    int method(float, const char*);
};
struct Args {
    float a;
    const char* b;
};
class Function_1cdc50 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method2<CScenarioManager, int, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CScenarioManager_1cdc50 * obj = (CScenarioManager_1cdc50 *)__p0; Args * args = (Args *)__p1; int * result = (int *)__p2;

    int (CScenarioManager_1cdc50::*f)(float, const char*) = (*(int (CScenarioManager_1cdc50::**)(float, const char *))&this->f_1c);
    float a = args->a;
    const char* b = args->b;
    int r = (obj->*f)(a, b);
    if (result)
        *result = r;
}
