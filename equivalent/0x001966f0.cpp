// STATUS: equivalent (tools/equiv.py level 3: 6052 inputs, branch coverage 116/116)
// hulkfight::motion::FireBeamAction::vfunc_3 @ 0x001966f0
// cl-flags: /GS
// equiv-map: ?thunk_FUN_0027d410@Obj64@@QAEXPAUKey@@@Z = 0x001d6630
#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"
extern "C" int atexit(void (*)());
int __cdecl FUN_00267760(char *buf, int n, const char *fmt, ...);
extern "C" int __cdecl FUN_0034483c();
void FUN_00363fa0();


struct Key {
    unsigned int lo, hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027b040(const char *name);
    void FUN_0027b0e0(const char *name);
};

struct V3_1966f0 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    char FUN_0022d2b0(V3_1966f0 *other, float eps);
    void FUN_00011220(V3_1966f0 *v);
};

struct Mat_1966f0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(V3_1966f0 *pos);
};

struct RefObj_1966f0 {
    virtual void AddRef();
    virtual void Release();
};
struct Other_1966f0;
struct Ref4c : RefObj_1966f0 {
    char pad4[4];
    Other_1966f0 *f08;
    int f0c;
};

struct Rng_1966f0 {
    unsigned int s0, s1;
    float FUN_00078780();
    int FUN_00011380(int a, int b);
};
Rng_1966f0 *__cdecl FUN_000964d0();

struct Locator {
    void FUN_00059a50(V3_1966f0 *out);
};

struct Sub74 {
    char pad[0x74];
    int f74;
};

struct Ent_1966f0 {
    Sub74 *FUN_001d72e0();
    int FUN_001d68d0();
};

struct Obj64 : RefObj_1966f0 {
    Sub74 *FUN_001d72e0();
    void thunk_FUN_0027d410(Key *k);
    void FUN_001d7590();
    void FUN_001d7810(V3_1966f0 v);
};

struct Mgr_1966f0 {
    void FUN_001e43b0(Key *k, void *src, Mat_1966f0 *m, int flag);
    Obj64 *FUN_001def30(char *name);
};

struct World {
    char pad0[0xc];
    Mgr_1966f0 *f0c;
    char pad10[0x20 - 0x10];
    struct Obj20 *f20;
};

struct Other_1966f0 {
    char pad0[0x8];
    unsigned int f08;
    unsigned int f0c;
    Locator *f10;
    char pad14[0x12c - 0x14];
    void *f12c;
    char pad130[0x140 - 0x130];
    int f140;
    void FUN_000356c0(V3_1966f0 *out);
    void FUN_00035550(V3_1966f0 *out);
};
struct Obj20 {
    char pad0[0x124];
    Other_1966f0 *f124;
};


struct IdObj {
    char pad0[8];
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};
struct Slot38 : RefObj_1966f0 {
    char pad4[4];
    IdObj *f08;
};

struct Pad_1966f0 {
    char pad0[0x10];
    Locator *f10;
    char pad14[0x120 - 0x14];
    Slot38 *f120;
    char pad124[0x328 - 0x124];
    RefObj_1966f0 *f328;
    char pad32c[0x1d54 - 0x32c];
    V3_1966f0 f1d54;
    unsigned int f1d60;
    unsigned int f1d64;
    Ent_1966f0 *FUN_00035ef0(int i);
    void FUN_0003ffa0(Sub74 *s, int z);
    void FUN_00035550(V3_1966f0 *out);
    void FUN_00035660(V3_1966f0 *out);
    void FUN_00124500(V3_1966f0 *out);
};

struct Beam {
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4();
    virtual void b5(); virtual void b6();
    virtual float v7();
    char pad04[0x2c - 4];
    int f2c;
    unsigned int f30;
    unsigned int f34;
    char pad38[0xc0 - 0x38];
    char fc0[8];
    V3_1966f0 fc8;
    V3_1966f0 fd4;
    char padd4x[0xec - 0xe0];
    float fec;
    char bf0;
    char padf1[3];
    float ff4;
    float ff8;
    char bfc;
    char padfd;
    char bfe;
    char padff;
    char pad100[0x118 - 0x100];
    float f118;
    V3_1966f0 *FUN_00192bb0(V3_1966f0 *v);
    V3_1966f0 *FUN_00192c70(V3_1966f0 *v);
    void FUN_00192ea0(V3_1966f0 *out);
};

struct Pad2 {
    char pad0[0x58];
};

