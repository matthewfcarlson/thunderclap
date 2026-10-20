#include "gen/global.h"

struct CUnlockablesManager_94bb0 {
    char dummy;
};
struct Arguments {
    const char* first;
    int second;
    const char* third;
    const char* fourth;
};

template <> void Closure4<CUnlockablesManager, void, const char *, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * arguments = (const Arguments *)__p1;

    const char** p = (const char**)arguments;
    const char* a = *p++;
    int b = *(int*)p++;
    const char* c = *p++;
    const char* d = *p++;
    ((*(CUnlockablesManager_94bb0 * *)&this->f_20)->*(*(void (CUnlockablesManager_94bb0::**)(const char *, int, const char *, const char *))&this->f_1c))(a, b, c, d);
}
