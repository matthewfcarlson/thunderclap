// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// CAvoidBehaviour::vfunc_4 @ 0x00109c00
struct V3_109c00 {
    float x, y, z;
    float FUN_0022d110();
};

class Ctx_109c00;

class Prober {
public:
    char FUN_00024540(Ctx_109c00 *who);
};

struct Target_109c00 {
    char pad0[0x20];
    Prober *prober;
};

class Ctx_109c00 {
public:
    char pad0[0x1d04];
    char hit;
    char pad1d05[0x2064 - 0x1d05];
    V3_109c00 p2064;
    float limit;
    V3_109c00 p2074;
    char pad2080[0x208c - 0x2080];
    V3_109c00 p208c;
    float FUN_00035700();
};

struct Frame_109c00 {
    char pad0[3];
    char flag;
    V3_109c00 diff;
    V3_109c00 w;
    int pad2c;
    volatile float e;
    volatile float f;
    volatile float g;
    int pad3c[4];
    volatile float c;
};

class CAvoidBehaviour {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(Target_109c00 *tgt, Ctx_109c00 *ctx, V3_109c00 *out, int a5, int zero);
    virtual bool vfunc_4(V3_109c00 *a, V3_109c00 *b, Ctx_109c00 *ctx, Target_109c00 *tgt, int a5, V3_109c00 *d, V3_109c00 *c);

    char pad4[0xc];
    V3_109c00 dir;
    V3_109c00 pad1c;
    float peak;
    float ratio;
    int f30;
    char f34;
};

bool CAvoidBehaviour::vfunc_4(V3_109c00 *a, V3_109c00 *b, Ctx_109c00 *ctx, Target_109c00 *tgt, int a5, V3_109c00 *d, V3_109c00 *c)
{
    Frame_109c00 fr;
    fr.flag = 0;
    fr.diff.x = a->x - b->x;
    fr.diff.y = a->y - b->y;
    fr.diff.z = a->z - b->z;
    dir.x = fr.diff.x;
    dir.y = fr.diff.y;
    dir.z = fr.diff.z;
    fr.diff.FUN_0022d110();

    bool hit = false;
    if (tgt && tgt->prober && tgt->prober->FUN_00024540(ctx)) {
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = 0.0f;
        pad1c.x = 0.0f;
        pad1c.y = 0.0f;
        pad1c.z = 0.0f;
        f34 = 1;
        f30 = 0;
    } else if (v3(tgt, ctx, &fr.w, a5, 0)) {
        hit = true;
        fr.flag = 1;
        fr.c = c->z * 0.1f;
        fr.e = d->y * 0.9f;
        fr.f = d->z * 0.9f;
        fr.g = d->x * 0.9f + c->x * 0.1f;
        double h = fr.e + c->y * 0.1f;
        double i = fr.f + fr.c;
        d->x = fr.g;
        d->y = (float)h;
        d->z = (float)i;
        fr.diff.x = fr.w.x + fr.g;
        fr.diff.y = (float)(fr.w.y + h);
        fr.diff.z = (float)(fr.w.z + i);
        fr.diff.FUN_0022d110();
        ctx->limit = ratio;
    } else {
        float r = ctx->FUN_00035700();
        if (r > peak)
            peak = r;
        float q = r / peak;
        if (q > ctx->limit)
            q = ctx->limit;
        ratio = q;
    }
    ctx->hit = hit;
    ctx->p2074.z = fr.diff.z;
    ctx->p2074.x = fr.diff.x;
    ctx->p2074.y = fr.diff.y;
    ctx->p2064.z = fr.diff.z;
    ctx->p2064.x = fr.diff.x;
    ctx->p2064.y = fr.diff.y;
    ctx->p208c.z = fr.w.z;
    ctx->p208c.x = fr.w.x;
    ctx->p208c.y = fr.w.y;
    return fr.flag != 0;
}
