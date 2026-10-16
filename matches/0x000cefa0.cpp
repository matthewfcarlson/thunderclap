#include "gen/global.h"

class Function_cefa0 {
  public:
    virtual void f0();
    virtual void f1();
};
class HUDOverlay_cefa0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void run(unsigned char, float);
};

template <> void Method2<HUDOverlay, void, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * p = (void *)__p1; void * c = (void *)__p2;

    HUDOverlay_cefa0* h = (HUDOverlay_cefa0*)a;
    (h->*(*(void (HUDOverlay_cefa0::**)(unsigned char, float))&this->f_1c))(*(unsigned char*)p, *(float*)((char*)p + 4));
}
