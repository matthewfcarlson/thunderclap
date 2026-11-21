// FUN_001c04e0 @ 0x001c04e0
// (integ9, D165; rev5) --x64 must-fail: the same raw write taken when the step is at least 0.5, inside the callee's
// return range: the draw covers the range (it never pins a value), so the layout difference is still found.
struct Listener_1c04e0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(float dt);
};
struct StateHolder {
    int* FUN_00086270();
};
struct Clock_1c04e0 {
    float FUN_00085f80();
};
struct World {
    void* pad[22];
    Clock_1c04e0* clock;
};
extern "C" World* DAT_004dd700;
struct Fader_1c04e0 {
    float timer;
    int pending;
    char pad0[4];
    bool active;
    bool fadeIn;
    char pad2[0x20 - 0x0e];
    int mode;
    char pad3[0x2c - 0x24];
    Listener_1c04e0* listener;
    char pad4[0x4c - 0x30];
    StateHolder* state;
    int alpha;
    void FUN_001bf9b0();
    void Update(float dt);
};
void Fader_1c04e0::Update(float dt) {
    if (!active)
        return;
    if (*state->FUN_00086270() != 6) {
        float absDt = dt < 0.0f ? -dt : dt;
        if (!(absDt > 1e-05f)) {
            float step = DAT_004dd700->clock->FUN_00085f80();
            if (step >= 0.5f)
                *(int*)((char*)this + 0x4c) = 0;
            if (step >= 0.0f && step < 0.1f)
                dt = step;
            else
                dt = 0.1f;
        }
    }
    if (timer < 0.0f)
        timer = dt;
    else
        timer += dt;
    if (pending > 0)
        FUN_001bf9b0();
    if (fadeIn) {
        if (alpha < 255) {
            alpha += 10;
            if (alpha > 255)
                alpha = 255;
        }
    } else {
        if (alpha > 0) {
            alpha -= 10;
            if (alpha < 0)
                alpha = 0;
        }
    }
    if (mode == 2)
        listener->vf3(dt);
}