extern Pad_1966f0 *__fastcall FUN_00059a30(void *o);
extern void *__fastcall FUN_000592a0(void *owner);
void __cdecl FUN_000188e0(void *slot, Ent_1966f0 *e);
void __cdecl FUN_00037510(void *slot, int v);
void __cdecl FUN_00018810(Ref4c **slot, RefObj_1966f0 *obj);
char __cdecl FUN_00065870(V3_1966f0 *a, V3_1966f0 *b);
V3_1966f0 *__cdecl FUN_00083e00(V3_1966f0 *out, V3_1966f0 *in, float s);
void __cdecl FUN_00224d70(float ang, V3_1966f0 *v);

struct Frame_1966f0 {
    V3_1966f0 delta;
    V3_1966f0 w;
    union RandBits { unsigned int u; float f; } rb;
    union { float len; Key key; V3_1966f0 c; } u1c;
    V3_1966f0 t;
    float m44;
    V3_1966f0 u;
    float arr[4];
    V3_1966f0 d;
    V3_1966f0 p0;
    V3_1966f0 vd;
    V3_1966f0 vc;
    V3_1966f0 va;
    V3_1966f0 vb;
    V3_1966f0 p3;
    Mat_1966f0 M;
    char buf[0x80];
};

static __forceinline void Step(float &w, float d, float t)
{
    if (d > 0.0f) {
        if (w > t)
            w = w - d;
        else if (w < t)
            w = d + w;
    } else {
        if (w < t)
            w = w - d;
        else if (w > t)
            w = d + w;
    }
}

template <class T>
static __forceinline float Rand1(Rng_1966f0 *r, T &slot)
{
    unsigned int a = r->s0;
    a = (a & 0xffff) * 0x9069 + (a >> 16);
    r->s0 = a;
    unsigned int b = r->s1;
    b = (b & 0xffff) * 0x4650 + (b >> 16);
    r->s1 = b;
    slot.u = ((r->s0 << 16) + (b & 0xffff)) & 0x7fffff | 0x3f800000;
    return slot.f;
}

class FireBeamAction {
public:
    char pad00[0x1c];
    Beam *f1c;
    void *f20;
    V3_1966f0 f24;
    char pad30[0x34 - 0x30];
    char f34[4];
    RefObj_1966f0 *f38;
    int f3c;
    char pad40[0x4c - 0x40];
    Ref4c *f4c;
    Other_1966f0 *f50;
    char pad54[4];
    unsigned int f58;
    unsigned int f5c;
    Sub74 *f60;
    Obj64 *f64;
    char pad68[0x6c - 0x68];
    V3_1966f0 f6c;
    V3_1966f0 f78;
    float f84;
    char pad88[0x90 - 0x88];
    int f90;

    char vfunc_3(int a1, int a2);
    char Body(Frame_1966f0 &f);
    __forceinline float Jitter(Frame_1966f0 &f, Rng_1966f0 *rng, int axis);
};

char FireBeamAction::vfunc_3(int a1, int a2)
{
    Frame_1966f0 f;
    char result = Body(f);
    f50 = 0;
    return result;
}

__forceinline float FireBeamAction::Jitter(Frame_1966f0 &f, Rng_1966f0 *rng, int axis)
{
    f.delta = f1c->fd4;
    return (Rand1(rng, f.rb) - 1.0f) * (axis == 1 ? f.delta.y : f.delta.z);
}

