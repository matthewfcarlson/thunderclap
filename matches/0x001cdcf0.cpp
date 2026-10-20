// Same code shape as 0x000beac0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class CFEManager_1cdcf0 {
  public:
    void Call(const char*, int);
};
class Function_1cdcf0 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method2<CScenarioManager, void, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1cdcf0* m = (CFEManager_1cdcf0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1cdcf0::**)(const char *, int))&this->f_1c))(s, x);
}
