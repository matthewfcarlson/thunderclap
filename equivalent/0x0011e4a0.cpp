// STATUS: equivalent (tools/equiv.py level 3: 20188 inputs, branch coverage 240/259, incomplete)
// hulkfight::ai::PathAction::vfunc_5 @ 0x0011e4a0
extern "C" int atexit(void (*)());

struct V3_11e4a0 {
    float x, y, z;
    float FUN_0022d110() throw();
    float FUN_00018990() throw();
    void FUN_000344b0(float s) throw();   // scale in place
};

struct Key_11e4a0 {
    unsigned int lo, hi;
    void FUN_0027af00() throw();
    void FUN_0027b040(const char *s) throw();
};

class RefObj_11e4a0 {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
    char pad04[4];
    struct Stats_11e4a0 *f08;
    int f0c;
    char pad10[0x40 - 0x10];
    V3_11e4a0 v40;
};

struct Info_11e4a0 {
    char pad[0x140];
    int f140;
};

struct Fighter_11e4a0 {
    Info_11e4a0 *FUN_00059a30() throw();
    void FUN_00059a50(V3_11e4a0 *out) throw();
};

struct Sub11c_11e4a0 {
    char pad[0x1b0];
    int f1b0;
    char pad1b4[0x380 - 0x1b4];
    int f380;
};

struct HubMid {
    char pad[0x11c];
    Sub11c_11e4a0 *f11c;
    char pad120[0x12c - 0x120];
    RefObj_11e4a0 *f12c;
};

struct HubSub20 {
    char pad[0x124];
    HubMid *f124;
    void FUN_00025260(int a, int b, int c) throw();
};

struct List_11e4a0 {
    char pad[0x14];
    int count;
    V3_11e4a0 *FUN_00106160(int i) throw();
};

struct Reg18 {
    List_11e4a0 *FUN_00106230(int key) throw();
};

struct Locator {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual V3_11e4a0 *v8(V3_11e4a0 *out) throw();
};

struct Reg28 {
    const char *FUN_001ff950(V3_11e4a0 pos, int a, int b, float lo, float hi) throw();
    Locator *FUN_001fc8c0(unsigned __int64 id) throw();
};

struct Mgr_11e4a0 {
    void FUN_001dcf60(int a) throw();
};

struct Hub1c_11e4a0 {
    char FUN_001ae2c0(V3_11e4a0 *a, V3_11e4a0 *b, V3_11e4a0 *c, float f1, float f2, float f3, int i1, int i2, int i3, int i4, int i5, float t, float u) throw();
};

struct Bounds_11e4a0 {
    int FUN_00088fa0() throw();
    int FUN_00088fb0() throw();
};
struct Viewport_11e4a0 {
    char pad[0x80];
    Bounds_11e4a0 bounds;
};
struct Hub54 {
    Viewport_11e4a0 *FUN_00086310() throw();
};

struct Hub_11e4a0 {
    char pad0[0xc];
    Mgr_11e4a0 *f0c;
    char pad10[8];
    Reg18 *f18;
    Hub1c_11e4a0 *f1c;
    HubSub20 *f20;
    char pad24[4];
    Reg28 *f28;
    char pad2c[0x54 - 0x2c];
    Hub54 *f54;
};

struct Stats_11e4a0;

class Sink_11e4a0 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual char v4(V3_11e4a0 *a, V3_11e4a0 *b, Stats_11e4a0 *s, Hub_11e4a0 *w, float dt, void *c, V3_11e4a0 *d) throw();
    char FUN_0010aa90(Hub_11e4a0 *w, V3_11e4a0 *b, V3_11e4a0 *a, float k, V3_11e4a0 *o1, V3_11e4a0 *o2, V3_11e4a0 *r, Stats_11e4a0 *s, RefObj_11e4a0 *obj, int p, int q) throw();
};

struct SpecialSub_11e4a0 {
    char pad[0x46];
    char b9e;
    char pad9f;
    unsigned __int64 id;
};

struct Special_11e4a0 {
    char pad0[0x58];
    SpecialSub_11e4a0 sub;
    char padA8[0x129 - 0xa8];
    char b129;
};

