// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_d5800 {
  public:
    void f();
};

template <> void Method0<MessageOverlay, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_d5800 * a = (CActorManager_d5800 *)__p0;

    (a->*(*(void (CActorManager_d5800::**)())&this->f_1c))();
}
