#include "gen/global.h"

class CActorManager_2ee10 {
  public:
    int act();
};

template <> void Closure0<CActorManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_2ee10* obj = (*(CActorManager_2ee10 * *)&this->f_20);
    int (CActorManager_2ee10::*fn)() = (*(int (CActorManager_2ee10::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
