#include "gen/global.h"

struct CUnlockablesManager_94560 {};
struct Function_94560 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

template <> void Method4<CUnlockablesManager, void, const char *, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_94560 * object = (CUnlockablesManager_94560 *)__p0; const char ** args = (const char **)__p1; void * unused = (void *)__p2;

    const char* a = *args++;
    int b = *(const int*)args++;
    const char* c = *args++;
    const char* d = *args;
    (object->*(*(void (CUnlockablesManager_94560::**)(const char *, int, const char *, const char *))&this->f_1c))(a, b, c, d);
}
