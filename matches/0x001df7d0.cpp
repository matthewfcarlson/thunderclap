#include "gen/global.h"

class CSPManager_1df7d0 {
  public:
    bool invoke(const char*, int, int);
};
struct Args_1df7d0 {
    const char* a;
    int b;
    int c;
};

template <> void Method3<CSPManager, bool, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1df7d0 * obj = (CSPManager_1df7d0 *)__p0; Args_1df7d0 * args = (Args_1df7d0 *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1df7d0::*fn)(const char*, int, int) = (*(bool (CSPManager_1df7d0::**)(const char *, int, int))&this->f_1c);
    const char* a = args->a;
    int b = args->b;
    int c = args->c;
    bool r = (obj->*fn)(a, b, c);
    if (out)
        *out = r;
}
