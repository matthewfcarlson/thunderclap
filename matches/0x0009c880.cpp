// Same code shape as 0x0002f820 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_9c880 {
  public:
    void run();
};

template <> void Closure0<CCameraManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_9c880 * *)&this->f_20)->*(*(void (CActorManager_9c880::**)())&this->f_1c))();
}