struct Stats_11e4a0 {
    char pad0[0x10];
    Fighter_11e4a0 *f10;
    char pad14[0x11c - 0x14];
    Sub11c_11e4a0 *f11c;
    char pad120[0x328 - 0x120];
    RefObj_11e4a0 *f328;
    char pad32c[0x1a60 - 0x32c];
    V3_11e4a0 v1a60;
    char pad1a6c[0x1ca0 - 0x1a6c];
    Special_11e4a0 *f1ca0;
    Sink_11e4a0 *f1ca4;
    char pad1ca8[0x1d44 - 0x1ca8];
    float f1d44;
    float f1d48;
    char pad1d4c[0x1d70 - 0x1d4c];
    unsigned __int64 id1d70;
    char pad1d78[0x2064 - 0x1d78];
    V3_11e4a0 outB;
    float speed;
    V3_11e4a0 outA;
    char pad2080[0x20a8 - 0x2080];
    int f20a8;
    char pad20ac[0x2149 - 0x20ac];
    char b2149;
    void FUN_00035550(V3_11e4a0 *out) throw();
    int FUN_00036d30() throw();
    void FUN_00036e70(Key_11e4a0 *k, int v) throw();
    void FUN_0003ffa0(RefObj_11e4a0 *t, int z) throw();
};

class Cfg_11e4a0 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual float v7() throw();
    char pad04[0x10];
    float f14;
    char pad18[0x34 - 0x18];
    float f34;
    char pad38[4];
    char b3c;
    char b3d;
    char pad3e[2];
    int id40Lo;
    int id40Hi;
    char b48;
    char b49;
    char pad4a[2];
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
};

struct Clock_11e4a0 {
    float FUN_00066280() throw();
};

extern Hub_11e4a0 *DAT_004dd700;
extern int DAT_004d2a3c;
extern char DAT_00554c1c;
extern float DAT_00554c18;
extern int DAT_004e0d30;
extern Key_11e4a0 DAT_004e0d38;
extern unsigned int DAT_004e0d40;
extern int DAT_004e0ce8;
extern int DAT_004e0cec;
extern int DAT_004e0cf0;
extern int DAT_004e0cf4;
extern int DAT_004e0cf8;
extern int DAT_004e0cfc;
extern int DAT_004e0d00;
extern int DAT_004e0d04;
extern int DAT_004e0d08;
extern int DAT_004e0d0c;
extern int DAT_004e0d10;
extern int DAT_004e0d14;
extern int DAT_004e0d18;
extern int DAT_004e0d1c;
extern int DAT_004e0d20;
extern int DAT_004e0d24;
extern int DAT_004e0d28;
extern int DAT_004e0d2c;

void FUN_00363f00();
unsigned __int64 __cdecl FUN_0027b020(const char *s) throw();
char __cdecl FUN_00018960(float a, float b, float eps) throw();
float __cdecl FUN_000186f0(float *a, float *b) throw();
float __cdecl FUN_0010b1c0(Hub_11e4a0 *w, Stats_11e4a0 *s, float thr, V3_11e4a0 *out) throw();
char __cdecl FUN_00036b10(Hub_11e4a0 *w, V3_11e4a0 *a, V3_11e4a0 *b, V3_11e4a0 *c, V3_11e4a0 *d, char *e, char *f) throw();
Clock_11e4a0 *FUN_000678d0() throw();

union FloatBits_11e4a0 {
    float f;
    unsigned int u;
};