__forceinline char FireBeamAction::Body(Frame_1966f0 &f)
{
    Pad_1966f0 *a = 0;
    if (f20 != 0) {
        a = FUN_00059a30(FUN_000592a0(f20));
        Slot38 *s = a->f120;
        RefObj_1966f0 **pf38 = &f38;
        if (s)
            s->AddRef();
        if (*pf38)
            (*pf38)->Release();
        *pf38 = s;
        int idx = f1c->f2c;
        f84 = f1c->v7();
        if (!(f84 <= 0.0f)) {
            if (idx >= 0 && idx < 8) {
                Ent_1966f0 *e = a->FUN_00035ef0(idx);
                if (e) {
                    if (!e->FUN_001d72e0() || e->FUN_001d72e0()->f74 == 0)
                        FUN_000188e0(f34, e);
                    FUN_00037510(pf38, e->FUN_001d68d0());
                }
            }
            Slot38 *sl = (Slot38 *)f38;
            if (sl) {
                unsigned int lo = f1c->f30;
                unsigned int hi = f1c->f34;
                IdObj *io = sl->f08;
                if (lo | hi) {
                    f3c = io->FUN_0027b200(lo, hi);
                    if (f3c == 0xffff)
                        f3c = 0;
                }
            }
            FUN_00267760(f.buf, 0x80, "propSpawnBeam%d", DAT_004e16e4);
            Mgr_1966f0 *mg = DAT_004dd700->f0c;
            DAT_004e16e4 = DAT_004e16e4 + 1;
            a->f10->FUN_00059a50(&f.p0);
            f.M.FUN_0022b980();
            f.M.FUN_0022be40(&f.p0);
            f.u1c.key.FUN_0027b0e0(f.buf);
            mg->FUN_001e43b0(&f.u1c.key, f1c->fc0, &f.M, 1);
            f.u1c.key.FUN_0027af50();
            Obj64 *o = mg->FUN_001def30(f.buf);
            if (o)
                o->AddRef();
            if (f64)
                f64->Release();
            f64 = o;
            if (o) {
                if (!(DAT_004e16e0 & 1)) {
                    DAT_004e16e0 |= 1;
                    (*(Key*)&DAT_004e16d8).FUN_0027af00();
                    atexit(FUN_00363fa0);
                }
                (*(Key*)&DAT_004e16d8).FUN_0027b040("invisible");
                f64->thunk_FUN_0027d410(((Key*)&DAT_004e16d8));
                Sub74 *sub = f64->FUN_001d72e0();
                if (sub) {
                    FUN_00018810(&f4c, a->f328);
                    Ref4c *r4 = f4c;
                    if (r4->f0c == 1)
                        f50 = r4->f08;
                    if (f50 == 0) {
                        Other_1966f0 *w = DAT_004dd700->f20->f124;
                        if (w && w->f12c)
                            f50 = w;
                    }
                    f58 = f50->f08;
                    f5c = f50->f0c;
                    f.u1c.key.FUN_0027af10(f58, f5c);
                    a->f1d60 = f.u1c.key.lo;
                    a->f1d64 = f.u1c.key.hi;
                    f.u1c.key.FUN_0027af50();
                    f50->f10->FUN_00059a50(&f.p3);
                    a->FUN_0003ffa0(sub, 0);
                    f60 = sub;
                    a->FUN_00035550(&f.va);
                    a->FUN_00035660(&f.vb);
                    f.vb.FUN_0022d110();
                    f.va.FUN_0022d110();
                    Rng_1966f0 *rng = FUN_000964d0();
                    f90 = -1;
                    if (f50) {
                        a->FUN_00124500(&f.vc);
                        if (FUN_00065870(&f.vc, &f24)) {
                            f.vd = f.vc;
                        } else {
                            f50->f10->FUN_00059a50(&f.vd);
                        }
                        if (f50->f140 != 2)
                            f.vd.y = f.p0.y;
                        f.d.x = f.vd.x - f.p0.x;
                        f.d.y = f.vd.y - f.p0.y;
                        f.d.z = f.vd.z - f.p0.z;
                        f.u1c.len = f.d.FUN_00018990();
                        Beam *bm = f1c;
                        V3_1966f0 *src;
                        if (bm->bf0) {
                            f.m44 = bm->ff4;
                            if (bm->bfc) {
                                if (FUN_000964d0()->FUN_00011380(0, 1) != 1) {
                                    f90 = 1;
                                    f.m44 = f.m44 * -1.0f;
                                } else {
                                    f90 = -1;
                                }
                            } else {
                                f.m44 = f.m44 * bm->ff8;
                                f90 = -(int)bm->ff8;
                            }
                            f.u = f.d;
                            FUN_00224d70(f.m44, &f.u);
                            bm = f1c;
                            src = &f.u;
                        } else {
                            src = &f.va;
                        }
                        V3_1966f0 *step = FUN_00083e00((V3_1966f0 *)f.arr, src, bm->fec * f.u1c.len);
                        f.w.x = f.p0.x + step->x;
                        f.w.y = f.p0.y + step->y;
                        f.arr[2] = f.p0.z + step->z;
                        f.w.z = f.arr[2];
                        char onPath = FUN_00065870(bm->FUN_00192bb0((V3_1966f0 *)f.arr), &f24);
                        Beam *cur = f1c;
                        if (onPath) {
                            f.w.FUN_00011220(cur->FUN_00192bb0((V3_1966f0 *)f.arr));
                        } else if (FUN_00065870(cur->FUN_00192c70((V3_1966f0 *)f.arr), &f24)) {
                            f1c->FUN_00192ea0(&f.delta);
                            if (f50) {
                                a->f10->FUN_00059a50((V3_1966f0 *)f.arr);
                                f50->f10->FUN_00059a50(&f.t);
                                Step(f.w.x, f.delta.x, f.t.x);
                                Step(f.w.y, f.delta.y, f.t.y);
                                Step(f.w.z, f.delta.z, f.t.z);
                            }
                        }
                        f.u = f1c->fd4;
                        if (FUN_00065870(&f.u, &f24)) {
                            for (int i = 0; i < 4; i++) {
                                f.u = f1c->fd4;
                                f.arr[i] = rng->FUN_00078780() * f.u.x;
                            }
                            float Ax = (((f.arr[0] + f.arr[1]) + f.arr[2]) + f.arr[3]) * 0.25f;
                            f.delta = f1c->fd4;
                            float ya = (Rand1(rng, f.rb) - 1.0f) * f.delta.y;
                            f.delta = f1c->fd4;
                            float yb = (Rand1(rng, f.rb) - 1.0f) * f.delta.y;
                            f.delta = f1c->fd4;
                            float yc = (Rand1(rng, f.rb) - 1.0f) * f.delta.y;
                            f.delta = f1c->fd4;
                            float yd = (Rand1(rng, f.rb) - 1.0f) * f.delta.y;
                            float Ay = (((ya + yb) + yc) + yd) * 0.25f;
                            f.delta = f1c->fd4;
                            float ze = (Rand1(rng, f.rb) - 1.0f) * f.delta.z;
                            f.delta = f1c->fd4;
                            float zf = (Rand1(rng, f.rb) - 1.0f) * f.delta.z;
                            f.delta = f1c->fd4;
                            float zg = (Rand1(rng, f.rb) - 1.0f) * f.delta.z;
                            f.delta = f1c->fd4;
                            float zh = (Rand1(rng, f.rb) - 1.0f) * f.delta.z;
                            volatile float *azSlot = &f.arr[2];
                            *azSlot = (((ze + zf) + zg) + zh) * 0.25f;
                            f.w.x = Ax + f.w.x;
                            f.w.y = Ay + f.w.y;
                            f.w.z = *azSlot + f.w.z;
                        }
                        if (f1c->bf0) {
                            f.m44 = f1c->ff4;
                            if (f.m44 != 0.0f && f50) {
                                f.arr[0] = a->f1d54.x;
                                f.arr[1] = a->f1d54.y;
                                f.arr[2] = a->f1d54.z;
                                a->f10->FUN_00059a50(&f.d);
                                if (!((V3_1966f0 *)f.arr)->FUN_0022d2b0(&f24, 1e-005f)) {
                                    f.t = a->f1d54;
                                } else {
                                    f50->f10->FUN_00059a50(&f.t);
                                }
                                if (f50->f140 != 2)
                                    f.t.y = f.d.y;
                                f.u.x = f.t.x - f.d.x;
                                f.u.y = f.t.y - f.d.y;
                                f.u.z = f.t.z - f.d.z;
                                FUN_00224d70((float)f90 * f.m44, &f.u);
                                float k = f.u1c.len * f1c->fec;
                                // the original rounds the y and z products to floats (kept in the c slot), not x
                                volatile float *cy = &f.u1c.c.y;
                                volatile float *cz = &f.u1c.c.z;
                                *cy = f.u.y * k;
                                *cz = f.u.z * k;
                                f.delta.x = f.u.x * k + f.d.x;
                                f.delta.y = *cy + f.d.y;      // read the scratch slots before the
                                f.delta.z = *cz + f.d.z;      // copy below overwrites them
                                f.u1c.c = f1c->fc8;
                                V3_1966f0 *pick;
                                if (!f.u1c.c.FUN_0022d2b0(&f24, 1e-005f)) {
                                    pick = &f1c->fc8;
                                } else {
                                    f.u1c.c = f1c->fd4;
                                    if (f.u1c.c.FUN_0022d2b0(&f24, 1e-005f))
                                        pick = 0;
                                    else
                                        pick = &f1c->fd4;
                                }
                                if (pick) {
                                    f.delta.x = pick->x + f.delta.x;
                                    f.delta.y = pick->y + f.delta.y;
                                    f.delta.z = pick->z + f.delta.z;
                                }
                                f6c = f.delta;
                            }
                        } else if (f1c->bfe) {
                            Other_1966f0 *tg = f50;
                            if (tg) {
                                tg->f10->FUN_00059a50(&f.u);
                                f.delta.x = 0.0f;
                                f.delta.y = 0.0f;
                                f.delta.z = 0.0f;
                                tg->FUN_000356c0(&f.delta);
                                f.u1c.len = f.delta.FUN_0022d110();
                                if (f.u1c.len <= 0.0f)
                                    tg->FUN_00035550(&f.delta);
                                float sc = f.u1c.len * f1c->f118;
                                f.t = f.delta;
                                f.t.x = f.t.x * sc;
                                f.t.y = f.t.y * sc;
                                f6c.x = f.u.x + f.t.x;
                                f6c.y = f.u.y + f.t.y;
                                f6c.z = f.u.z + f.t.z * sc;
                            }
                        } else if (f50) {
                            f50->f10->FUN_00059a50(&f6c);
                        }
                    }
                    f64->FUN_001d7590();
                    f64->FUN_001d7810(f.w);
                    f78.x = f.w.x;
                    f78.y = f.w.y;
                    f78.z = f.w.z;
                    return 1;
                }
            }
        }
    }
    return 0;
}
