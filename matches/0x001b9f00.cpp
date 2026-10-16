// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1b9f00 {
  public:
    void f();
};

template <> void Method0<CRenderManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9f00 * a = (CActorManager_1b9f00 *)__p0;

    (a->*(*(void (CActorManager_1b9f00::**)())&this->f_1c))();
}
