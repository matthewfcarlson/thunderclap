// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_be720 {
  public:
    void f();
};

template <> void Method0<CFEManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_be720 * a = (CActorManager_be720 *)__p0;

    (a->*(*(void (CActorManager_be720::**)())&this->f_1c))();
}
