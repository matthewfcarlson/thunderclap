#include "gen/global.h"

class CTriggerVolumeManager_1feb80 {
  public:
    bool Run(const char*);
};
class Function_1feb80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};

template <> void Method1<CTriggerVolumeManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1feb80 * obj = (CTriggerVolumeManager_1feb80 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CTriggerVolumeManager_1feb80::*f)(const char*) = (*(bool (CTriggerVolumeManager_1feb80::**)(const char *))&this->f_1c);
    const char* s = *arg;
    bool r = (obj->*f)(s);
    if (out)
        *out = r;
}
