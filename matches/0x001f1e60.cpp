// Same code shape as 0x0002f820 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1f1e60 {
  public:
    void run();
};

template <> void Closure0<CSoundSystem, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_1f1e60 * *)&this->f_20)->*(*(void (CActorManager_1f1e60::**)())&this->f_1c))();
}
