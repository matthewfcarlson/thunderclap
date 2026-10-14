// STATUS: equivalent (tools/equiv.py level 3: 3188 inputs, branch coverage 149/162, incomplete)
// FUN_001da540 @ 0x001da540
extern "C" int __cdecl FUN_0034483c();
extern "C" double __cdecl sqrt(double);

static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    void FUN_00011160(float s, V3 *d);
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

extern unsigned __int64 DAT_004e2548;

struct Entity;
struct Actor;

struct Ref : RefObj {
    int pad4;
    union {
        Entity *ent;
        Actor *act;
    };
    int type;
    char pad10[0x70 - 0x10];
    int f70;
};

struct Sub : RefObj {
    char pad[0x68];
    int f6c;
};

struct Request {
    int r00;
    int r04;
    V3 target;                 // 0x08
    char pad14[4];
    V3 aim;                    // 0x18
    char pad24[4];
    V3 dir;                    // 0x28
    char pad34[4];
    V3 vel;                    // 0x38
    char pad44[0x4c - 0x44];
    RefObj *f4c;
    RefObj *f50;
    float f54;
    char pad58[0x60 - 0x58];
    RefObj *f60;
    char pad64[0x78 - 0x64];
    float f78;
    float f7c;
    float f80;
    char pad84[0xb0 - 0x84];
    void FUN_00059820();
    void FUN_00059300();
};

struct Job : RefObj {
    Job *FUN_000598e0(void *a, Request *req);
    void FUN_00059790(Sub *s);
};

struct Handle {
    char FUN_00231ad0(void *sink, Job *job, int n);
};

struct Queue {
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual void q4(); virtual void q5(); virtual void q6(); virtual void q7();
    virtual Handle *Submit(Job *job, int n);
};

struct Ctrl {
    char pad0[0x14];
    int f14;
};

struct Hit {
    char pad0[0x40];
    V3 f40;
};

struct Owner3 {
    void *a;
    Ref *b;
    int c;
};

struct Pusher {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(V3 *pos, V3 *out, int n);
};

struct Obj70 {
    char pad0[0x10];
    Pusher *f10;
    char pad14[0x98 - 0x14];
    V3 v98;
};

struct Mid10 {
    char pad0[0x70];
    Obj70 *f70;
};

struct Holder {
    char pad0[0x10];
    Mid10 *f10;
};

struct Actor {
    char pad0[0x10];
    void **f10;
    char pad14[0xdc - 0x14];
    int fdc;
    char pade0[0x11c - 0xe0];
    Ctrl *f11c;
    char pad120[0x12c - 0x120];
    RefObj *f12c;
    char pad130[0x3a4 - 0x130];
    int f3a4;
    char FUN_000360f0();
    void FUN_0003a9d0(Sub *s);
    void FUN_000350c0(V3 *out);
    void FUN_00043ae0(Ref *a1, V3 *a2, float a3, float a4, float a5, int a6, int a7, int a8, Sub *a9);
    Hit *FUN_00039c60(V3 *pos, V3 *dir, float a3, float a4, int a5, Owner3 *o, int a7);
};

struct Ready {
    int FUN_001d4de0();
    int FUN_001d5e80(int v);
    unsigned __int64 FUN_001d4f70();
};

struct Mover {
    void FUN_00083320(V3 *a, V3 *b, float c, char airborne, V3 *e, char forced);
};

struct Ray {
    char FUN_00201e00(V3 *a, V3 *b, int c, V3 *d, V3 *e, int f, int g);
};

struct Sink30 {
    void FUN_001cbd10(const char *s);
};

struct Fx34;

struct Reqs {
    Mover *FUN_0007ad00(void *p);
};

struct World {
    char pad0[0x24];
    Ray *p24;
    char pad28[0x30 - 0x28];
    Sink30 *p30;
    Fx34 *p34;
    char pad38[0x4c - 0x38];
    Reqs *p4c;
};
extern World *DAT_004dd700;

struct Sub1a4 {
    char FUN_001b6e90(Ref *a);
    void FUN_001b6e60(Ref *a);
    void FUN_001b6de0(Ref *a);
};

struct Sub240 {
    char pad[8];
};

class Entity;

struct Fx34 {
    void FUN_001ebd80(Entity *e, const char *name, float v, int z);
};

