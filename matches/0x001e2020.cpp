#include "gen/global.h"

class CSPManager_1e2020 {
  public:
    void Act(const char*, const char*, float, float, float);
};
class Function_1e2020 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

template <> void Closure5<CSPManager, void, const char *, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    char* p = (char*)b;
    const char* x = *(const char**)p;
    p += 4;
    const char* y = *(const char**)p;
    p += 4;
    float z = *(float*)p;
    p += 4;
    float w = *(float*)p;
    p += 4;
    float v = *(float*)p;
    ((*(CSPManager_1e2020 * *)&this->f_20)->*(*(void (CSPManager_1e2020::**)(const char *, const char *, float, float, float))&this->f_1c))(x, y, z, w, v);
}
