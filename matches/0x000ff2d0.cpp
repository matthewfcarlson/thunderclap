struct Status_ff2d0 {
    char pad[0x3a0];
    float value;
    int FUN_000446c0(int);
};
struct Actor_ff2d0 {
    char pad[0x11c];
    Status_ff2d0* status;
    int FUN_00035ef0(int);
};
struct Context {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Actor_ff2d0* slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
    char pad04[0x5c];
    void* active;
    char pad64[0x39];
    unsigned char flag9d;
    unsigned char flag9e;
};
struct CHand2HandAgent {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual float vfunc_3(int, int);
    char pad04[4];
    float score;
    char pad0c[0x4c];
    Context* context;
    char pad5c[4];
    unsigned char flag60;
    char pad61[0x72];
    unsigned char flagd3;
    float FUN_000fc4e0(int, int);
};
float CHand2HandAgent::vfunc_3(int a, int b) {
    FUN_000fc4e0(a, b);
    Actor_ff2d0* actor = context->slot6();
    Context* saved = context;
    score = 0.0f;
    if (!saved->flag9e) {
        if (saved->slot9() < 3)
            return score;
        if (!saved->flag9d)
            return score;
    }
    if (!context->active)
        return score;
    if (actor->FUN_00035ef0(0)) {
        if (actor->status->FUN_000446c0(0)) {
            if (!(actor->status->value < 4.0f))
                return score;
        }
    }
    if (saved->flag9e && !flag60)
        score = 60.0f;
    else if (flagd3)
        score = 55.0f;
    else
        score = 40.0f;
    return score;
}