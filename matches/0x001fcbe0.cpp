#include "gen/global.h"

class CTriggerVolumeManager_1fcbe0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual char V11();
};

struct CTriggerVolumeManager_nv_1fcbe0 {
    CTriggerVolumeManager_1fcbe0* FUN_001fc7f0(int);
};

char CTriggerVolumeManager::FUN_001fcbe0(int a) {
    CTriggerVolumeManager_1fcbe0* r = ((CTriggerVolumeManager_nv_1fcbe0*)(this))->FUN_001fc7f0(a);
    if (!r)
        return 1;
    return r->V11();
}
