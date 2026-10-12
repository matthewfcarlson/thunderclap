// STATUS: equivalent (tools/equiv.py level 3: 3056 inputs, branch coverage 49/52, incomplete)
// hulkfight::ai::RoutAction::vfunc_5 @ 0x00122520
extern "C" int atexit(void (*)());
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_000111f0() throw();
    float FUN_0022d110() throw();
    float FUN_00018990() throw();
};

struct Key {
    unsigned int lo, hi;
    void FUN_0027af00() throw();
};

struct Mat {
    float m[16];
    void FUN_0022c3b0(Vec3 *in, Vec3 *out) throw();
};

struct World;

struct Fighter {
    void FUN_00059a50(Vec3 *out) throw();
};

struct Ent {
    char pad00[0x10];
    Fighter *f10;
    void FUN_00035660(Vec3 *out) throw();
};

struct Misc {
    void FUN_000344b0(float x) throw();
};

class RefObj {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
    char pad04[4];
    Ent *f08;
    int f0c;
};

struct Hand {
    char pad[0x129];
    char b129;
};

struct Sub {
    char pad000[0x10c];
    Vec3 v10c;
    float f118;
    Vec3 v11c;
    void FUN_00060170() throw();
};

struct Stats;

class Sink {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual char v4(Vec3 *a, Vec3 *b, Stats *s, World *w, float dt, void *c, Vec3 *d) throw();
    char FUN_0010aa90(World *w, Vec3 *b, Vec3 *a, float k, Vec3 *o1, Vec3 *o2, Vec3 *r, Stats *s, RefObj *obj, int p, int q) throw();
};

struct Stats {
    char pad000[0x10];
    Fighter *f10;
    char pad014[0x328 - 0x14];
    RefObj *f328;
    char pad32c[0x1ca0 - 0x32c];
    Hand *f1ca0;
    Sink *f1ca4;
    char pad1ca8[0x1f58 - 0x1ca8];
    Sub sub1f58;
    void FUN_00035160(Mat *m) throw();
};

struct Cfg {
    char pad00[0x18];
    float f18;
    char pad1c[4];
    float f20;
    float f24;
    char b28;
    char pad29[3];
    float f2c;
    float f30;
    float f34;
};

extern World *DAT_004dd700;
extern unsigned int DAT_004e0d60;
extern Key DAT_004e0d58;
void FUN_00363f20();
float __cdecl FUN_0010b1c0(World *w, Stats *s, float thr, Vec3 *out) throw();
float __cdecl FUN_000186f0(float *a, float *b) throw();
Vec3 *__cdecl FUN_00083e00(Vec3 *out, Vec3 *a, float c) throw();
void __cdecl FUN_00224d70(float angle, Vec3 *v) throw();
Ent *__fastcall FUN_000592a0(void *owner) throw();

union Arg1 {
    int i;
    float f;
};

class RoutAction {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual bool vfunc_5(Arg1 a1, float dt);
    char pad04[0x18];
    Vec3 v1c;
    Vec3 v28;
    Cfg *f34;
    RefObj *f38;
    RefObj *f3c;
    char pad40[0x58 - 0x40];
    float f58;
    Stats *f5c;
    char pad60[0x6c - 0x60];
    float f6c;
    float f70;
    Mat m74;
};

