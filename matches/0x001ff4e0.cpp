#include "gen/global.h"

class CTriggerVolumeManager_1ff4e0 {
  public:
    void* Fn(const char*);
    inline void* Invoke(void* (CTriggerVolumeManager_1ff4e0::*fn)(const char*), const char* arg) {
        return (this->*fn)(arg);
    }
};
class Function_1ff4e0 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method1<CTriggerVolumeManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff4e0 * obj = (CTriggerVolumeManager_1ff4e0 *)__p0; const char ** arg = (const char **)__p1; void ** out = (void **)__p2;

    void* (CTriggerVolumeManager_1ff4e0::*fn)(const char*) = (*(void *(CTriggerVolumeManager_1ff4e0::**)(const char *))&this->f_1c);
    void* result = obj->Invoke(fn, *arg);
    if (out)
        *out = result;
}
