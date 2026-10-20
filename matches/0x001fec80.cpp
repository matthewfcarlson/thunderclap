#include "gen/global.h"

class CTriggerVolumeManager_1fec80 {
  public:
    int invoke(const char*);
    typedef int (CTriggerVolumeManager_1fec80::*Method)(const char*);
    inline int Do(Method fn, const char* arg) { return (this->*fn)(arg); }
};
class Function_1fec80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager_1fec80*, const char**, int*) = 0;
};

template <> void Method1<CTriggerVolumeManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fec80 * obj = (CTriggerVolumeManager_1fec80 *)__p0; const char ** args = (const char **)__p1; int * result = (int *)__p2;

    CTriggerVolumeManager_1fec80::Method fn = (*(CTriggerVolumeManager_1fec80::Method *)&this->f_1c);
    int r = obj->Do(fn, *args);
    if (result)
        *result = r;
}
