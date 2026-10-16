#include "gen/global.h"

class CSPManager_1e1ef0 {
  public:
    void Fn(const char*, int, float, float, float, float);
};

template <> void Closure6<CSPManager, void, const char *, int, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const unsigned int * p = (const unsigned int *)__p1;

    const char* a = (const char*)*p++;
    int b = *p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    float e = *(float*)p++;
    float f = *(float*)p++;
    ((*(CSPManager_1e1ef0 * *)&this->f_20)->*(*(void (CSPManager_1e1ef0::**)(const char *, int, float, float, float, float))&this->f_1c))(a, b, c, d, e, f);
}
