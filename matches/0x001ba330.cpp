// Same code shape as 0x000beac0 (propagated; names are from that function)
#include "gen/global.h"

class CFEManager_1ba330 {
  public:
    void Call(const char*, int);
};
class Function_1ba330 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method2<CRenderManager, void, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; int n = (int)__p2;

    CFEManager_1ba330* m = (CFEManager_1ba330*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1ba330::**)(const char *, int))&this->f_1c))(s, x);
}
