// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 29/30, incomplete)
// hulkfight::motion::HitPushbackAction::vfunc_3 @ 0x0014f680
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3 *a, const V3 *b);
};

struct Str {
    void FUN_0027b040(const char *s);
};

struct Sub18 {
    void FUN_0022be40(V3 *v);
    void FUN_00221d20(float f);
};

struct Push {
    virtual void v0();
    char pad04[0x8 - 0x4];
    Str name;               // 0x8
    char pad09[0x14 - 0x9];
    int flags;              // 0x14
    Sub18 sub;              // 0x18
    char pad19[0x70 - 0x19];
    Push *FUN_002248f0(int a);
};

struct Params {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float v7();
    char pad04[0x14 - 0x4];
    float f14;
    float f18;
    char flag;              // 0x1c
    char pad1d[3];
    float f20;
    float f24;
    float w2;               // 0x28
    float w1;               // 0x2c
    float w0;               // 0x30
};

struct Hit {
    char pad0[0x8];
    float x8;
    char pad0c[4];
    float x10;
    char pad14[0x28 - 0x14];
    V3 vec;                 // 0x28
    char pad34[0x5c - 0x34];
    float f5c;
};

struct Player {
    char pad0[0x140];
    int mode;               // 0x140
    float FUN_000354c0();
};

struct Body {
    char pad0[0x40];
    V3 pos;                 // 0x40
    void FUN_00222890(Push *p, float a, float b, float c, float d, float e, float f);
};

struct Owner {
    Player *FUN_00059a30();
    Body *FUN_00059a40();
};

struct Link {
    Owner *FUN_000592a0();
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Hit *v3();
};

extern void *thunk_FUN_0008d690(unsigned int size);
extern float __cdecl FUN_00224f10(V3 *v);

class HitPushbackAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(void *a, void *b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Params *params;         // 0x1c
    Link *link;             // 0x20
    Push *push;             // 0x24
    float f28;
    V3 v;                   // 0x2c
    float f38;
    float f3c;
    float f40;
};

bool HitPushbackAction::vfunc_3(void *a, void *b)
{
    if (link == 0)
        return false;
    Owner *own = link->FUN_000592a0();
    Player *pl = own->FUN_00059a30();
    Body *body = own->FUN_00059a40();
    if (body == 0)
        return false;
    Hit *hit = link->v3();
    if (hit == 0)
        return false;
    Params *pa = params;
    float f24 = pa->f24;
    float w2 = pa->w2;
    int mode = pl->mode;
    float w1 = pa->w1;
    float w0 = pa->w0;
    void *mem = thunk_FUN_0008d690(0x70);
    Push *o;
    if (mem != 0)
        o = ((Push *)mem)->FUN_002248f0(0);
    else
        o = 0;
    push = o;
    o->name.FUN_0027b040("hitPushback");
    int flag = 1;
    if (params->flag != 0 || (mode == 2 && f24 > 0.0f))
        flag = 3;
    push->flags = flag;
    push->v0();
    V3 *bp = &body->pos;
    push->sub.FUN_0022be40(bp);
    float arg;
    if (params->flag != 0)
        arg = FUN_00224f10(&hit->vec) + params->f20;
    else
        arg = pl->FUN_000354c0();
    push->sub.FUN_00221d20(arg);
    body->FUN_00222890(push, -1.0f, w2, 1.0f, w1, w0, -1.0f);
    float h5c = hit->f5c;
    f28 = h5c;
    if (h5c <= 0.0f)
        f28 = params->v7();
    v = hit->vec;
    v.y = 0.0f;
    double len = v.FUN_0022d110();
    f38 = (float)len;
    Params *pp = params;
    double p1 = len * pp->f14;
    f38 = (float)p1;
    double X;
    if (f28 > 0.0f) {
        float c = pp->f18;
        X = p1 * f28;
        if (c >= 0.0f && X > c) {
            f38 = c / f28;
            X = c;
        }
        double D = f38;
        D = D + D;
        f38 = (float)D;
        double fm = f28;
        double N = X - D * fm;
        N = N + N;
        f3c = (float)(N / (fm * fm));
    } else {
        f3c = 0.0f;
    }
    if (mode == 2 && f24 > 0.0f) {
        f40 = f24 * f38;
        V3 w;
        w.x = bp->x;
        w.z = bp->z;
        w.x = w.x - hit->x8;
        w.y = 0.0f;
        w.z = w.z - hit->x10;
        w.FUN_0022d110();
        V3 vc = v;
        V3 cr;
        cr.FUN_000111b0(&vc, &w);
        if (cr.y < 0.0f)
            f40 = -f40;
    }
    return true;
}
