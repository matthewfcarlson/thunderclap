// STATUS: equivalent (tools/equiv.py level 3: 2865 inputs, branch coverage 193/224, incomplete)
// FUN_0003c1d0 @ 0x0003c1d0
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3 *other, float eps);
    float FUN_00018990();
};

struct V4 : V3 {
    float w;
};

struct Mtx {
    float m[16];
    void FUN_0022c3b0(V3 *in, V3 *out);
};

struct Kin {
    char pad[4];
    float FUN_002220d0();
    Mtx *FUN_00221c40();
    V4 *FUN_00221cd0();
};

struct Body {
    char pad00[0x10];
    Kin kin;
    void FUN_002226e0(Kin *k);
    void FUN_002226f0(V3 *p);
    void FUN_00222720(V4 *q);
};

struct Part {
    Body *FUN_00059a40();
    bool FUN_00059a50(V3 *out);
};

struct Info {
    char pad00[0x6c];
    int f6c;
};

struct Mgr {
    Info *FUN_001d72e0();
};

struct Hook {
    virtual void v0();
    virtual void v1();
};

struct Ctl {
    char pad00[0x14];
    int mode;               // 0x14
    char pad18[0x30 - 0x18];
    float f30;
    float f34;
    bool FUN_000456e0();
};

struct Owner {
    char pad00[0x11c];
    Ctl *f11c;
};

struct Pair {
    char pad00[8];
    int f8;
    int fc;
};

struct Obj {
    char pad00[8];
    Owner *f8;
    int type;               // 0xc
    char pad10[0x50 - 0x10];
    V3 v50;
    char pad5c[0x74 - 0x5c];
    Pair *f74;
};

struct Plane {
    int id;
    Obj *obj;
    int f8;
    V3 pos;                 // 0xc
    V3 n;                   // 0x18
    float d;                // 0x24
};

extern int DAT_004e2198;
extern int DAT_004e219c;

bool __cdecl FUN_00018960(unsigned int a, unsigned int b, float c);
void __cdecl FUN_00018810(Hook **slot, Obj *o);
bool __cdecl FUN_00044510(Obj *o, int k);
void __cdecl FUN_00224d70(unsigned int angle, V3 *v);

union W {
    Obj *o;
    float f;
    int i;
    unsigned int u;
};

struct Frame {
    W t10;                  // 0x10
    char pad14[2];
    char f16;
    char f17;
    V3 disp;                // 0x18
    int k;                  // 0x24
    V3 u;                   // 0x28
    V3 w;                   // 0x34
    V3 cur;                 // 0x40
    V3 m;                   // 0x4c
    W thr;                  // 0x58
    W n;                    // 0x5c
    W t60;                  // 0x60
    V3 s;                   // 0x64
    float half;             // 0x70
    W ang;                  // 0x74
    int mode;               // 0x78
    float rad;              // 0x7c
    V3 base;                // 0x80
    W t8c;                  // 0x8c
    V4 n2;                  // 0x90
    V3 delta;               // 0xa0
    struct Kin *kin;        // 0xac
    float lim1;             // 0xb0
    float half308;          // 0xb4
    V3 q;                   // 0xb8
    V3 r2;                  // 0xc4
    V3 out;                 // 0xd0
    V3 G;                   // 0xdc
    float q1;               // 0xe8
    float f34raw;           // 0xec
    V3 P;                   // 0xf0
    V3 r3;                  // 0xfc
    float nd;               // 0x108
    float half220;          // 0x10c
    float s216;             // 0x110
    Body *body;             // 0x114
    V3 up;                  // 0x118
    Mtx mtx;                // 0x124
    char flags[0x80];       // 0x164
    unsigned int cookie;    // 0x1e4
};

