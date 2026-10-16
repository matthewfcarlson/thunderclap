// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_9aff0 {
  public:
    void f();
};

template <> void Method0<CCameraManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_9aff0 * a = (CActorManager_9aff0 *)__p0;

    (a->*(*(void (CActorManager_9aff0::**)())&this->f_1c))();
}