extern "C" int __cdecl FUN_00266da0(int mode);
void *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj **slot, RefObj *obj);
void __cdecl FUN_00224d70(float ang, V3 *v);
void __cdecl FUN_00096b50(Ref *a1, V3 *out, int *count);
int __cdecl FUN_00097a30(float a1, float a2, float a3, void *a4, float a5, V3 *a6, float a7, V3 *a8, int a9, int a10, int a11, int a12);

class Entity {
public:
    char pad000[0x40];
    int f40;
    char pad44[0xa0 - 0x44];
    Holder *f0a0;
    char pad0a4[0xb0 - 0xa4];
    char b0b0;
    char pad0b1[0xec - 0xb1];
    Ready *ready;
    char pad0f0[0x110 - 0xf0];
    char b110;
    char pad111[3];
    Ref *f114;
    Ref *f118;
    char pad11c[0x148 - 0x11c];
    Actor *f148;
    char pad14c[1];
    char b14d;
    char pad14e[0x1a4 - 0x14e];
    Sub1a4 s1a4;
    char pad1a5[0x1c9 - 0x1a5];
    char b1c9;
    char pad1ca[0x1fc - 0x1ca];
    Ref *f1fc;
    V3 v200;
    V3 v20c;
    float f218;
    Ref *f21c;
    float f220;
    int f224;
    float f228;
    float f22c;
    float f230;
    float f234;
    Queue *p238;
    char pad23c[4];
    Sub240 s240;
    int f248;

    void FUN_001d82d0();
    void FUN_001d6ec0(int a, Ref *b, int c);
    int FUN_001d73f0();
    Sub *FUN_001d72e0();
    char FUN_001d7300();
    void FUN_001d86d0(V3 *v, V3 *w);
    void FUN_001d66b0(V3 *a, V3 *b);
    void FUN_001d8100();
    void FUN_001d8c70(Hit *h);
    void FUN_001d8cd0();
    void FUN_001d8d90(int a);
    void FUN_001d71e0(int a);
    char FUN_001da350(Ref *a1, V3 *a2, V3 *a3, float a4, void *a5, float a6, int a7, float a8, float a9,
                      float a10, float a11, Queue *a12, Sub240 *a13);
    int FUN_001da540(Ref *a1, V3 *a2, V3 *a3, float a4);
};

struct Frame {
    char pad0[2];
    char b12;
    char b13;
    union { Actor *p14; float F; } u14;
    V3 v;
    char pad14[3];
    char flagA;
    union { int saved; int cntOut; float flagF; } u18;
    char pad1c[3];
    char flagB;
    V3 v2;
    V3 w;
    V3 pos;
    Sub1a4 *volatile sp;
    Owner3 own;
    union {
        Request req;
        struct { char pad[0x98]; V3 t0; V3 t1; } t;
    } rq;
    V3 t2;
};

