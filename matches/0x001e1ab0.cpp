#include "gen/global.h"

class CSPManager_1e1ab0 {
  public:
    bool invoke(const char*, const char*, int, float, const char*);
};
class Function_1e1ab0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*, void*);
};

template <> void Closure5<CSPManager, bool, const char *, const char *, int, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * args = (void *)__p1; void * result = (void *)__p2;

    CSPManager_1e1ab0* p = (*(CSPManager_1e1ab0 * *)&this->f_20);
    bool (CSPManager_1e1ab0::*method)(const char*, const char*, int, float, const char*) = (*(bool (CSPManager_1e1ab0::**)(const char *, const char *, int, float, const char *))&this->f_1c);
    void** a = (void**)args;
    const char* s1 = (const char*)*a++;
    const char* s2 = (const char*)*a++;
    int n = (int)*a++;
    float v = *(float*)a++;
    const char* s3 = (const char*)*a;
    bool r = (p->*method)(s1, s2, n, v, s3);
    if (result)
        *(bool*)result = r;
}
