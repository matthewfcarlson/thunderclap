#include "gen/global.h"

class CActorManager_2d040 {
  public:
    char Act(const char*, const char*);
};
class Function_2d040 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

template <> void Method2<CActorManager, bool, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d040 * obj = (CActorManager_2d040 *)__p0; const char ** args = (const char **)__p1; char * out = (char *)__p2;

    char (CActorManager_2d040::*f)(const char*, const char*) = (*(char (CActorManager_2d040::**)(const char *, const char *))&this->f_1c);
    const char* a = args[0];
    const char* b = args[1];
    char r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
