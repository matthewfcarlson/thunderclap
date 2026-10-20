#include "gen/global.h"

class HUDOverlay_cf030 {
  public:
    void Act(int, bool);
};
class Function_cf030 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method2<HUDOverlay, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cf030 * h = (HUDOverlay_cf030 *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    struct Args {
        int i;
        bool flag;
    };
    Args* p = (Args*)b;
    (h->*(*(void (HUDOverlay_cf030::**)(int, bool))&this->f_1c))(p->i, p->flag);
}
