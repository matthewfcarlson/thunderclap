#include "gen/global.h"

class CSPManager_1e1bd0 {
  public:
    void Fn(int, float, float, float, const char*);
};

template <> void Closure5<CSPManager, void, int, float, float, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; int * args = (int *)__p1; int other = (int)__p2;

    int a = *args++;
    float b = *(float*)args++;
    float c = *(float*)args++;
    float d = *(float*)args++;
    const char* e = (const char*)*args++;
    ((*(CSPManager_1e1bd0 * *)&this->f_20)->*(*(void (CSPManager_1e1bd0::**)(int, float, float, float, const char *))&this->f_1c))(a, b, c, d, e);
}
