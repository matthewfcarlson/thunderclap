// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 14/14)
// pure3d::SimpleFrameController::vfunc_14 @ 0x00285930
namespace pure3d {
class SimpleFrameController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void vfunc_14(float lo, float hi);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float GetFrame();                            // slot 20

    char pad4[0x1c];
    int mode;               // 0x20
    char pad24[4];
    float frame;            // 0x28
    float lo;               // 0x2c
    float hi;               // 0x30
    float cur;              // 0x34
    unsigned char playing;  // 0x38
};

void SimpleFrameController::vfunc_14(float newLo, float newHi)
{
    if (lo == newLo && hi == newHi)
        return;
    lo = newLo;
    hi = newHi;
    if (cur >= lo && cur <= hi) {
    } else if (cur > hi) {
        cur = hi;
    } else {
        cur = lo;
    }
    frame = GetFrame();
    playing = !(mode == 3 || mode == 5);
}
}
