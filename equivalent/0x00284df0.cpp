// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 10/10)
// pure3d::SimpleFrameController::vfunc_16 @ 0x00284df0
extern const float DAT_0042c5b0;
namespace pure3d {
struct SimpleFrameController {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(int); virtual void vfunc_17();
    virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20();
    char pad[0x20-4];
    int mode;
    int frame;
    float length;
    char pad2[0x38-0x2c];
    unsigned char active;
};
void SimpleFrameController::vfunc_16(int value) {
    if (value != mode) {
        mode = value;
        float duration = vfunc_20();
        length = duration;
        if (mode == 0 && duration == DAT_0042c5b0)
            frame = 0;
        active = mode != 3 && mode != 5;
    }
}
}