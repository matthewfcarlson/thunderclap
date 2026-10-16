// Same code shape as 0x0002ee10 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_c0300 {
  public:
    int act();
};

template <> void Closure0<CFEManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_c0300* obj = (*(CActorManager_c0300 * *)&this->f_20);
    int (CActorManager_c0300::*fn)() = (*(int (CActorManager_c0300::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
