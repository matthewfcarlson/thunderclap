// Same code shape as 0x000beac0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class CFEManager_93fe0 {
  public:
    void Call(const char*, int);
};
class Function_93fe0 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method2<CUnlockablesManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_93fe0* m = (CFEManager_93fe0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_93fe0::**)(const char *, int))&this->f_1c))(s, x);
}
