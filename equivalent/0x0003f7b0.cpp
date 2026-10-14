// STATUS: equivalent (tools/equiv.py level 3: 3031 inputs, branch coverage 71/72, incomplete)
// FUN_0003f7b0 @ 0x0003f7b0
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3 *a, const V3 *b);
    void FUN_00011090();
};

void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3::*ctor)());

struct Info {
    char pad00[0x16];
    unsigned char flags16;
};

struct Holder5 {
    char pad00[0x40];
    int f40;
    char pad44[0xec - 0x44];
    struct Checker *chk;
};

struct HitObj {
    char pad00[8];
    Holder5 *sub;
    int kind;
};

struct Checker {
    char FUN_001d6000(int a);
};

struct Cfg {
    char pad00[0x30];
    float f30;
    float radius;
};

struct Player {
    char pad00[0x124];
    struct Chara *current;
};

struct World {
    char pad00[0x20];
    Player *player;
};

extern World *DAT_004dd700;
extern float DAT_0048f690;
extern float DAT_0048f694;
extern unsigned int DAT_004dc2e8;
extern float DAT_004dc2e4;

char FUN_002027c0(V3 *from, V3 *to, int a, int b, V3 *hitPos, V3 *hitNormal, HitObj **hitObj, Info **info);

struct Chara {
    char pad00[0x11c];
    Cfg *cfg;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x334 - 0x144];
    Chara *ignoreA;
    Chara *ignoreB;
    char pad33c[0x1b08 - 0x33c];
    char allowMiss;
    void FUN_00035fa0(int a);
    char Probe(V3 *p1, V3 *p2, V3 *out1, V3 *out2, V3 *d, V3 *n2, unsigned int *flags);
};

struct Frame {
    V3 n;               // 0x00
    char pad0c[3];
    char found;         // 0x0f
    int i;              // 0x10
    int count;          // 0x14
    union {
        double sx;      // x accumulator (0x18)
        struct { float tmp18; float w1c; };
    };
    float radius;       // 0x20
    Info *info;         // 0x24
    V3 w;               // 0x28
    V3 c;               // 0x34
    int flagArg;        // 0x40
    int k;              // 0x44
    V3 hn;              // 0x48 (up vector, then hit normal)
    V3 s;               // 0x54
    V3 nn;              // 0x60
    float dd;           // 0x6c
    HitObj *hitObj;     // 0x70
    V3 t;               // 0x74
    V3 hp;              // 0x80
    V3 arr2[3];         // 0x8c
    V3 hp2;             // 0xb0
    V3 arr[5];          // 0xbc
};

static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