bool RoutAction::vfunc_5(Arg1 a1, float dt)
{
    struct Frame {
        float thr;
        union {
            Hand *h;
            float r;
            float one;
            float pz;
        } u4;
        union {
            World *world;
            float c18;
            float c34;
            float q;
        } u8;
        Vec3 D;
        Vec3 P;
        Vec3 Out;
        Vec3 W;
        Vec3 B;
        Vec3 A;
        Vec3 R;
        Vec3 X60;
        Vec3 Y6c;
    } f;

    f.u8.world = DAT_004dd700;
    if (!(DAT_004e0d60 & 1)) {
        DAT_004e0d60 |= 1;
        DAT_004e0d58.FUN_0027af00();
        atexit(FUN_00363f20);
    }
    f6c = dt + f6c;
    if (a1.i != 0)
        return true;
    if (f38 == 0)
        return false;
    Stats *stats = f5c;
    if (stats == 0)
        return false;
    f.u4.h = stats->f1ca0;
    RefObj *obj = stats->f328;
    if (obj == 0) {
        obj = f3c;
        if (obj == 0)
            return true;
    }
    obj->AddRef();
    if (f3c != 0)
        f3c->Release();
    f3c = obj;
    if (obj == 0)
        return false;
    if (obj->f0c != 1)
        return false;
    Ent *tgt = obj->f08;
    if (tgt == 0)
        return false;
    stats = f5c;
    Sub *edi = (Sub *)((char *)stats + 0x1f58);
    if (edi == 0)
        return false;
    stats->FUN_00035160(&m74);
    f5c->f10->FUN_00059a50(&f.P);
    tgt->f10->FUN_00059a50(&f.D);
    f.D.x = f.D.x - f.P.x;
    f.D.y = f.D.y - f.P.y;
    f.D.z = f.D.z - f.P.z;
    tgt->FUN_00035660(&f.X60);
    float len = f.D.FUN_000111f0();
    if (len < f70) {
        double k = -1.0f / sqrt(len);
        f.R.x = 0.0f;
        f.R.y = 0.0f;
        f.R.z = 1.0f;
        f.D.x = f.D.x * k;
        f.D.y = f.D.y * k;
        f.D.z = f.D.z * k;
        m74.FUN_0022c3b0(&f.R, &f.Out);
        float dotF = f.Out.y * f.D.y + f.D.z * f.Out.z + f.Out.x * f.D.x;
        if (dotF > -0.99f) {
            float cross = f.Out.z * f.D.x - f.Out.x * f.D.z;
            if (cross > 0.0f)
                FUN_00224d70(-180.0f, &f.Out);
            else
                FUN_00224d70(180.0f, &f.Out);
        }
        edi->v11c = f.Out;
        edi->v10c = f.Out;
        edi->f118 = f34->f18;
    } else {
        edi->FUN_00060170();
    }
    Hand *h = f.u4.h;
    f.W.x = 0.0f;
    f.W.y = 0.0f;
    f.W.z = 0.0f;
    if (h != 0 && f34->b28 != 0) {
        if (h->b129 != 0)
            f.thr = f34->f30;
        else
            f.thr = f34->f2c;
        f.u4.r = FUN_0010b1c0(f.u8.world, f5c, f.thr, &f.W);
        if (f.u4.r < 0.0f || f.u4.r > f.thr) {
            h->b129 = 0;
            f.W.z = 0.0f;
            f.W.y = 0.0f;
            f.W.x = 0.0f;
        } else {
            h->b129 = 1;
            f.W.FUN_0022d110();
            f.u8.q = (f.thr - f.u4.r) / f.thr;
            f.u4.one = 1.0f;
            float rr = FUN_000186f0(&f.u4.one, &f.u8.q);
            ((Misc *)&f.W.y)->FUN_000344b0(rr);
        }
    }
    Cfg *cfg = f34;
    f.u8.c34 = cfg->f34;
    Vec3 *res = FUN_00083e00(&f.R, &edi->v10c, cfg->f34);
    float pzr = f.P.z + res->z;
    f.u4.pz = pzr;
    float pyr = f.P.y + res->y;
    float pxr = f.P.x + res->x;
    f.B.y = f.P.y;
    f.B.z = f.P.z;
    f.B.x = f.P.x;
    f.A.z = pzr;
    f.A.x = pxr;
    f.A.y = pyr + 1.0f;
    f.B.y = f.B.y + 1.0f;
    f.u8.c18 = cfg->f18;
    if (edi->f118 != 0.0f && f5c->f1ca4 != 0 && cfg->b28 != 0) {
        f.R.x = f.A.x - f.B.x;
        f.R.y = f.A.y - f.B.y;
        f.R.z = f.u4.pz - f.B.z;
        if (!f5c->f1ca4->FUN_0010aa90(DAT_004dd700, &f.B, &f.A, 1.0f, &f.Y6c, &f.Out, &f.R, f5c, obj, 1, 1)) {
            edi->FUN_00060170();
        } else if (!f5c->f1ca4->v4(&f.A, &f.B, f5c, DAT_004dd700, dt, &v1c, &f.W)) {
            edi->f118 = f.u8.c18;
        }
    }
    f.R.x = f.P.x - v28.x;
    f.R.y = f.P.y - v28.y;
    f.R.z = f.P.z - v28.z;
    f.u8.q = f.R.FUN_00018990();
    *(unsigned int *)&f.u8.q &= 0x7fffffff;
    Cfg *c = f34;
    if (f.u8.q / dt <= c->f24)
        f58 = dt + f58;
    else
        f58 = 0.0f;
    if (f58 > c->f20)
        return false;
    v28 = f.P;
    return true;
}
