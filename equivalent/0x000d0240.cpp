// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// HUDOverlay::vfunc_3 @ 0x000d0240
class Ref {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x1b0c - 4];
    float f1b0c;
    char pad1b10[4];
    float f1b14;
    char pad1b18[0x20b0 - 0x1b18];
    int f20b0;
    float FUN_00036090();
};

struct Target {
    char pad00[0x124];
    Ref* ref;
};

struct Holder {
    char pad00[0x20];
    Target* target;
};

struct Parent {
    char pad00[0x20];
    Target* target;
};

struct Clock {
    int FUN_00090110();
};

struct Timer {
    Clock* FUN_00086370();
};

struct Globals {
    char pad00[0x54];
    Timer* timer;
};

struct Updater {
    void FUN_000c9810(float dt);
};

extern Globals* DAT_004dd700;
extern float DAT_004de600;
extern float DAT_004de604;
extern float DAT_0049fcf0;
extern float DAT_0049fd1c;
extern float DAT_0049fd20;
extern float DAT_0049fd24;

extern float DAT_004dde98;
extern float DAT_004dde9c;
extern float DAT_004ddea0;
extern float DAT_004ddea4;
extern float DAT_004ddea8;
extern float DAT_004ddeac;
extern float DAT_004ddeb0;
extern float DAT_004ddeb4;
extern float DAT_004ddeb8;
extern float DAT_004ddec8;
extern float DAT_004ddecc;
extern float DAT_004dded0;
extern float DAT_004ddf00;
extern float DAT_004ddf04;
extern float DAT_004ddf08;
extern float DAT_004ddf0c;
extern float DAT_004ddf10;
extern float DAT_004ddf14;

void FUN_00025960(Ref** slot, Ref* value);
void FUN_000a0d40(Ref** slot);
float FUN_000186b0(float* v, float* lo, float* hi);

struct Frame {
    float hi;
    float lo;
    float v;
    float w;
    int gap10;
    int gap14;
    float t20;
    float t24;
    int gap20;
    float t2c;
    float t30;
    int gap2c;
};

class Overlay {
public:
    virtual void vfunc_0();
};

class HUDOverlay : public Overlay {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(float dt);

    char pad04[8];
    Parent* parent;
    char pad10[4];
    Ref* ref;
    Ref* ref2;
    char pad1c[0x50 - 0x1c];
    char hidden;
    char pad51[0x88 - 0x51];
    Updater* updater;
    char pad8c[0xa8 - 0x8c];
    float a8;
    int lastValue;
    float b0;
    int b4;
    char padb8[0x144 - 0xb8];
    float elapsed;
    char pad148[0x154 - 0x148];
    float f154;
    float f158;
    char pad15c[4];
    int f160;
    char pad164[0x174 - 0x164];
    float f174;
    float f178;

    void FUN_000cbc40(float dt);
    void FUN_000cf4b0(float dt);
    void FUN_000ce0d0(float dt);
};

void HUDOverlay::vfunc_3(float dt)
{
    if (!parent)
        return;
    if (hidden)
        return;

    volatile Frame f;
    f.w = DAT_004de600;
    double x1 = DAT_004de600 * -0.5f;
    double hh = DAT_004de604 * 0.5f;
    DAT_004ddf14 = 0;
    DAT_004ddeb8 = 0;
    f.t20 = (float)x1;
    DAT_004ddea0 = 0;
    DAT_004ddf08 = 0;
    f.t30 = DAT_004de604 * -0.1f;
    DAT_004ddf0c = f.w * 0.06f + f.t20;
    DAT_004ddf10 = f.t30 + hh;
    f.t20 = (float)x1;
    f.t24 = DAT_004de604 * -0.5f;
    DAT_004ddeb0 = f.w * 0.1f + f.t20;
    DAT_004ddeb4 = DAT_004de604 * 0.36f + f.t24;
    f.t20 = (float)x1;
    f.t24 = DAT_004de604 * -0.5f;
    DAT_004dde98 = f.w * 0.1f + f.t20;
    DAT_004dde9c = DAT_004de604 * 0.4f + f.t24;
    f.t30 = DAT_004de604 * -0.18f;
    DAT_004ddf00 = f.w * 0.04f + x1;
    DAT_004ddf04 = f.t30 + hh;
    double ah = DAT_0049fd1c * f.w;
    f.hi = (float)ah;
    f.t30 = -(DAT_0049fd20 * DAT_004de604);
    DAT_004ddec8 = ah + x1;
    DAT_004ddecc = f.t30 + hh;
    DAT_004dded0 = 0;
    f.t2c = (float)x1;
    DAT_004ddeac = 0;
    f.t24 = -(DAT_0049fd24 * DAT_004de604);
    DAT_004ddea4 = f.hi + f.t2c;
    DAT_004ddea8 = f.t24 + hh;

    Ref* want = parent->target->ref;
    if (want != ref && want) {
        FUN_00025960(&ref, want);
        if (ref) {
            float h = ref->f1b0c;
            f160 = 0xff;
            f154 = h;
            f158 = h;
            f.hi = ref->f1b0c;
            float d = f.hi - ref->FUN_00036090();
            f174 = d;
            f178 = d;
        }
    }
    if (ref && ref->f20b0)
        FUN_000a0d40(&ref);
    if (ref2 && ref2->f20b0)
        FUN_000a0d40(&ref2);

    int value = DAT_004dd700->timer->FUN_00086370()->FUN_00090110();
    if (value != lastValue) {
        float s = DAT_0049fcf0 * 0.4f;
        int delta = value - lastValue;
        lastValue = value;
        if (s > a8)
            a8 = s + a8;
        if (delta > 100) {
            if (b0 > 0.0f)
                b4 = b4 + delta;
            else
                b4 = delta;
            f.hi = 0.5f;
            f.lo = 0;
            f.v = b4 * 0.00166667f;
            b0 = FUN_000186b0((float*)&f.v, (float*)&f.lo, (float*)&f.hi) + 0.5f;
        }
    } else {
        a8 = a8 - dt;
        if (a8 < 0.0f)
            a8 = 0;
        b0 = b0 - dt;
        if (b0 < 0.0f)
            b0 = 0;
    }

    updater->FUN_000c9810(dt);
    FUN_000cbc40(dt);
    FUN_000cf4b0(dt);
    FUN_000ce0d0(dt);
    elapsed = dt + elapsed;
}
