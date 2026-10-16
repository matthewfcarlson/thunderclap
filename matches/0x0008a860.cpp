#include "gen/global.h"

class CGameFlowManager_8a860;
class CGameFlowManager_8a860 {
  public:
    const char* Get(const char* s);
};
typedef const char* (CGameFlowManager_8a860::*Fn_8a860)(const char*);
struct Function_8a860 {
    virtual void f0();
    virtual void f1();
};

template <> void Method1<CGameFlowManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_8a860 * a = (CGameFlowManager_8a860 *)__p0; const char ** p = (const char **)__p1; const char ** out = (const char **)__p2;

    Fn_8a860 f = (*(Fn_8a860 *)&this->f_1c);
    const char* s = *p;
    const char* x = (a->*f)(s);
    if (out)
        *out = x;
}
