#include "gen/global.h"

class CSPManager_1e0c80 {
  public:
    bool Invoke(const char*, float);
};
struct Args {
    const char* name;
    float val;
};
class Function_1e0c80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager_1e0c80*, Args*, bool*);
};

template <> void Method2<CSPManager, bool, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0c80 * obj = (CSPManager_1e0c80 *)__p0; Args * a = (Args *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1e0c80::*fn)(const char*, float) = (*(bool (CSPManager_1e0c80::**)(const char *, float))&this->f_1c);
    const char* name = a->name;
    float val = a->val;
    bool result = (obj->*fn)(name, val);
    if (out)
        *out = result;
}
