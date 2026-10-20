// Same code shape as 0x000beac0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class CFEManager_1edf40 {
  public:
    void Call(const char*, int);
};
class Function_1edf40 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method2<CSoundSimManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1edf40* m = (CFEManager_1edf40*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1edf40::**)(const char *, int))&this->f_1c))(s, x);
}
