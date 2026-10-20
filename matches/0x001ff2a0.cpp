#include "gen/global.h"

class CTriggerVolumeManager_1ff2a0 {
  public:
    int Invoke(const char*);
};
class Function_1ff2a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager_1ff2a0*, const char**, int*);
};

template <> void Method1<CTriggerVolumeManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff2a0 * obj = (CTriggerVolumeManager_1ff2a0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CTriggerVolumeManager_1ff2a0::*f)(const char*) = (*(int (CTriggerVolumeManager_1ff2a0::**)(const char *))&this->f_1c);
    const char* s = *arg;
    int r = (obj->*f)(s);
    if (out)
        *out = r;
}
