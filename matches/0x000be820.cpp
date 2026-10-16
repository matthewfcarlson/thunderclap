// Same code shape as 0x000beac0 (propagated; names are from that function)
#include "gen/global.h"

class CFEManager_be820 {
  public:
    void Call(const char*, int);
};
class Function_be820 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method2<CFEManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; int n = (int)__p2;

    CFEManager_be820* m = (CFEManager_be820*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_be820::**)(const char *, int))&this->f_1c))(s, x);
}
