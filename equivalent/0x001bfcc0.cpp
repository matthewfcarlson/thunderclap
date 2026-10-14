// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// CSubtitleOverlay::vfunc_3 @ 0x001bfcc0
static float Abs(float v)
{
    union { float f; unsigned int u; } x;
    x.f = v;
    x.u &= 0x7fffffff;
    return x.f;
}

struct Clock { float FUN_00085f80(); };
struct Globals { char pad0[0x58]; Clock *clock; };
extern Globals *DAT_004dd700;

class Overlay {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(float dt);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[8];
    char active;              // 0xc
    char pad0d[3];
    float timer;              // 0x10
    char pad14[0x11d - 0x14];
    char hidden;              // 0x11d
    void FUN_001bf0c0(float dt);
};

class CSubtitleOverlay : public Overlay {
public:
    virtual void vfunc_3(float dt);
};

void CSubtitleOverlay::vfunc_3(float dt)
{
    if (hidden)
        return;
    if (!active && Abs(timer) <= 1e-5f)
        return;
    if (Abs(dt) <= 1e-5f) {
        dt = DAT_004dd700->clock->FUN_00085f80();
        if (dt < 0.1f) {
            FUN_001bf0c0(dt);
            return;
        }
        dt = 0.1f;
    }
    FUN_001bf0c0(dt);
}
