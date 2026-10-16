// Same code shape as 0x0002d950 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1f4a90 {
  public:
    void f();
};

template <> void Method0<CSoundVoiceManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1f4a90 * a = (CActorManager_1f4a90 *)__p0;

    (a->*(*(void (CActorManager_1f4a90::**)())&this->f_1c))();
}
