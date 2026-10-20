#include "gen/global.h"

struct CStatsManager_91160 {
    int invoke(const char*);
};
typedef int (CStatsManager_91160::*StatsMethod)(const char*);

template <> void Closure1<CStatsManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; int * result = (int *)__p2;

    CStatsManager_91160* obj = (*(CStatsManager_91160 * *)&this->f_20);
    StatsMethod fn = (*(StatsMethod *)&this->f_1c);
    int value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}
