// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 10/10)
// pure3d::SimpleFrameController::vfunc_18 @ 0x00284e60
#include "decls/data/engine/pure3d.h"

namespace pure3d {
struct SimpleFrameController {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(int);
    virtual void vfunc_19(); virtual float vfunc_20();
    char reserved[0x1c];
    int mode;
    int frame;
    float duration;
    char reserved2[0xc];
    unsigned char active;
};
}
void pure3d::SimpleFrameController::vfunc_18(int value) {
    if (frame != value) {
        frame = value;
        float length = vfunc_20();
        duration = length;
        int currentMode = mode;
        if (currentMode == 0 && length == (*(float*)&DAT_0042c5b0))
            frame = 0;
        active = currentMode != 3 && currentMode != 5;
    }
}