#include "gen/global.h"

struct CStatsManager_90d50 {
    int FUN_00090d50(const char*);
};
struct Function_90d50 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CStatsManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CStatsManager_90d50 * manager = (CStatsManager_90d50 *)__p0; const char ** argument = (const char **)__p1; int * result = (int *)__p2;

    int (CStatsManager_90d50::*fn)(const char*) = (*(int (CStatsManager_90d50::**)(const char *))&this->f_1c);
    const char* arg = *argument;
    int value = (manager->*fn)(arg);
    if (result)
        *result = value;
}
