// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_87270 {
  public:
    void f();
};

template <> void Method0<CGame, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_87270 * a = (CActorManager_87270 *)__p0;

    (a->*(*(void (CActorManager_87270::**)())&this->f_1c))();
}