int Entity::FUN_001da540(Ref *a1, V3 *a2, V3 *a3, float a4)
{
    Frame f;
    if (s1a4.FUN_001b6e90(a1))
        return 1;

    f.b12 = 0;
    f.b13 = 1;
    f.u14.p14 = 0;

    if (a1 != 0) {
        Ref *r = f21c;
        if (r && r->type == 5 && a1->type == 1) {
            Ref *k = (Ref *)r->ent->f114;
            if (k) {
                Actor *aa = a1->act;
                if (aa && (Ref *)aa->f12c == k)
                    a1 = r;
            }
        }

        Actor *tgt = 0;
        if (a1->type == 5) {
            Entity *o = a1->ent;
            if (o) {
                f.u14.p14 = o->f148;
                if (f.u14.p14) {
                    tgt = f.u14.p14;
                } else {
                    if (o->f114 == f1fc)
                        return 1;
                    if (o->b1c9 && o->f1fc == f1fc)
                        return 1;
                    o->FUN_001d82d0();
                    if (f230 > 0.0f)
                        o->FUN_001d6ec0((int)f230, f1fc, 0);
                    int lvl = o->FUN_001d73f0();
                    if (lvl <= -10)
                        f.b13 = 0;
                    if (!o->b0b0 && (a1->f70 != 0 || (b110 && lvl <= -10))) {
                        f.b12 = 0;
                    } else {
                        f.b12 = 1;
                        f.b13 = 1;
                    }
                    if (o->b14d && o->FUN_001d72e0()->f6c == 0) {
                        Mover *m = DAT_004dd700->p4c->FUN_0007ad00((char *)o + 8);
                        if (m) {
                            f.v = v200;
                            f.v.FUN_0022d110();
                            f.v.x = f.v.x * f22c;
                            f.v.y = f.v.y * f22c;
                            f.v.z = f.v.z * f22c;
                            m->FUN_00083320(a2, a3, a4, 1, &f.v, 0);
                        }
                    } else if (f22c > 0.0f && o->FUN_001d7300() && o->f114 == 0) {
                        f.v = v200;
                        f.v.FUN_0022d110();
                        f.v.x = f.v.x * f22c;
                        f.v.y = f.v.y * f22c;
                        f.v.z = f.v.z * f22c;
                        o->FUN_001d86d0(&f.v, a2);
                        if (o->ready->FUN_001d4f70() == DAT_004e2548)
                            DAT_004dd700->p30->FUN_001cbd10("golf_stroke");
                    }
                }
            }
        } else if (a1->type == 1) {
            f.u14.p14 = a1->act;
            tgt = f.u14.p14;
        }

        if (tgt) {
            f.u18.saved = FUN_00266da0(0xd);
            int mode = tgt->f11c->f14;
            f.b12 = (mode == 3 || mode == 2);
            f.b13 = (mode != 0);
            if (!tgt->FUN_000360f0()) {
                Handle *slot = 0;
                if (p238) {
                    if (tgt->f3a4 == 0)
                        tgt->FUN_0003a9d0(FUN_001d72e0());
                    f.rq.req.FUN_00059820();
                    f.rq.req.target = *a2;
                    f.rq.req.aim = *a3;
                    f.rq.req.dir = v200;
                    f.rq.req.f54 = f234;
                    f.rq.req.f7c = f228;
                    f.rq.req.f78 = f230;
                    f.rq.req.vel = v200;
                    f.rq.req.f80 = 1.0f;
                    f.rq.req.vel.FUN_0022d110();
                    f.rq.req.vel.x = f.rq.req.vel.x * f22c;
                    f.rq.req.vel.y = f.rq.req.vel.y * f22c;
                    f.rq.req.vel.z = f.rq.req.vel.z * f22c;
                    FUN_00018810(&f.rq.req.f60, FUN_001d72e0());
                    if (f1fc)
                        FUN_00018810(&f.rq.req.f4c, f1fc);
                    FUN_00018810(&f.rq.req.f50, tgt->f12c);
                    Job *job = (Job *)FUN_0008d690(0xb0);
                    if (job)
                        job = job->FUN_000598e0(*tgt->f10, &f.rq.req);
                    job->AddRef();
                    job->FUN_00059790(FUN_001d72e0());
                    slot = p238->Submit(job, 0);
                    if (slot)
                        slot->FUN_00231ad0(&tgt->fdc, job, -1);
                    job->Release();
                    f.rq.req.FUN_00059300();
                }
                if (!slot) {
                    if (f1fc != a1 && f118 != a1) {
                        f.w.x = 0.0f;
                        f.w.y = 0.0f;
                        f.w.z = 0.0f;
                        tgt->FUN_000350c0(&f.w);
                        f.w.FUN_00011160(-1.0f, &v200);
                        tgt->FUN_00043ae0(f1fc, &f.w, f22c + 90.0f, f234, f230, 0, 0, 1, FUN_001d72e0());
                    }
                }
            }
            FUN_00266da0(f.u18.saved);
        }
    }

    FUN_001d66b0(a2, a3);
    DAT_004dd700->p34->FUN_001ebd80(this, "impact_big", 100.0f, 0);
    f.sp = &s1a4;
    f.sp->FUN_001b6e60(a1);
    int kind = ready->FUN_001d4de0();
    int k = ready->FUN_001d5e80(f40);
    char bl = (kind == 5);
    f.flagA = (k == 3);
    f.flagB = (k == 2);
    if (f.flagA && a1 == f21c) {
        FUN_001d8100();
        if (f21c) {
            f21c->Release();
            f21c = 0;
        }
    }

    if (f228 < 0.8f || !bl) {
        int k2 = ready->FUN_001d5e80(f40);
        float m = 1.0f;
        if (k2 == 3)
            m = 0.01f;
        if (k2 == 2)
            m = m * 0.025f;
        bl = f.b13;
        m = m * f230;
        if (!bl) {
            if (f.u14.p14)
                m = m * 0.25f;
            else
                m = m * 0.1f;
        }
        int n = (int)m;
        if (n > 0)
            FUN_001d6ec0(n, f1fc, 0);
    } else {
        bl = f.b13;
    }

    Actor *victim = 0;
    if (f1fc && f1fc->type == 1)
        victim = f1fc->act;
    int cnt = f224;
    if (cnt > 0 && victim) {
        if (bl || f.u14.p14 || f.b12) {
            f224 = cnt - 1;
            f.pos.x = 0.0f;
            f.pos.y = 0.0f;
            f.pos.z = 0.0f;
            Mid10 *m10 = f0a0 ? f0a0->f10 : 0;
            Obj70 *o70 = m10->f70;
            f.pos = o70->v98;
            f.w.x = 0.0f;
            f.w.y = 0.0f;
            f.w.z = 0.0f;
            o70->f10->v8(&o70->v98, &f.w, -1);
            f.v.x = f.w.x;
            f.v.y = f.w.y;
            f.v.z = f.w.z;
            if (AbsF(f.w.y) < 1.0f)
                f.v.y = 0.0f;
            f.v.FUN_0022d110();
            if (v20c.y < 0.0f)
                FUN_00224d70(0.78539818525314331f, &f.v);
            else
                FUN_00224d70(-0.78539818525314331f, &f.v);
            if (f224 > 0) {
                f.u18.cntOut = 0;
                FUN_00096b50(a1, &f.rq.t.t0, &f.u18.cntOut);
                int c = (f.u18.cntOut < 100) ? 0 : 100;
                f.own.a = f0a0 ? f0a0->f10 : 0;
                f.own.b = a1;
                f.own.c = 0;
                Hit *hit = victim->FUN_00039c60(&f.pos, &f.v, 3.14159274f, 50.0f, c, &f.own, 0);
                if (hit) {
                    f.v2.x = f.v.x;
                    f.v2.y = f.v.y;
                    f.v2.z = f.v.z;
                    f.u14.F = v200.FUN_00018990();
                    if (FUN_00097a30(f.u14.F, f220, -1.0f, hit, 1.0f, &f.pos, 0, &f.v2, 0, 0, 0, 1)) {
                        if (!DAT_004dd700->p24->FUN_00201e00(&f.pos, &hit->f40, 1, &f.rq.t.t1, &f.t2, 0, 0)) {
                            FUN_001d8c70(hit);
                            f.v2.x = f.v2.x * f.u14.F;
                            f.v2.y = f.v2.y * f.u14.F;
                            f.v2.z = f.v2.z * f.u14.F;
                            FUN_001da350(f1fc, &f.v2, &v20c, 50.0f, hit, f220, f224, f228, f22c, f230,
                                         f234, p238, &s240);
                            return 1;
                        }
                    }
                }
            }
            f.v2.x = f.v.x;
            f.v2.y = f.v.y;
            f.v2.z = f.v.z;
            f.u14.F = (float)sqrt(v200.x * v200.x + v200.y * v200.y + v200.z * v200.z);
            f.u18.flagF = f.flagB ? 1.0f : 0.0f;
            FUN_00097a30(f.u14.F, f220, -1.0f, f1fc, f.u18.flagF, &f.pos, 0.52359879016876221f, &f.v2,
                         0, 0, 0, 1);
            f.v2.x = f.v2.x * f.u14.F;
            f.v2.y = f.v2.y * f.u14.F;
            f.v2.z = f.v2.z * f.u14.F;
            FUN_001da350(f1fc, &f.v2, &v20c, 100.0f, f1fc, f220 * 3.0f, 1, f228, f22c, f230, f234, p238,
                         &s240);
            FUN_001d71e0(0);
            f.sp->FUN_001b6de0(f1fc);
            return 1;
        }
    }

    if (!(f218 <= 0.0f) && f.flagA) {
        if (!f.b12)
            return 1;
        f248 = 1;
        return 0;
    }
    if (cnt > 0 && !bl && !f.b12 && !f.u14.p14)
        return 1;
    FUN_001d8cd0();
    if (bl) {
        FUN_001d8d90(0);
        FUN_001d71e0(0);
    }
    return 0;
}
