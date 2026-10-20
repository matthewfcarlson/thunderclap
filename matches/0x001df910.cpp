#include "gen/global.h"

class CSPManager_1df910 {
  public:
    bool fn(const char*, int);
};
struct Args {
    const char* s;
    int n;
};
class Function_1df910 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method2<CSPManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1df910 * obj = (CSPManager_1df910 *)__p0; Args * args = (Args *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1df910::*fn)(const char*, int) = (*(bool (CSPManager_1df910::**)(const char *, int))&this->f_1c);
    const char* s = args->s;
    int n = args->n;
    bool value = (obj->*fn)(s, n);
    if (out)
        *out = value;
}
