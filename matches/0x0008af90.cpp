// Same code shape as 0x0002ee10 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_8af90 {
  public:
    int act();
};

template <> void Closure0<CGameFlowManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_8af90* obj = (*(CActorManager_8af90 * *)&this->f_20);
    int (CActorManager_8af90::*fn)() = (*(int (CActorManager_8af90::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
