#include "gen/global.h"

class Function_7cfc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CAmbientsManager_7cfc0 {
  public:
    void invoke(const char*, bool);
};

template <> void Method2<CAmbientsManager, void, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7cfc0 * obj = (CAmbientsManager_7cfc0 *)__p0; void * args = (void *)__p1; void * unused = (void *)__p2;

    struct Args {
        const char* s;
        bool b;
    };
    Args* a = (Args*)args;
    (obj->*(*(void (CAmbientsManager_7cfc0::**)(const char *, bool))&this->f_1c))(a->s, a->b);
}
