// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00099470 @ 0x00099470
struct Scaler_99470 {
    void FUN_00086100(float v);
};

struct Holder_99470 {
    char pad0[8];
    Scaler_99470 *scaler;         // 0x8
    Scaler_99470 *FUN_00086320();
};

struct Mode_99470 {
    bool FUN_001c3cb0();
};
Mode_99470 *FUN_001c3d90();

struct Anim_99470 {
    void FUN_000361c0(int a);
    void FUN_00036140(int a);
};

struct Status_99470 {
    char pad0[8];
    char flag;              // 0x8
};

struct Actor_99470 {
    char pad0[0x124];
    Anim_99470 *anim;             // 0x124
};

struct Ctx_99470 {
    char pad0[4];
    Status_99470 *status;         // 0x4
    char pad8[0x20 - 8];
    Actor_99470 *actor;           // 0x20
};

struct Target_99470 {
    char pad0[0x2c4];
    float scale;            // 0x2c4
};

class Handler_99470 {
public:
    char pad0[4];
    unsigned int flags;     // 0x4
    char pad8[4];
    Holder_99470 *holder;         // 0xc
    int arg0;               // 0x10
    int arg1;               // 0x14
    char pad18[0xc4 - 0x18];
    Target_99470 *target;         // 0xc4

    void FUN_000991b0(Ctx_99470 *ctx, int a, int b, int c, int d);
    void FUN_00099470(Ctx_99470 *ctx);
};

void Handler_99470::FUN_00099470(Ctx_99470 *ctx)
{
    if ((flags >> 4 & 1) == 0)
        return;
    flags &= ~0x10u;
    holder->FUN_00086320()->FUN_00086100(1.0f);
    if (!FUN_001c3d90()->FUN_001c3cb0())
        ctx->status->flag = 1;
    Anim_99470 *a = ctx->actor->anim;
    if (a != 0) {
        a->FUN_000361c0(0);
        a->FUN_00036140(0);
    }
    FUN_000991b0(ctx, arg0, arg1, 0, 0);
    target->scale = 1.5f;
}
