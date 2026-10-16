// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CCameraShakeAction::vfunc_6 @ 0x00016d30
#include "decls/address.h"
class Shake_16d30 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float GetTime();

    char pad04[0xc];
    float endTime;      // +0x10
    float amplitude;    // +0x14
    float frequency;    // +0x18
};

struct CameraManager_16d30 {
    void FUN_00099320(int mode, float remaining, float amplitude, float frequency);
};

struct World {
    char pad0[8];
    CameraManager_16d30 *camera;
};


class CCameraShakeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused);

    char pad04[0x1c];
    Shake_16d30 *shake;       // +0x20
};

bool CCameraShakeAction::vfunc_6(int unused) {
    float end = shake->endTime;
    float remaining = end - shake->GetTime();
    if (!(remaining <= 0.0f)) {
        Shake_16d30 *s = shake;
        float amplitude = s->amplitude;
        if (!(amplitude <= 0.0f)) {
            float frequency = s->frequency;
            if (!(frequency <= 0.0f)) {
                DAT_004dd700->camera->FUN_00099320(1, remaining, amplitude, frequency);
            }
        }
    }
    return false;
}
