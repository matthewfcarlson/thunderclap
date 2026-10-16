// Same code shape as 0x0002ee10 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_d7490 {
  public:
    int act();
};

template <> void Closure0<CSimOverlayManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_d7490* obj = (*(CActorManager_d7490 * *)&this->f_20);
    int (CActorManager_d7490::*fn)() = (*(int (CActorManager_d7490::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
