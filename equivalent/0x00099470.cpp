// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00099470 @ 0x00099470
struct Scaler {
    void FUN_00086100(float v);
};

struct Holder {
    char pad0[8];
    Scaler *scaler;         // 0x8
    Scaler *FUN_00086320();
};

struct Mode {
    bool FUN_001c3cb0();
};
Mode *FUN_001c3d90();

struct Anim {
    void FUN_000361c0(int a);
    void FUN_00036140(int a);
};

struct Status {
    char pad0[8];
    char flag;              // 0x8
};

struct Actor {
    char pad0[0x124];
    Anim *anim;             // 0x124
};

struct Ctx {
    char pad0[4];
    Status *status;         // 0x4
    char pad8[0x20 - 8];
    Actor *actor;           // 0x20
};

struct Target {
    char pad0[0x2c4];
    float scale;            // 0x2c4
};

class Handler {
public:
    char pad0[4];
    unsigned int flags;     // 0x4
    char pad8[4];
    Holder *holder;         // 0xc
    int arg0;               // 0x10
    int arg1;               // 0x14
    char pad18[0xc4 - 0x18];
    Target *target;         // 0xc4

    void FUN_000991b0(Ctx *ctx, int a, int b, int c, int d);
    void FUN_00099470(Ctx *ctx);
};

void Handler::FUN_00099470(Ctx *ctx)
{
    if ((flags >> 4 & 1) == 0)
        return;
    flags &= ~0x10u;
    holder->FUN_00086320()->FUN_00086100(1.0f);
    if (!FUN_001c3d90()->FUN_001c3cb0())
        ctx->status->flag = 1;
    Anim *a = ctx->actor->anim;
    if (a != 0) {
        a->FUN_000361c0(0);
        a->FUN_00036140(0);
    }
    FUN_000991b0(ctx, arg0, arg1, 0, 0);
    target->scale = 1.5f;
}
