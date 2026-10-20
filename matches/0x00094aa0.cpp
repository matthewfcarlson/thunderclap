#include "gen/global.h"

struct CUnlockablesManager_94aa0 {
    char unused;
    int FUN_00094aa0(const char*);
};

template <> void Closure1<CUnlockablesManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; int * result = (int *)__p2;

    CUnlockablesManager_94aa0* obj = (*(CUnlockablesManager_94aa0 * *)&this->f_20);
    int (CUnlockablesManager_94aa0::*fn)(const char*) = (*(int (CUnlockablesManager_94aa0::**)(const char *))&this->f_1c);
    int value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}
