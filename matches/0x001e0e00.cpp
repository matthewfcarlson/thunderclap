#include "gen/global.h"

class CSPManager_1e0e00 {
  public:
    void* Get(const char*);
};
class Function_1e0e00 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method1<CSPManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0e00 * a = (CSPManager_1e0e00 *)__p0; const char ** b = (const char **)__p1; void ** out = (void **)__p2;

    void* (CSPManager_1e0e00::*f)(const char*) = (*(void *(CSPManager_1e0e00::**)(const char *))&this->f_1c);
    const char* arg = *b;
    void* result = (a->*f)(arg);
    if (out)
        *out = result;
}