char Chara::Probe(V3 *p1, V3 *p2, V3 *out1, V3 *out2, V3 *d, V3 *n2, unsigned int *flags)
{
    if (cfg == 0)
        return 0;

    Chara *cur = DAT_004dd700->player->current;
    Frame f;
    f.flagArg = 0;
    if (this != cur && ignoreB != cur && ignoreA != cur)
        f.flagArg = 1;

    f.hitObj = 0;
    f.info = 0;
    FUN_00035fa0(0);
    char ok = FUN_002027c0(p1, p2, 0, f.flagArg, &f.hp, &f.n, &f.hitObj, &f.info);
    FUN_00035fa0(1);
    if (!ok) {
        if (flags)
            *flags = 0xf;
        return 0;
    }
    if (f.info && (f.info->flags16 & 0x10))
        return 0;
    if (f.hitObj) {
        if (f.hitObj->kind != 5)
            return 0;
        Holder5 *h = f.hitObj->sub;
        if (!h)
            return 0;
        if (!h->chk->FUN_001d6000(h->f40))
            return 0;
    }

    *(float *)&f.i = f.n.y;
    *(unsigned int *)&f.i &= 0x7fffffff;
    float ay = *(float *)&f.i;
    if (!(ay <= 0.01f)) {
        if ((float)sin((double)(DAT_0048f694 * 0.017453292f)) > ay) {
            f.n.y = 0;
            f.n.FUN_0022d110();
        }
    }
    if (!(DAT_004dc2e8 & 1)) {
        DAT_004dc2e8 |= 1;
        DAT_004dc2e4 = (float)cos(1.1344640453656516);
    }

    FUN_00011520(f.arr, 12, 5, &V3::FUN_00011090);
    f.count = 0;
    f.k = 0;
    if (d && (f.n.z * d->z + f.n.y * d->y + f.n.x * d->x) <= DAT_004dc2e4) {
        f.k = 1;
    } else {
        f.arr[0] = f.n;
        f.count = 1;
    }

    f.w1c = cfg->f30;
    f.radius = cfg->radius;
    f.w.x = p2->x - p1->x;
    f.w.y = p2->y - p1->y;
    f.w.z = p2->z - p1->z;
    f.w.FUN_0022d110();

    FUN_00011520(f.arr2, 12, 3, &V3::FUN_00011090);
    float hy = DAT_0048f690 * f.w1c;
    f.arr2[0].x = 0;
    f.arr2[0].y = hy;
    f.arr2[0].z = 0;
    if (mode != 4)
        f.arr2[0].y = hy * 0.5f;
    f.hn.x = 0;
    f.hn.y = 1.0f;
    f.hn.z = 0;
    f.arr2[2].FUN_000111b0(&f.hn, &f.w);
    f.arr2[2].x = f.arr2[2].x * f.radius;
    f.arr2[2].y = f.arr2[2].y * f.radius;
    f.arr2[2].z = f.arr2[2].z * f.radius;
    f.nn = f.n;
    f.arr2[1].x = -f.arr2[2].x;
    f.arr2[1].y = -f.arr2[2].y;
    f.arr2[1].z = -f.arr2[2].z;
    f.hp2.z = -f.arr2[2].z;
    f.dd = -(f.hp.z * f.nn.z + f.hp.x * f.nn.x + f.hp.y * f.nn.y);
    f.found = 1;
    for (f.i = 0; f.i < 3; f.i++) {
        if (n2) {
            f.t = f.arr2[f.i];
            f.t.FUN_0022d110();
            if ((f.t.z * n2->z + f.t.y * n2->y + f.t.x * n2->x) <= 0.0f)
                continue;
        }
        f.s.x = p1->x + f.arr2[f.i].x;
        f.s.y = p1->y + f.arr2[f.i].y;
        f.s.z = p1->z + f.arr2[f.i].z;
        f.c = *p2;
        f.tmp18 = f.nn.z * p1->z + f.nn.y * p1->y + f.nn.x * p1->x + f.dd;
        float cx = f.c.x + f.arr2[f.i].x;
        f.w1c = f.c.y + f.arr2[f.i].y;
        f.c.z = f.c.z + f.arr2[f.i].z;
        f.c.x = f.w.x * f.tmp18 + cx;
        f.c.y = f.w.y * f.tmp18 + f.w1c;
        f.c.z = f.w.z * f.tmp18 + f.c.z;
        f.found = 0;
        FUN_00035fa0(0);
        char ok2 = FUN_002027c0(&f.s, &f.c, 0, f.flagArg, &f.hp2, &f.hn, 0, &f.info);
        FUN_00035fa0(1);
        if (!ok2) {
            if (flags) {
                *flags |= 1u << f.i;
                return 0;
            }
            if (!allowMiss)
                return 0;
            continue;
        }
        if (f.info && (f.info->flags16 & 0x10))
            return 0;
        f.found = 1;
        if (!((f.hn.z * f.n.z + f.hn.x * f.n.x + f.hn.y * f.n.y) < DAT_004dc2e4)) {
            f.arr[f.count] = f.hn;
            f.count++;
        } else {
            f.k++;
            if (f.k > 1)
                return 0;
        }
        f.tmp18 = f.hp2.z * f.nn.z + f.hp2.y * f.nn.y + f.hp2.x * f.nn.x + f.dd;
        *(unsigned int *)&f.tmp18 &= 0x7fffffff;
        if (f.tmp18 > f.radius) {
            if (flags) {
                *flags |= 1u << f.i;
                return 0;
            }
            return 0;
        }
    }
    if (!f.found)
        return 0;
    if (f.count > 0) {
        f.sx = 0;
        float sy = 0;
        float sz = 0;
        for (int j = 0; j < f.count; j++) {
            f.sx += f.arr[j].x;
            sy += f.arr[j].y;
            sz += f.arr[j].z;
        }
        double inv = 1.0f / f.count;
        f.n.x = (float)(inv * f.sx);
        f.tmp18 = (float)inv;
        f.n.y = f.tmp18 * sy;
        f.n.z = sz * f.tmp18;
        f.n.FUN_0022d110();
    }
    out1->x = f.n.x * 0.01f + f.hp.x;
    out1->y = f.n.y * 0.01f + f.hp.y;
    out1->z = f.n.z * 0.01f + f.hp.z;
    out2->x = f.n.x;
    out2->y = f.n.y;
    out2->z = f.n.z;
    return 1;
}
