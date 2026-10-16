// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 12/12)
// ControllerPoller::vfunc_4 @ 0x000ddac0
#include "decls/data/game/global.h"

struct Binding_ddac0 {
    int axis;       // index into the sample buffer
    int button;     // button id this axis is bound to
};

                // number of bindings
             // axis threshold (writable, 0.05f)
               // latch: a press is being held

class Device_ddac0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int pad, float* samples);
};

class ControllerPoller {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual char vfunc_4(int button, int pad);
    virtual void vfunc_5();
    char pad04[0x38 - 4];
    Device_ddac0* device;         // 0x38
};

// True when an axis bound to the button is pressed past the threshold; a held press reports once.
char ControllerPoller::vfunc_4(int button, int pad)
{
    float samples[10];
    device->vfunc_1(pad, samples);
    char pressed = 0;
    int i = 0;
    if ((*(int*)&DAT_004de8c0) > 0) {
        do {
            if (((Binding_ddac0*)&DAT_004de800)[i].button == button && samples[((Binding_ddac0*)&DAT_004de800)[i].axis] > DAT_004a0e68)
                pressed = 1;
            i++;
        } while (i < (*(int*)&DAT_004de8c0));
    }
    if ((*(char*)&DAT_004e222d)) {
        if (pressed)
            return 0;
        (*(char*)&DAT_004e222d) = pressed;
    }
    return pressed;
}
