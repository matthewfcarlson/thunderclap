// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_002d50c0 @ 0x002d50c0
struct Matrix {
    float m[16];
    void FUN_0022ca90(const void *a, const void *b);
};

struct Curve;
struct Ctx;

struct Key {
    const Curve *c[0x13];
};

struct MatrixHolder {
    Matrix *FUN_0028faa0();
};

struct Sink88 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(Ctx *ctx, void *out);
};

struct Sink8c {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(Ctx *ctx, void *out);
};

struct Sink94 {
    void FUN_0028ac90(Ctx *ctx, void *out);
};

extern MatrixHolder **DAT_0052c2b0;

float __cdecl FUN_0028b150(const Curve *a, const Curve *b, int t, Ctx *ctx);
unsigned int *__cdecl FUN_0028b2f0(unsigned int *out, const Curve *a, const Curve *b, int t, Ctx *ctx);
unsigned char __cdecl FUN_0028b100(const Curve *a, const Curve *b, int t, Ctx *ctx);

class Blend {
public:
    char pad0[8];
    Matrix mat;             // 0x08
    char f48[0x30];         // 0x48
    char f78[0x10];         // 0x78
    Sink88 *sink88;         // 0x88
    Sink8c *sink8c;         // 0x8c
    char f90[4];            // 0x90
    Sink94 *sink94;         // 0x94
    char pad98[0xac - 0x98];
    float fac, fb0;         // 0xac, 0xb0
    char padb4[4];
    float fb8, fbc, fc0, fc4, fc8, fcc, fd0, fd4, fd8;
    char paddc[0xe4 - 0xdc];
    float fe4, fe8, fec, ff0, ff4, ff8, ffc, f100, f104, f108;
    unsigned int f10c;
    unsigned char f110, f111;

    void FUN_002d50c0(Ctx *ctx, const Key *a, const Key *b, int t, const void *xform);
};

void Blend::FUN_002d50c0(Ctx *ctx, const Key *a, const Key *b, int t, const void *xform)
{
    sink88->v4(ctx, f78);
    sink8c->v6(ctx, f48);
    if (sink94)
        sink94->FUN_0028ac90(ctx, f90);

    mat.FUN_0022ca90(xform, f48);
    Matrix tmp;
    tmp.FUN_0022ca90(&mat, (*DAT_0052c2b0)->FUN_0028faa0());
    mat = tmp;

    fac = FUN_0028b150(a->c[2], b->c[2], t, ctx);
    fac = fac * fb0;
    if (fac < 0.0f)
        fac = 0.0f;
    fb8 = FUN_0028b150(a->c[3], b->c[3], t, ctx);
    fb8 = fb8 * fc0;
    if (fb8 < 0.0f)
        fb8 = 0.0f;
    fbc = FUN_0028b150(a->c[4], b->c[4], t, ctx);
    fc4 = FUN_0028b150(a->c[5], b->c[5], t, ctx) * fcc;
    fc8 = FUN_0028b150(a->c[6], b->c[6], t, ctx);
    fd0 = FUN_0028b150(a->c[7], b->c[7], t, ctx);
    fd0 = fd0 * fd8;
    if (fd0 < 0.0f)
        fd0 = 0.0f;
    fd4 = FUN_0028b150(a->c[8], b->c[8], t, ctx);
    if (a->c[9] && b->c[9])
        fe4 = FUN_0028b150(a->c[9], b->c[9], t, ctx) * fec;
    if (a->c[10] && b->c[10])
        fe8 = FUN_0028b150(a->c[10], b->c[10], t, ctx);
    ff0 = FUN_0028b150(a->c[11], b->c[11], t, ctx) * ff8;
    ff4 = FUN_0028b150(a->c[12], b->c[12], t, ctx);
    ffc = FUN_0028b150(a->c[13], b->c[13], t, ctx) * f100;
    f104 = FUN_0028b150(a->c[14], b->c[14], t, ctx) * f108;
    unsigned int col;
    f10c = *FUN_0028b2f0(&col, a->c[15], b->c[15], t, ctx);
    f10c = (f10c & 0xffffff) | ((unsigned int)FUN_0028b100(a->c[17], b->c[17], t, ctx) << 24);
    f110 = FUN_0028b100(a->c[16], b->c[16], t, ctx);
    f111 = FUN_0028b100(a->c[18], b->c[18], t, ctx);
}
