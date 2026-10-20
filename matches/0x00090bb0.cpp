#include "gen/global.h"

class CStatsManager_90bb0 {
  public:
    int Get(const char*);
};
typedef int (CStatsManager_90bb0::*StatsFn)(const char*);
class Function_90bb0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

template <> void Method1<CStatsManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CStatsManager_90bb0 * obj = (CStatsManager_90bb0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    StatsFn f = (*(StatsFn *)&this->f_1c);
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}
