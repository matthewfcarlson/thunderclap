// Same code shape as 0x0002ee10 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_205e10 {
  public:
    int act();
};

template <> void Closure0<CWorldStreamManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_205e10* obj = (*(CActorManager_205e10 * *)&this->f_20);
    int (CActorManager_205e10::*fn)() = (*(int (CActorManager_205e10::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
