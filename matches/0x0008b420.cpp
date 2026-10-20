#include "gen/global.h"

struct CGameFlowManager_8b420 {};
struct Function_8b420 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Closure1<CGameFlowManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; const char ** result = (const char **)__p2;

    CGameFlowManager_8b420* obj = (*(CGameFlowManager_8b420 * *)&this->f_20);
    const char* (CGameFlowManager_8b420::*fn)(const char*) = (*(const char *(CGameFlowManager_8b420::**)(const char *))&this->f_1c);
    const char* value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}
