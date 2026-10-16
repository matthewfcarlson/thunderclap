// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1edbe0 {
  public:
    void f();
};

template <> void Method0<CSoundRealTimeManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1edbe0 * a = (CActorManager_1edbe0 *)__p0;

    (a->*(*(void (CActorManager_1edbe0::**)())&this->f_1c))();
}
