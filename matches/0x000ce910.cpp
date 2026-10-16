// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_ce910 {
  public:
    void f();
};

template <> void Method0<HUDOverlay, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_ce910 * a = (CActorManager_ce910 *)__p0;

    (a->*(*(void (CActorManager_ce910::**)())&this->f_1c))();
}