namespace hulkfight {
namespace ai {
class PathAction {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual char vfunc_5(int a, float dt);
    char pad04[0x18];
    char b1c;
    char b1d;
    char pad1e[2];
    V3_11e4a0 v20;
    V3_11e4a0 v2c;
    char pad38[0x64 - 0x38];
    V3_11e4a0 v64;
    char pad70[4];
    int mode;
    char pad78[4];
    int f7c;
    V3_11e4a0 f80;
    Cfg_11e4a0 *p8c;
    void *p90;
    RefObj_11e4a0 *p94;
    char pad98[0xc8 - 0x98];
    Stats_11e4a0 *owner;
    char padcc[4];
    int idLo;
    int idHi;
    char d8;
    char padd9[3];
    float fdc;
    Reg28 *e0;
    float fe4;
    int fe8;
    int fec;
};

char PathAction::vfunc_5(int a, float dt)
{
    struct Frame {
        V3_11e4a0 V10;
        union {
            V3_11e4a0 *p;
            float f;
            int i;
        } u1c;
        char pad20[3];
        char B23;
        V3_11e4a0 V24;
        V3_11e4a0 A30;
        union {
            Locator *loc;
            float f;
        } u3c;
        V3_11e4a0 B40;
        union {
            Hub_11e4a0 *hub;
            float s;
        } u4c;
        union {
            float f;
            int i;
        } u50;
        V3_11e4a0 V54;
        V3_11e4a0 W;
        RefObj_11e4a0 *th;
        float A;
        Special_11e4a0 *sp;
        union {
            int i;
            float f;
        } u78;
        char pad7c[2];
        char b7e;
        char b7f;
        V3_11e4a0 Vec80;
        V3_11e4a0 V8c;
        V3_11e4a0 V98;
        int g88fa0;
        V3_11e4a0 Va8;
        V3_11e4a0 Vb4;
        V3_11e4a0 Vc0;
        V3_11e4a0 Vcc;
        V3_11e4a0 Vd8;
    } f;

    f.u4c.hub = DAT_004dd700;
    if ((DAT_004e0d40 & 1) == 0) {
        DAT_004e0d40 |= 1;
        DAT_004e0d38.FUN_0027af00();
        atexit(FUN_00363f00);
    }
    f.u50.i = 1;
    if (owner != 0)
        f.u50.i = owner->f11c->f380;
    fdc = dt + fdc;
    if (a != 0)
        return 1;
    if (p90 == 0)
        return 0;
    if (owner == 0)
        return 0;

    f.g88fa0 = DAT_004dd700->f54->FUN_00086310()->bounds.FUN_00088fa0();
    f.u78.i = DAT_004dd700->f54->FUN_00086310()->bounds.FUN_00088fb0();
    f.sp = owner->f1ca0;
    f.A = 0.0f;
    f.A30.x = 0.0f;
    f.A30.y = 0.0f;
    f.A30.z = 0.0f;
    f.B40.x = 0.0f;
    f.B40.y = 0.0f;
    f.B40.z = 0.0f;
    f.W.x = 0.0f;
    f.W.y = 0.0f;
    f.W.z = 0.0f;
    owner->FUN_00035550(&f.A30);
    f.B40 = f.A30;
    v20 = owner->v1a60;

    RefObj_11e4a0 *th = owner->f328;
    f.th = th;
    if (th == 0) {
        th = p94;
        f.th = th;
        if (th == 0) {
            if (owner->f20a8 >= 0)
                return 1;
            Sub11c_11e4a0 *s1 = owner->f11c;
            if (s1 == 0)
                return 1;
            HubMid *mid = f.u4c.hub->f20->f124;
            if (mid == 0)
                return 1;
            RefObj_11e4a0 *cand = mid->f12c;
            if (cand == 0)
                return 1;
            Sub11c_11e4a0 *s2 = mid->f11c;
            if (s2 == 0)
                return 1;
            if (s1->f1b0 == s2->f1b0)
                return 1;
            owner->FUN_0003ffa0(cand, 0);
            f.th = cand;
        }
    }
    th = f.th;
    if (th != 0)
        th->AddRef();
    if (p94 != 0)
        p94->Release();
    p94 = th;

    if (d8 != 0) {
        if (!(idLo == DAT_004e0d18 && idHi == DAT_004e0d1c)) {
            if (fdc > 5.0f) {
                d8 = 0;
                fdc = 0.0f;
            }
        }
        f.W.x = v2c.x - v20.x;
        f.W.y = 0.0f;
        f.W.z = v2c.z - v20.z;
        float len = f.W.FUN_0022d110();
        if (fe4 == 0.0f || len < fe4)
            fe4 = len;
        if (owner->f11c->f1b0 != 3) {
            if (len - 0.2f > fe4)
                return 0;
        }
        if (len <= p8c->f14)
            return 0;
    }

    char al = d8;
    if (al == 0 && idLo == DAT_004e0d08 && idHi == DAT_004e0d0c) {
        owner->f10->FUN_00059a50(&f.V54);
        owner->b2149 = 1;
        Reg18 *r18 = f.u4c.hub->f18;
        List_11e4a0 *list = r18->FUN_00106230(owner->FUN_00036d30());
        if (list == 0) {
            DAT_004e0d38.FUN_0027b040("waypoint_failed");
            owner->FUN_00036e70(&DAT_004e0d38, 1);
            return 0;
        }
        V3_11e4a0 *first = list->FUN_00106160(fec);
        f.V10.x = first->x;
        f.V10.y = first->y;
        f.V10.z = first->z;
        f.u1c.p = first;
        owner->f10->FUN_00059a50(&f.V24);
        f.V10.x = f.V10.x - f.V24.x;
        f.V10.y = f.V10.y - f.V24.y;
        f.V10.z = f.V10.z - f.V24.z;
        f.u3c.f = f.V10.FUN_00018990();
        f.u50.i = list->count;
        for (int i = 1; i < f.u50.i; i++) {
            V3_11e4a0 *p = list->FUN_00106160(i);
            float px = p->x;
            float py = p->y;
            f.V10.z = p->z;
            f.V10.x = px - f.V24.x;
            f.V10.y = py - f.V24.y;
            f.V10.z = f.V10.z - f.V24.z;
            float d = f.V10.FUN_00018990();
            if (d < f.u3c.f && d > 0.01) {
                f.u3c.f = d;
                fec = i;
            }
        }
        V3_11e4a0 *pick;
        if (fec != 0)
            pick = list->FUN_00106160(fec);
        else
            pick = f.u1c.p;
        v2c = *pick;
        b1d = 0;
        d8 = 1;
        b1c = 1;
    } else if (th != 0 && (al == 0 || p8c->v7() < 0.0f)) {
        if (th->f0c == 1)
            f.V10 = th->f08->v1a60;
        else
            f.V10 = th->v40;
        int lo = idLo;
        int hi = idHi;
        bool ok = true;
        if (lo == DAT_004e0cf8 && hi == DAT_004e0cfc) {
            v2c = f.V10;
        } else if (lo == DAT_004e0ce8 && hi == DAT_004e0cec) {
            Locator *loc = 0;
            const char *pt = e0->FUN_001ff950(v20, 2, 0, -3.40282347e+38f, 3.40282347e+38f);
            if (pt != 0)
                loc = e0->FUN_001fc8c0(FUN_0027b020(pt));
            if (loc != 0) {
                V3_11e4a0 *q = loc->v8(&f.V54);
                v2c = *q;
            } else {
                f.u50.f = -1.0f;
                f.u3c.loc = 0;
                for (int i = 0; i < 6; i++) {
                    f.V24.z = 0.0f;
                    f.V24.y = 0.0f;
                    f.V24.x = 0.0f;
                    Reg28 *r = DAT_004dd700->f28;
                    if (r != 0) {
                        const char *p2 = r->FUN_001ff950(v20, i, 0, -4.0f, 4.0f);
                        if (p2 != 0) {
                            Locator *l2 = DAT_004dd700->f28->FUN_001fc8c0(FUN_0027b020(p2));
                            if (l2 != 0) {
                                V3_11e4a0 *q = l2->v8(&f.Va8);
                                float qx = q->x;
                                float qy = q->y;
                                f.V54.z = q->z;
                                f.V24.x = v20.x - qx;
                                f.V24.y = v20.y - qy;
                                f.V24.z = v20.z - f.V54.z;
                                float d = f.V24.FUN_00018990();
                                if (f.u50.f < 0.0f || d < f.u50.f) {
                                    f.u50.f = d;
                                    f.u3c.loc = l2;
                                }
                            }
                        }
                    }
                }
                if (f.u3c.loc == 0) {
                    DAT_004e0d38.FUN_0027b040("intersect_failed");
                    owner->FUN_00036e70(&DAT_004e0d38, 1);
                    ok = false;
                } else {
                    V3_11e4a0 *q = f.u3c.loc->v8(&f.Va8);
                    v2c = *q;
                }
            }
        } else if (lo == DAT_004e0d00 && hi == DAT_004e0d04) {
            const char *pt = e0->FUN_001ff950(v20, 2, 2, -3.40282347e+38f, 3.40282347e+38f);
            Locator *loc = 0;
            if (pt != 0)
                loc = e0->FUN_001fc8c0(FUN_0027b020(pt));
            if (loc == 0) {
                DAT_004e0d38.FUN_0027b040("intersect_failed");
                owner->FUN_00036e70(&DAT_004e0d38, 1);
                ok = false;
            } else {
                V3_11e4a0 *q = loc->v8(&f.Va8);
                v2c = *q;
            }
        } else if (lo == DAT_004e0d20 && hi == DAT_004e0d24) {
            const char *pt = e0->FUN_001ff950(f.V10, 2, 0, -3.40282347e+38f, 3.40282347e+38f);
            Locator *loc = 0;
            if (pt != 0)
                loc = e0->FUN_001fc8c0(FUN_0027b020(pt));
            if (loc == 0) {
                ok = false;
            } else {
                V3_11e4a0 *q = loc->v8(&f.Va8);
                v2c = *q;
            }
        } else if (lo == DAT_004e0cf0 && hi == DAT_004e0cf4) {
            Locator *loc;
            Cfg_11e4a0 *c = p8c;
            if (c->b3d != 0)
                loc = e0->FUN_001fc8c0(owner->id1d70);
            else if (c->b3c != 0 && f.sp != 0 && &f.sp->sub != 0)
                loc = e0->FUN_001fc8c0(f.sp->sub.id);
            else
                loc = e0->FUN_001fc8c0(*(unsigned __int64 *)&c->id40Lo);
            if (loc == 0) {
                DAT_004e0d38.FUN_0027b040("locator_failed");
                owner->FUN_00036e70(&DAT_004e0d38, 1);
                ok = false;
            } else {
                V3_11e4a0 *q = loc->v8(&f.Va8);
                v2c = *q;
            }
        } else if (lo == DAT_004e0d10 && hi == DAT_004e0d14) {
            if (owner->f10->FUN_00059a30()->f140 != 1)
                return 1;
            owner->f10->FUN_00059a50(&f.V54);
            f.V24 = v2c;
            if (DAT_004dd700->f1c->FUN_001ae2c0(&v2c, &f.V54, &f.V10, 1.0f, 1000.0f, 180.0f, 1, 1, 2, f.u50.i, 0, 0.0f, 0.0f) == 0) {
                v2c = f.V24;
                DAT_004e0d38.FUN_0027b040("retreat_failed");
                owner->FUN_00036e70(&DAT_004e0d38, 1);
                ok = false;
            }
        } else if (lo == DAT_004e0d18 && hi == DAT_004e0d1c) {
            if (owner->f10->FUN_00059a30()->f140 != 1)
                return 1;
            owner->f10->FUN_00059a50(&f.V54);
            f.V24 = v2c;
            if (DAT_004dd700->f1c->FUN_001ae2c0(&v2c, &f.V54, &f.V10, 10.0f, 200.0f, 360.0f, 1, 0, 2, f.u50.i, 1, 0.0f, 0.0f) == 0) {
                v2c = f.V24;
                DAT_004e0d38.FUN_0027b040("flank_failed");
                owner->FUN_00036e70(&DAT_004e0d38, 1);
                ok = false;
            }
        } else if (lo == DAT_004e0d28 && hi == DAT_004e0d2c) {
            if (owner->f10->FUN_00059a30()->f140 != 1)
                return 1;
            owner->f10->FUN_00059a50(&f.V54);
            f.V24 = v2c;
            if (DAT_004dd700->f1c->FUN_001ae2c0(&v2c, &f.V54, &f.V10, 1.0f, 1000.0f, 180.0f, 1, 1, 1, f.u50.i, 0, 0.0f, 2.0f) == 0) {
                v2c = f.V24;
                DAT_004e0d38.FUN_0027b040("rout_failed");
                owner->FUN_00036e70(&DAT_004e0d38, 1);
                ok = false;
            }
        } else if (lo == DAT_004e0d08 && hi == DAT_004e0d0c) {
        } else {
            v2c = f.V10;
        }
        if (ok)
            d8 = 1;
        b1c = 1;
    }

    int g = DAT_004e0d30;
    if (g > 8) {
        g = 0;
        DAT_004e0d30 = 0;
    }
    int cur = f7c;
    if (cur < 0) {
        cur = g;
        if (g == 0)
            f7c = g;
    }
    if (p8c->b49 != 0 && owner->f1ca4 != 0) {
        f.V10 = v2c;
        if (cur != 0) {
            if (cur == 1 || cur == 2 || cur == 8)
                f.V10.x = f.V10.x + p8c->f4c;
            if (cur == 6 || cur == 5 || cur == 4)
                f.V10.x = f.V10.x - p8c->f4c;
            if (cur == 2 || cur == 3 || cur == 4)
                f.V10.z = f.V10.z + p8c->f4c;
            if (cur == 8 || cur == 7 || cur == 6)
                f.V10.z = f.V10.z - p8c->f4c;
            DAT_004d2a3c = 2;
            DAT_00554c1c = 1;
            DAT_00554c18 = 4.0f;
            f.u4c.hub->f20->FUN_00025260(1, 0, 0);
            DAT_004dd700->f0c->FUN_001dcf60(1);
            f.V54.x = f.V10.x - v20.x;
            f.V54.y = f.V10.y - v20.y;
            volatile float *tz = &f.V24.z;
            *tz = f.V10.z - v20.z;
            f.V54.z = *tz;
            f.u1c.f = p8c->f5c;
            char hit = owner->f1ca4->FUN_0010aa90(f.u4c.hub, &v20, &f.V10, f.u1c.f, &f.Vd8, &f.Va8, &f.V54, owner, f.th, 1, 1);
            if (hit != 0) {
                v2c = f.V10;
                f7c = DAT_004e0d30;
                fe4 = 0.0f;
            }
        }
        DAT_004e0d30 = DAT_004e0d30 + 1;
    }

    f.W.x = v2c.x - v20.x;
    f.W.y = 0.0f;
    f.W.z = v2c.z - v20.z;
    f.u50.f = f.W.FUN_0022d110();
    Hub_11e4a0 *hub = f.u4c.hub;
    DAT_004d2a3c = 2;
    DAT_00554c1c = 1;
    DAT_00554c18 = 0.0f;
    hub->f20->FUN_00025260(0, 0, 0);
    DAT_004dd700->f0c->FUN_001dcf60(0);
    f.V8c.x = v20.x;
    f.V8c.y = v20.y + 1.0f;
    f.V8c.z = v20.z;
    f.V98.x = v2c.x;
    f.V98.y = v2c.y + 1.0f;
    f.V98.z = v2c.z;
    {
        volatile float *tz = &f.V54.z;
        f.Vb4.x = f.V98.x - f.V8c.x;
        f.Vb4.y = f.V98.y - f.V8c.y;
        *tz = f.V98.z - f.V8c.z;
        f.Vb4.z = *tz;
    }
    f.u1c.f = v20.y - v2c.y;
    f.u1c.i = f.u1c.i & 0x7fffffff;
    if (f.u1c.f >= 2.0f) {
        f.B23 = 0;
    } else {
        if (owner->f1ca4 != 0) {
            f.u1c.f = p8c->f58;
            f.B23 = owner->f1ca4->FUN_0010aa90(hub, &f.V8c, &f.V98, f.u1c.f, &f.Vcc, &f.Vc0, &f.Vb4, owner, f.th, 1, 1);
        } else {
            f.B23 = FUN_00036b10(hub, &f.V8c, &f.V98, &f.Vcc, &f.Vc0, &f.b7f, &f.b7e);
        }
    }
    hub->f20->FUN_00025260(1, 0, 0);
    DAT_004dd700->f0c->FUN_001dcf60(1);
    f.Vec80.x = 0.0f;
    f.Vec80.y = 0.0f;
    f.Vec80.z = 0.0f;
    if (f.sp != 0 && p8c->b48 != 0) {
        if (f.sp->b129 != 0)
            f.u4c.s = p8c->f54;
        else
            f.u4c.s = p8c->f50;
        float r = FUN_0010b1c0(hub, owner, f.u4c.s, &f.Vec80);
        f.u3c.f = r;
        if (r < 0.0f || r > f.u4c.s) {
            f.sp->b129 = 0;
            f.Vec80.z = 0.0f;
            f.Vec80.y = 0.0f;
            f.Vec80.x = 0.0f;
        } else {
            f.sp->b129 = 1;
            f.Vec80.FUN_0022d110();
            f.u1c.f = (f.u4c.s - f.u3c.f) / f.u4c.s;
            f.u3c.f = 1.0f;
            f.Vec80.FUN_000344b0(FUN_000186f0(&f.u3c.f, &f.u1c.f));
        }
    }

    if (f.B23 != 0) {
        Stats_11e4a0 *o = owner;
        f.V10 = v2c;
        f.V24 = v20;
        if (o->f1ca4 != 0 && p8c->b48 != 0) {
            if (o->f1ca4->v4(&f.V10, &f.V24, o, DAT_004dd700, dt, &f80, &f.Vec80) == 0)
                o->speed = 1.0f;
            return 1;
        }
        f.V54 = v2c;
        float xx = f.V54.x - f.V24.x;
        float zz = f.V54.z - f.V24.z;
        f.A30.y = 0.0f;
        f.B40.y = 0.0f;
        f.A30.x = xx;
        f.A30.z = zz;
        f.B40.x = xx;
        f.B40.z = zz;
        f.A30.FUN_0022d110();
        f.B40.FUN_0022d110();
        o->speed = 1.0f;
        o->outA = f.A30;
        o->outB = f.B40;
        return 1;
    }

    if (d8 != 0 && b1d != 0) {
        if (mode != 2) {
            f.V24 = v64;
            f.V54 = v20;
            fe8 = 0;
            Stats_11e4a0 *o = owner;
            if (o->f1ca4 != 0 && p8c->b48 != 0) {
                if (o->f1ca4->v4(&f.V24, &f.V54, o, DAT_004dd700, dt, &f80, &f.Vec80) != 0)
                    return 1;
            }
            f.V10.x = f.V24.x;
            f.V10.z = f.V24.z;
            f.V10.y = f.V24.y;
            f.V10.x = f.V10.x - f.V54.x;
            f.V10.y = 0.0f;
            f.V10.z = f.V10.z - f.V54.z;
            char near0 = FUN_00018960(f.V10.FUN_0022d110(), 0.0f, 1.0e-5f);
            if (near0 == 0 && f.u50.f > p8c->f34) {
                f.A30.x = f.V10.x;
                f.A30.y = f.V10.y;
                f.A30.z = f.V10.z;
                f.A = 1.0f;
                if (idLo == DAT_004e0d28 && idHi == DAT_004e0d2c) {
                    f.A30.x = f.V10.x * -1.0f;
                    f.A30.y = f.V10.y * -1.0f;
                    f.A30.z = f.V10.z * -1.0f;
                }
                f.B40 = f.V10;
            } else {
                if (p8c->v7() < 0.0f)
                    return 0;
                f.A30 = f.W;
                f.B40 = f.W;
                f.A = 0.0f;
            }
        } else {
            fe8 = fe8 + 1;
            f.V10.x = v2c.x;
            f.V10.z = v2c.z;
            f.V10.y = v2c.y;
            f.V10.z = f.V10.z - v20.z;
            f.u1c.f = v20.y - v2c.y;
            f.u1c.i = f.u1c.i & 0x7fffffff;
            if (!(f.u1c.f >= 2.0f)) {
                if (f.u50.f > p8c->f34) {
                    f.A30.x = f.V10.x - v20.x;
                    f.A = 1.0f;
                    f.A30.y = 0.0f;
                    f.A30.z = f.V10.z;
                    if (idLo == DAT_004e0d28 && idHi == DAT_004e0d2c) {
                        *(unsigned int *)&f.A30.y = 0x80000000;
                        f.A30.x = (f.V10.x - v20.x) * -1.0f;
                        f.A30.z = f.V10.z * -1.0f;
                    }
                    f.B40.x = f.V10.x - v20.x;
                    f.B40.y = 0.0f;
                    f.B40.z = f.V10.z;
                } else {
                    f.A30 = f.W;
                    f.B40 = f.W;
                    f.A = 0.0f;
                    if (p8c->v7() < 0.0f)
                        return 0;
                }
            } else {
                f.A30.y = 0.0f;
                f.A30.z = 0.0f;
                f.B40.x = 0.0f;
                f.B40.y = 0.0f;
                f.B40.z = 0.0f;
                DAT_004e0d38.FUN_0027b040("rout_failed");
                owner->FUN_00036e70(&DAT_004e0d38, 1);
                DAT_004e0d38.FUN_0027b040("path_failed");
                owner->FUN_00036e70(&DAT_004e0d38, 1);
                if (!(f.g88fa0 == 4 && f.u78.i == 1)) {
                    Special_11e4a0 *sp2 = owner->f1ca0;
                    if (sp2->sub.b9e != 0) {
                        sp2->sub.b9e = 0;
                        float now = FUN_000678d0()->FUN_00066280();
                        if (now >= 0.0f) {
                            f.u78.i = *(int *)&owner->f1d48;
                            float now2 = FUN_000678d0()->FUN_00066280();
                            owner->f1d44 = now2 + f.u78.f;
                        }
                    }
                }
                return fe8 <= 5;
            }
        }
    }

    f.A30.FUN_0022d110();
    f.B40.FUN_0022d110();
    Stats_11e4a0 *o2 = owner;
    o2->speed = f.A;
    o2->outA = f.A30;
    o2->outB = f.B40;
    return 1;
}
}
}
