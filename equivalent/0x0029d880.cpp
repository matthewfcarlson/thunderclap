// STATUS: equivalent (tools/equiv.py level 3: 17928 inputs, branch coverage 51/54, incomplete)
// FUN_0029d880 @ 0x0029d880
// checked with equiv.py --time-budget 1500 at 20000 inputs (the default budget stops early)
extern "C" double __cdecl cos(double);
extern "C" double __cdecl pow(double, double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Rec {
    float f0;                        // 0x00  light intensity
    unsigned int color;              // 0x04
    float f8;                        // 0x08  reach squared
    V3 dir;                          // 0x0c
    unsigned int mask;               // 0x18
    char pad1c[4];
};

class Light {
public:
    char pad00[0x11];
    char enabled;                    // 0x11
    char pad12[2];
    unsigned int color;              // 0x14
    V3 pos;                          // 0x18
    char pad24[0x58 - 0x24];
    V3 dir;                          // 0x58
    float FUN_002a0d00(V3 *where);
    void FUN_002c41c0(float *a, float *b, float *c);
    void FUN_002c4200(float *a, float *b, float *c);
};

struct LightList {
    char pad00[0x10];
    int limit;                       // 0x10
    int count;                       // 0x14
    Light **items;                   // 0x18
};

struct LightCtx {
    LightList *list;                 // 0x00
    Rec *recs;                       // 0x04
};

float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
char __cdecl FUN_00018960(float a, float b, float eps);

extern unsigned int DAT_004cf730;

// The original keeps these unrounded on the FPU stack, so they are recomputed at each use.
static __forceinline float Reach(float len, float p0, float p1, float p2)
{
    if (p1 > 0.0f)
        return len * p1;
    if (p2 > 0.0f)
        return len * len * p2;
    return p0;
}

static __forceinline float Intensity(bool useColor, int m, float fac)
{
    return useColor ? (float)m * fac : 0.0f;
}

class LightMgr {
public:
    char pad00[0x18];
    int lit;                         // 0x18
    char pad1c[0x38 - 0x1c];
    LightCtx *ctx;                   // 0x38
    float FUN_0029d880(V3 *pos, unsigned int mask);
};

float LightMgr::FUN_0029d880(V3 *pos, unsigned int mask)
{
    struct Frame {
        float fac;                   // 0x00
        float c1;                    // 0x04
        int idx;                     // 0x08
        float acc;                   // 0x0c
        union {
            float len;
            int r8;
        } u10;                       // 0x10
        float q1;                    // 0x14
        float p1;                    // 0x18
        float p2;                    // 0x1c
        union {
            float a;
            int m;
        } u20;                       // 0x20
        float q2;                    // 0x24
        float pw;                    // 0x28
        float p0;                    // 0x2c
        float k30;                   // 0x30
        float k34;                   // 0x34
        float k38;                   // 0x38
        float k3c;                   // 0x3c
        int g8;                      // 0x40
        int b8;                      // 0x44
        V3 d;                        // 0x48
    } f;

    f.idx = ctx->list->count - 1;
    f.acc = 0.0f;
    for (; f.idx >= 0; f.idx--) {
        LightList *list = ctx->list;
        if (f.idx >= list->limit) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }
        Light *light = list->items[f.idx];
        if (light == 0 || light->enabled == 0) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }
        if ((ctx->recs[f.idx].mask & mask) != mask) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }

        f.d = *pos;
        f.d.x = f.d.x - light->pos.x;
        f.d.y = f.d.y - light->pos.y;
        f.d.z = f.d.z - light->pos.z;
        if (f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x >= ctx->recs[f.idx].f8) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }

        f.u20.a = light->FUN_002a0d00(pos);
        if (f.u20.a == 0.0f) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }
        light->FUN_002c41c0(&f.p0, &f.p1, &f.p2);
        f.u10.len = f.d.FUN_0022d110();
        if (!(Reach(f.u10.len, f.p0, f.p1, f.p2) <= 0.0f))
            f.fac = f.u20.a / Reach(f.u10.len, f.p0, f.p1, f.p2);
        else
            f.fac = 0.0f;
        f.u10.len = f.d.z * light->dir.z + f.d.y * light->dir.y + f.d.x * light->dir.x;
        light->FUN_002c4200(&f.c1, &f.q1, &f.q2);
        f.c1 = (float)cos(f.c1 * 0.5f);
        if (f.u10.len < f.c1)
            f.fac = 0.0f;

        unsigned int color;
        bool useColor;
        if (!(f.fac > 0.0f)) {
            color = DAT_004cf730;
            useColor = false;
        } else {
            float r2;
            f.q1 = (float)cos(f.q1 * 0.5f);
            if (f.q1 - f.c1 == 0.0f) {
                r2 = 0.0f;
            } else {
                f.u20.a = (f.u10.len - f.c1) / (f.q1 - f.c1);
                f.k30 = 1.0f;
                f.k34 = 0.0f;
                r2 = FUN_000186b0(&f.u20.a, &f.k34, &f.k30);
            }
            f.fac = r2 * f.fac;
            if (FUN_00018960(f.q2, 0.0f, 1e-5f))
                f.pw = 1.0f;
            else
                f.pw = (float)pow(f.u10.len, f.q2);
            f.k38 = 1.0f;
            f.k3c = 0.0f;
            f.fac = FUN_000186b0(&f.pw, &f.k3c, &f.k38) * f.fac;

            unsigned int cl = light->color;
            f.u10.r8 = cl & 0xff;
            f.g8 = (cl >> 8) & 0xff;
            int mx = f.g8 >= f.u10.r8 ? f.g8 : f.u10.r8;
            f.b8 = (cl >> 16) & 0xff;
            f.u20.m = f.b8 < mx ? mx : f.b8;
            int rr = (int)(f.u10.r8 * f.fac);
            int gg = (int)(f.g8 * f.fac);
            int bb = (int)(f.b8 * f.fac);
            if (rr < 0)
                rr = 0;
            else if (rr > 0xff)
                rr = 0xff;
            if (gg < 0)
                gg = 0;
            else if (gg > 0xff)
                gg = 0xff;
            if (bb < 0)
                bb = 0;
            else if (bb > 0xff)
                bb = 0xff;
            color = (((0xffffff00u | bb) << 8 | gg) << 8) | rr;
            useColor = true;
        }
        ctx->recs[f.idx].color = color;
        ctx->recs[f.idx].f0 = Intensity(useColor, f.u20.m, f.fac);
        ctx->recs[f.idx].dir = f.d;
        if (Intensity(useColor, f.u20.m, f.fac) > 0.0f)
            lit++;
        f.acc = Intensity(useColor, f.u20.m, f.fac) + f.acc;
    }
    return f.acc;
}
