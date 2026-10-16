// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_b01d0 {
  public:
    void f();
};

template <> void Method0<CHapticControllerManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_b01d0 * a = (CActorManager_b01d0 *)__p0;

    (a->*(*(void (CActorManager_b01d0::**)())&this->f_1c))();
}
