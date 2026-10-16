// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_8a8e0 {
  public:
    void f();
};

template <> void Method0<CGameFlowManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_8a8e0 * a = (CActorManager_8a8e0 *)__p0;

    (a->*(*(void (CActorManager_8a8e0::**)())&this->f_1c))();
}
