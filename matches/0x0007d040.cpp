// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_7d040 {
  public:
    void f();
};

template <> void Method0<CAmbientsManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_7d040 * a = (CActorManager_7d040 *)__p0;

    (a->*(*(void (CActorManager_7d040::**)())&this->f_1c))();
}
