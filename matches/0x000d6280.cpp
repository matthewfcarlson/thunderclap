// Same code shape as 0x0002f820 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_d6280 {
  public:
    void run();
};

template <> void Closure0<MessageOverlay, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_d6280 * *)&this->f_20)->*(*(void (CActorManager_d6280::**)())&this->f_1c))();
}
