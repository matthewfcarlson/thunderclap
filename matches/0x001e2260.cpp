#include "gen/global.h"

class CSPManager_1e2260 {
  public:
    bool invoke(float, float, float, float);
};
class Function_1e2260 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, float*, bool*);
};

template <> void Closure4<CSPManager, bool, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { float * a = (float *)__p1; bool * result = (bool *)__p2;

    CSPManager_1e2260* o = (*(CSPManager_1e2260 * *)&this->f_20);
    bool (CSPManager_1e2260::*m)(float, float, float, float) = (*(bool (CSPManager_1e2260::**)(float, float, float, float))&this->f_1c);
    float v0 = *a++;
    float v1 = *a++;
    float v2 = *a++;
    float v3 = *a++;
    bool r = (o->*m)(v0, v1, v2, v3);
    if (result)
        *result = r;
}
