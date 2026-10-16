// Same code shape as 0x0002f820 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_8b4a0 {
  public:
    void run();
};

template <> void Closure0<CGameFlowManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_8b4a0 * *)&this->f_20)->*(*(void (CActorManager_8b4a0::**)())&this->f_1c))();
}