class Character {
public:
    char pad00[0x10];
    Part *part;             // 0x10
    Kin kin14;              // 0x14
    char pad18[0x44 - 0x18];
    V3 f44;
    char pad50[0x11c - 0x50];
    Ctl *f11c;
    char pad120[8];
    Mgr *f128;
    int f12c;
    char pad130[0x140 - 0x130];
    int f140;
    unsigned int f144;
    float f148;
    char pad14c[0x328 - 0x14c];
    Obj *f328;
    char pad32c[0x634 - 0x32c];
    int count;              // 0x634
    Plane list[130];        // 0x638
    char pad1a88[0x1ab8 - 0x1a88];
    V3 hitPos;              // 0x1ab8
    V3 hitNrm;              // 0x1ac4
    Hook *f1ad0;
    char pad1ad4[0x1aec - 0x1ad4];
    V3 vH;                  // 0x1aec
    V3 vG;                  // 0x1af8
    int f1b04;
    char pad1b08[0x1b20 - 0x1b08];
    int f1b20;
    int f1b24;
    char pad1b28[0x1d4d - 0x1b28];
    char f1d4d;

    void FUN_00038e80(int a, Obj *o, int b, V3 *m, V3 *s, float thr);
    void FUN_0003c1d0(int unused, float dt);
};

