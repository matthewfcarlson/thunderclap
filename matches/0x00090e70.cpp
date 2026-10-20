#include "compat/ptr.h"
#include "gen/global.h"

class CStatsManager_90e70 {
  public:
    void Action(const char*, const char*, int, int, int, int);
};

template <> void Closure6<CStatsManager, void, const char *, const char *, int, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const int * args = (const int *)__p1;

    const int* p = args;
    hulk_intptr a = *p++;
    hulk_intptr b = *p++;
    int c = *p++;
    int d = *p++;
    int e = *p++;
    int f = *p++;
    ((*(CStatsManager_90e70 * *)&this->f_20)->*(*(void (CStatsManager_90e70::**)(const char *, const char *, int, int, int, int))&this->f_1c))((const char*)a, (const char*)b, c, d, e, f);
}