void Character::FUN_0003c1d0(int unused, float dt)
{
    Frame fr;
    fr.cookie = DAT_004d9968;
    Body *body = part->FUN_00059a40();
    fr.body = body;
    if (f128 != 0) {
        Info *info = f128->FUN_001d72e0();
        if (info != 0 && info->f6c == 1)
            body->FUN_002226e0((Kin *)((char *)info + 0x10));
    }
    fr.cur.x = 0;
    fr.cur.y = 0;
    fr.cur.z = 0;
    part->FUN_00059a50(&fr.cur);
    fr.base = f44;
    if (f1ad0 != 0) {
        f1ad0->v1();
        f1ad0 = 0;
    }
    fr.rad = f148;
    Ctl *c = f11c;
    fr.mode = c->mode;
    fr.half220 = fr.rad * 0.5f;
    fr.half308 = fr.rad * 0.5f;
    fr.f34raw = c->f34;
    fr.half = c->f30 * 0.5f;
    f144 = 0;
    f1b04 = 0;
    if (!(f1b20 > 0)) {
        fr.disp.x = fr.cur.x - fr.base.x;
        fr.delta.x = fr.disp.x;
        fr.disp.y = fr.cur.y - fr.base.y;
        fr.delta.y = fr.disp.y;
        fr.disp.z = fr.cur.z - fr.base.z;
        fr.delta.z = fr.disp.z;
        fr.delta.FUN_0022d110();
        fr.kin = &kin14;
        fr.ang.f = kin14.FUN_002220d0();
        Body *b2 = part->FUN_00059a40();
        float t = (b2 == 0) ? 0.0f : b2->kin.FUN_002220d0();
        hitNrm.z = 0;
        hitNrm.y = 0;
        hitNrm.x = 0;
        fr.n.i = count;
        fr.ang.f = t - fr.ang.f;
        fr.f17 = 0;
        fr.lim1 = 1.0f;
        if (fr.n.i - 1 > 0) {
            fr.t60.i = fr.n.i - 1;
            fr.k = 1;
            Plane *p = &list[0];
            do {
                fr.w = fr.cur;
                fr.w.x = fr.w.x - p->pos.x;
                fr.w.y = fr.w.y - p->pos.y;
                fr.w.z = fr.w.z - p->pos.z;
                if (((fr.w.z * p->n.z + fr.w.y * p->n.y) + fr.w.x * p->n.x) > 0.0f
                    && fr.k < fr.n.i) {
                    fr.t10.i = fr.n.i - fr.k;
                    Plane *q = p + 1;
                    do {
                        fr.u = fr.cur;
                        fr.u.x = fr.u.x - q->pos.x;
                        fr.u.y = fr.u.y - q->pos.y;
                        fr.u.z = fr.u.z - q->pos.z;
                        if (((fr.u.z * q->n.z + fr.u.y * q->n.y) + fr.u.x * q->n.x) > 0.0f) {
                            float cs = (p->n.z * q->n.z + p->n.y * q->n.y) + q->n.x * p->n.x;
                            if (cs < -9.99999975e-06f && cs > -0.99999f) {
                                fr.s.x = p->n.x + q->n.x;
                                fr.s.y = p->n.y + q->n.y;
                                fr.s.z = p->n.z + q->n.z;
                                fr.s.FUN_0022d110();
                                volatile float *vm = &fr.m.x;
                                vm[2] = -fr.w.z;
                                vm[0] = -fr.w.x - fr.u.x;
                                vm[0] = vm[0] * 0.5f;
                                vm[1] = (-fr.w.y - fr.u.y) * 0.5f;
                                vm[0] = vm[0] + fr.cur.x;
                                vm[1] = vm[1] + fr.cur.y;
                                vm[2] = (vm[2] - fr.u.z) * 0.5f + fr.cur.z;
                                if (p->d < q->d)
                                    fr.thr.f = p->d;
                                else
                                    fr.thr.f = q->d;
                                FUN_00038e80(0, p->obj, -1, &fr.m, &fr.s, fr.thr.f);
                            }
                        }
                        q++;
                        fr.t10.i--;
                    } while (fr.t10.i != 0);
                }
                fr.k++;
                p++;
                fr.t60.i--;
            } while (fr.t60.i != 0);
        }

        // main pass over the planes
        for (fr.k = 0; fr.k < count; fr.k++) {
            if (fr.k == -1)
                continue;
            Plane *e = &list[fr.k];
            Obj *o = e->obj;
            fr.flags[fr.k] = 0;
            fr.t10.o = o;
            if (o != 0 && o->type == 1 && o->f8->f11c != 0 && f1b24 > 0)
                continue;
            fr.P = e->pos;
            if (fr.mode == 5) {
                Mtx *mp = fr.kin->FUN_00221c40();
                fr.mtx = *mp;
                fr.up.x = 0;
                fr.up.y = 1.0f;
                fr.up.z = 0;
                fr.mtx.FUN_0022c3b0(&fr.up, &fr.out);
                if (((fr.P.z * fr.out.z + fr.P.y * fr.out.y) + fr.out.x * fr.P.x)
                        + (-((fr.mtx.m[14] * fr.out.z + fr.mtx.m[13] * fr.out.y)
                             + fr.mtx.m[12] * fr.out.x))
                    < fr.half308)
                    continue;
                o = fr.t10.o;
            } else if (f140 != 4 && o != f328) {
                float t1 = e->pos.y - fr.cur.y;
                float x;
                if (f140 == 3) {
                    t1 = t1 + fr.rad;
                    x = 0.155f;
                } else {
                    x = fr.half308;
                }
                if (o->type == 5)
                    x = x * 0.5f;
                if (t1 < x)
                    continue;
                if (f140 == 1 && e->n.y > 0.5f) {
                    if (t1 < fr.rad)
                        continue;
                }
            }
            if (!(f11c != 0 && f11c->FUN_000456e0())) {
                if (e->n.y > 0.5f) {
                    e->n.y = 0;
                    float len = e->n.FUN_0022d110();
                    if (fr.mode == 5 && len < 0.8f)
                        continue;
                    fr.t8c.f = len;
                    fr.t8c.u &= 0x7fffffff;
                    if (fr.t8c.f <= 0.1f)
                        continue;
                }
            }
            if (f140 == 4) {
                fr.G = vG;
                fr.q1 = -((fr.G.z * vH.z + fr.G.y * vH.y) + fr.G.x * vH.x);
                fr.n2.x = e->n.x;
                fr.n2.y = e->n.y;
                fr.n2.z = e->n.z;
                fr.n2.w = -((fr.n2.z * e->pos.z + fr.n2.y * e->pos.y) + fr.n2.x * e->pos.x);
                if (fr.G.FUN_0022d2b0(&fr.n2, 1e-05f)) {
                    fr.t60.f = fr.q1 - fr.n2.w;
                    fr.t60.u &= 0x7fffffff;
                    if (fr.t60.f <= 9.99999975e-06f)
                        continue;
                }
            }
            V3 *nn = &e->n;
            if ((fr.disp.y * nn->y + fr.disp.z * nn->z) + fr.disp.x * nn->x < 0.0f) {
                fr.flags[fr.k] = 1;
                if (fr.k > -1) {
                    if (e->d > 0.0f && -((fr.disp.y * nn->y + fr.disp.z * nn->z) + fr.disp.x * nn->x) > e->d)
                        fr.t10.f = e->d;
                    else
                        fr.t10.f = -((fr.disp.y * nn->y + fr.disp.z * nn->z) + fr.disp.x * nn->x);
                    fr.s = *nn;
                    fr.s.y = fr.s.y * fr.t10.f;
                    fr.s.z = fr.s.z * fr.t10.f;
                    fr.disp.x = fr.s.x * fr.t10.f + fr.disp.x;
                    fr.disp.y = fr.s.y + fr.disp.y;
                    fr.disp.z = fr.s.z + fr.disp.z;
                    if (e->d < 0.0f) {
                        Obj *ob = e->obj;
                        if (ob == 0 || ob->type != 1 || FUN_00044510(ob, 2)
                            || FUN_00044510(e->obj, 3) || FUN_00044510(e->obj, 5)) {
                            fr.nd = -e->d;
                            fr.s216 = fr.t10.f;
                            if (-e->d > fr.t10.f) {
                                fr.w = *nn;
                                bool cl = false;
                                if (f1d4d)
                                    cl = fr.w.y < -0.5f;
                                if (f140 != 3) {
                                    if (fr.w.y > 0.5f || cl)
                                        fr.w.y = 0;
                                }
                                float lim = (f1d4d ? 2.0f : 10.0f) * dt;
                                fr.t10.f = fr.nd - fr.s216;
                                float amt = (lim > fr.t10.f) ? fr.t10.f : lim;
                                fr.w.x = fr.w.x * amt;
                                fr.w.y = fr.w.y * amt;
                                fr.disp.x = fr.w.x + fr.disp.x;
                                fr.disp.y = fr.w.y + fr.disp.y;
                                fr.disp.z = amt * fr.w.z + fr.disp.z;
                            }
                        }
                    }
                } else {
                    fr.disp.x = 0;
                    fr.disp.z = 0;
                    fr.disp.y = 0;
                    continue;
                }
                fr.f16 = 0;
                if (o == 0)
                    continue;
                if (e->id != f12c)
                    continue;
                Pair *pr = o->f74;
                if (pr != 0 && pr->f8 == DAT_004e2198 && pr->fc == DAT_004e219c) {
                    fr.f16 = 1;
                } else if (o->type == 1) {
                    if (o->f8 == 0)
                        continue;
                    Ctl *c2 = o->f8->f11c;
                    if (c2 == 0)
                        continue;
                    int mm = c2->mode;
                    if (mm < 2)
                        continue;
                    if (mm > 3 && mm != 5)
                        continue;
                } else if (o->type == 5) {
                    if (!(o->v50.FUN_00018990() < 5.0f))
                        continue;
                } else {
                    continue;
                }
                fr.t10.f = nn->y;
                fr.t10.u &= 0x7fffffff;
                bool goB = !(fr.t10.f <= 0.1f);
                if (!goB && f140 == 1) {
                    float t = e->pos.y - fr.cur.y;
                    if (!(t > fr.half * -0.8f))
                        goB = true;
                    else if (!(t < fr.half * 0.8f))
                        goB = true;
                }
                if (!goB) {
                    fr.q.x = fr.delta.x;
                    fr.q.y = fr.delta.y;
                    fr.q.z = fr.delta.z;
                    fr.q.y = 0;
                    fr.q.FUN_0022d110();
                    fr.t10.f = (fr.q.z * nn->z + fr.q.y * nn->y) + fr.q.x * nn->x;
                    if (!(fr.t10.f < fr.lim1))
                        continue;
                    V3 *ep = &e->pos;
                    hitPos.x = ep->x;
                    hitPos.y = e->pos.y;
                    hitPos.z = ep->z;
                    hitNrm.x = nn->x;
                    hitNrm.y = nn->y;
                    hitNrm.z = nn->z;
                    FUN_00018810(&f1ad0, e->obj);
                    fr.lim1 = fr.t10.f;
                    if (fr.t10.f < -0.8f) {
                        f144 = f144 | 2;
                        if (fr.f16)
                            f144 = f144 | 4;
                    }
                    if (fr.mode == 5 && fr.f16 && e->d < -0.05f) {
                        unsigned int au = fr.ang.u;
                        if (!FUN_00018960(au, 0, 1e-05f)) {
                            fr.u.x = ep->x - fr.base.x;
                            fr.u.y = ep->y - fr.base.y;
                            fr.u.z = ep->z - fr.base.z;
                            fr.r2 = fr.u;
                            FUN_00224d70(au, &fr.r2);
                            fr.r3 = fr.r2;
                            if (((fr.r3.z - fr.u.z) * nn->z + (fr.r3.y - fr.u.y) * nn->y)
                                    + (fr.r3.x - fr.u.x) * nn->x
                                < 0.0f) {
                                fr.ang.f = 0;
                                fr.f17 = 1;
                            }
                        }
                    }
                    continue;
                }
                if (!(fr.delta.y > 0.85f))
                    continue;
                fr.thr.f = nn->y - (-1.0f);
                fr.thr.u &= 0x7fffffff;
                if (!(fr.thr.f <= 0.3f))
                    continue;
                if (f140 != 1) {
                    if (e->pos.y - fr.cur.y > fr.half * 0.5f) {
                        f144 = f144 | 8;
                        continue;
                    }
                    if (f140 != 1)
                        continue;
                }
                if (e->pos.y - fr.cur.y > fr.half * 1.5f)
                    f144 = f144 | 8;
                continue;
            }

            // surface faces away from the displacement
            {
                Obj *ob = e->obj;
                if (ob != 0) {
                    int ty = ob->type;
                    bool go = false;
                    if (ty == 5 && (e->pos.y - fr.base.y) > fr.half220)
                        go = true;
                    else if ((e->pos.y - fr.base.y) > fr.rad)
                        go = true;
                    if (go && -(fr.f34raw * 0.5f) > e->d) {
                        bool pass;
                        if (ty != 1 && ob->f74 != 0 && ob->f74->f8 == DAT_004e2198
                            && ob->f74->fc == DAT_004e219c)
                            pass = true;
                        else
                            pass = FUN_00044510(ob, 2) || FUN_00044510(e->obj, 3)
                                   || FUN_00044510(e->obj, 5);
                        if (pass) {
                            fr.w = *nn;
                            bool cl = false;
                            if (f1d4d)
                                cl = fr.w.y < -0.5f;
                            if (f140 != 3) {
                                if (fr.w.y > 0.5f || cl)
                                    fr.w.y = 0;
                            }
                            fr.t10.f = -e->d;
                            float lim = dt * 4.0f;
                            float amt = (lim > fr.t10.f) ? fr.t10.f : lim;
                            fr.w.x = fr.w.x * amt;
                            fr.w.y = fr.w.y * amt;
                            fr.disp.x = fr.w.x + fr.disp.x;
                            fr.disp.y = fr.w.y + fr.disp.y;
                            fr.disp.z = amt * fr.w.z + fr.disp.z;
                        }
                    }
                }
            }
            if (e->obj == 0)
                continue;
            if (e->obj->type != 5)
                continue;
            if (!(fr.delta.y >= 0.0f))
                continue;
            fr.n.f = e->n.y - (-1.0f);
            fr.n.u &= 0x7fffffff;
            if (!(fr.n.f <= 0.3f))
                continue;
            if (f140 != 1) {
                if (e->pos.y - fr.cur.y > fr.half * 0.5f) {
                    f144 = f144 | 8;
                    continue;
                }
                if (f140 != 1)
                    continue;
            }
            if (e->pos.y - fr.cur.y > fr.half * 1.5f)
                f144 = f144 | 8;
        }

        fr.cur.x = fr.base.x + fr.disp.x;
        fr.cur.y = fr.base.y + fr.disp.y;
        fr.cur.z = fr.base.z + fr.disp.z;
        fr.body->FUN_002226f0(&fr.cur);
        if (fr.mode == 5 && fr.f17) {
            V4 *qv = fr.kin->FUN_00221cd0();
            fr.n2.x = qv->x;
            fr.n2.y = qv->y;
            fr.n2.z = qv->z;
            fr.n2.w = qv->w;
            fr.body->FUN_00222720(&fr.n2);
        }
    }
    __security_check_cookie(fr.cookie);
}
