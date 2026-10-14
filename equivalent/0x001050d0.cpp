// STATUS: equivalent (tools/equiv.py level 3: 6833 inputs, branch coverage 131/132, incomplete)
// CPathAgent::vfunc_4 @ 0x001050d0
// equiv-map: ?Del340@@YAXPAX@Z = 0x0008d340
// equiv-map: ?Del330@@YAXPAX@Z = 0x0008d330
extern "C" double __cdecl sqrt(double);
void __cdecl Del340(void *p);
void __cdecl Del330(void *p);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    char FUN_0022d2b0(V3 *other, float eps);
    void FUN_00011250(V3 *out, V3 *other);
};

struct Locator {
    void FUN_00059a50(V3 *out);
};

struct Body {
    char pad0[0x10];
    Locator *locator;
    char pad14[0x1a64 - 0x14];
    float f1a64;
    char pad1a68[0x1d0c - 0x1a68];
    float f1d0c;
    float f1d10;
    char pad1d14[0x2074 - 0x1d14];
    V3 v2074;
    char FUN_000372f0();
};

struct PNode {
    V3 pos;
    int link;
};
struct PList {
    char pad0[0x14];
    int count;
    PNode *FUN_00106160(int idx);
};

struct Part2 {
    char pad0[0x60];
    PList *f60;
    char pad64[0xb8 - 0x64];
    int fb8;
};

struct Mgr20 {
    void FUN_00024300(Body *b);
    void FUN_00025260(int a, int b, int c);
};
struct Ctx {
    char pad0[0x20];
    Mgr20 *f20;
};
struct Sink0c {
    void FUN_001dcf60(int a);
};
struct World {
    char pad0[0xc];
    Sink0c *f0c;
};
extern World *DAT_004dd700;

class Part {
public:
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual void p5();
    virtual Body *vfunc_6();
    virtual void p7(); virtual void p8();
    virtual int vfunc_9();
    char pad04[0xe8 - 4];
    char flagE8;
    char pad_e9[0x129 - 0xe9];
    char b129;
    Part2 *FUN_000fdc40();
};

struct VList {
    V3 *nodes;
    int f04;
    int count;
    void *f0c;
};

class AgentSub {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void vfunc_4(Ctx *c, float dt, int a3);
    char pad04[0x76 - 4];
    char b76;
    char pad77[0x89 - 0x77];
    char b89;
    void FUN_00102b90(V3 *p, float a, int b);
};

struct Dir {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual float vfunc_4(V3 *target, V3 *pos, Body *b, Ctx *a1, float dt, V3 *fbc, V3 *w);
};

float __cdecl FUN_00018710(float *a, float *b);
float __cdecl FUN_000186f0(float *a, float *b);
V3 *__cdecl FUN_00083e00(V3 *out, V3 *in, float s);
float __cdecl FUN_0010b1c0(Ctx *a1, Body *b, float thr, V3 *out);
char __cdecl FUN_00036b10(Ctx *w, V3 *a, V3 *b, V3 *c, V3 *d, char *e, char *f);

extern float DAT_004a1c64;
extern float DAT_004a1c7c;

struct Frame {
    float L;                          // path-length / scratch (reused for t and k later)
    union {
        float gy;
        unsigned char b;              // bool stored as a byte then pushed as a dword
        unsigned int w;
    } g;
    char pad08;
    char fl19;
    char flag1a;
    char fl1b;
    V3 qv;
    V3 dv;
    V3 pos;
    V3 pp;
    V3 o1;
    V3 v3;
    float two;
    Body *bsave;
    V3 h;
    V3 out1;
    V3 out2;
};

class CPathAgent {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual float vfunc_4(Ctx *a1, float a2, int a3);
    char pad04[0x58 - 4];
    Part *part;
    char pad5c[4];
    AgentSub *sub;
    VList *list;
    int idx;
    float f6c;
    V3 p70;
    V3 p7c;
    char b88;
    char b89;
    char pad8a[2];
    float f8c;
    unsigned char b90;
    unsigned char b91;
    char pad92[2];
    float f94;
    float f98;
    char pad9c[4];
    V3 pa0;
    float fac;
    V3 pb0;
    V3 pbc;
    Dir *fc8;
    char padcc[0xe4 - 0xcc];
    float fe4;
    V3 pe8;
    float ff4;
    float ff8;

    void FUN_000fc550(Ctx *a1, float a2, int a3);
    void FUN_00104c60(Ctx *a1, V3 *pos, V3 *p7c, float f8c, int b90, float f94, int z);
};


float CPathAgent::vfunc_4(Ctx *a1, float a2, int a3)
{
    Frame f;
    FUN_000fc550(a1, a2, a3);
    // The early exits fall off the end without a value: the original leaves the x87 stack empty there.
    if (b88 && !(part && part->vfunc_9() == 4)) {
        Body *b = part->vfunc_6();
        f.bsave = b;
        b->locator->FUN_00059a50(&f.pos);
        f.dv.x = p70.x - f.pos.x;
        f.dv.y = p70.y - f.pos.y;
        f.dv.z = p70.z - f.pos.z;
        if ((char)a3) {
            pb0.x = b->v2074.x;
            pb0.y = b->v2074.y;
            pb0.z = b->v2074.z;
            pe8.z = 0.0f;
            pe8.y = 0.0f;
            pe8.x = 0.0f;
            ff4 = 0.0f;
            ff8 = 999.0f;
            f6c = 0.0f;
        }
        a1->f20->FUN_00024300(b);
        fac = fac - a2;
        f.flag1a = 0;
        f.L = (float)sqrt(f.dv.z * f.dv.z + f.dv.y * f.dv.y + f.dv.x * f.dv.x);
        b->f1d10 = f.L;
        if (f98 <= 1.0f)
            f98 = 10.0f;
        if (!b->FUN_000372f0()) {
            if (f6c == 0.0f || f.L < f6c) {
                f6c = f.L;
                b->f1d0c = f.L;
            }
            if (f.L - 0.2f > f6c) {
                Part2 *p = part->FUN_000fdc40();
                if (p && p->f60) {
                    PNode *n1 = p->f60->FUN_00106160(p->fb8);
                    if (n1) {
                        int k = n1->link;
                        if (k >= 0 && k < p->f60->count) {
                            PNode *n2 = p->f60->FUN_00106160(k);
                            if (n2) {
                                f.pp = f.pos;
                                f.g.gy = b->f1a64 + 0.25f;
                                f.qv = n2->pos;
                                f.pos.y = FUN_00018710(&f.pos.y, &f.g.gy);
                                f.qv.y = FUN_00018710(&f.qv.y, &f.g.gy);
                                a1->f20->FUN_00025260(0, 0, 0);
                                DAT_004dd700->f0c->FUN_001dcf60(0);
                                if (FUN_00036b10(a1, &f.pp, &f.qv, &f.o1, &f.dv, &f.fl19, &f.fl1b))
                                    f.flag1a = 1;
                                a1->f20->FUN_00025260(1, 0, 0);
                                DAT_004dd700->f0c->FUN_001dcf60(1);
                            }
                        }
                    }
                }
            }
        }

        // Decide between advancing to the next waypoint (1) and holding (0).
        int advance;
        bool lookahead = false;
        bool reachNear = (f.L < f98) || (!part->flagE8 && f.L < 3.0f);
        if (!reachNear) {
            advance = -1;                            // go straight to the stuck/blocked test
        } else if (list && idx < list->count - 1) {
            advance = f.L < f98 ? -2 : -1;           // -2: look ahead
        } else {
            advance = f.L < f98 ? 1 : -1;
        }
        (void)lookahead;
        if (advance == -2) {
            f.g.gy = b->f1a64 + 0.25f;
            f.dv = f.pos;
            f.o1 = list->nodes[idx + 1];
            f.pos.y = FUN_00018710(&f.pos.y, &f.g.gy);
            f.o1.y = FUN_00018710(&f.o1.y, &f.g.gy);
            f.qv.x = f.o1.x - f.dv.x;
            f.qv.y = f.o1.y - f.dv.y;
            f.qv.z = f.o1.z - f.dv.z;
            f.g.gy = f.qv.FUN_00018990();      // segment length; f.L (distance to the waypoint) stays live
            f.qv.FUN_0022d110();
            f.two = 2.0f;
            V3 *step = FUN_00083e00(&f.pp, &f.qv, FUN_000186f0(&f.two, &f.g.gy));
            f.o1.x = f.dv.x + step->x;
            f.o1.y = f.dv.y + step->y;
            f.o1.z = f.dv.z + step->z;
            if (FUN_00036b10(a1, &f.dv, &f.o1, &f.out2, &f.out1, &f.fl1b, &f.fl19)) {
                advance = 1;
            } else {
                if (f98 > 0.5f) {
                    f.two = f98 * 0.5f;
                    f.g.gy = 0.5f;
                    f98 = FUN_00018710(&f.g.gy, &f.two);
                }
                advance = f.flag1a ? 1 : 0;
            }
        } else if (advance == -1) {
            advance = 0;
            if (f.flag1a) {
                advance = 1;
            } else if (list) {
                f.qv.x = -1.0f;
                f.qv.y = -1.0f;
                f.qv.z = -1.0f;
                if (!pa0.FUN_0022d2b0(&f.qv, 1e-005f) && idx < list->count - 1 && f.L < f98) {
                    p70.FUN_00011250(&f.qv, &pa0);
                    f.qv.y = 0.0f;
                    f.qv.FUN_0022d110();
                    f.pp.x = p70.x - f.pos.x;
                    f.pp.y = 0.0f;
                    f.pp.z = p70.z - f.pos.z;
                    f.pp.FUN_0022d110();
                    if (f.qv.z * f.pp.z + f.qv.y * f.pp.y + f.qv.x * f.pp.x < 0.25f) {
                        f.o1 = f.pos;
                        f.g.gy = b->f1a64 + 0.25f;
                        f.dv = p70;
                        f.pos.y = FUN_00018710(&f.pos.y, &f.g.gy);
                        f.dv.y = FUN_00018710(&f.dv.y, &f.g.gy);
                        f.flag1a = FUN_00036b10(a1, &f.o1, &f.dv, &f.out1, &f.out2, &f.fl1b, &f.fl19);
                        advance = f.flag1a ? 1 : 0;
                    }
                }
            }
        }

        if (advance == 1) {
            f6c = 0.0f;
            pe8.z = 0.0f;
            pe8.y = 0.0f;
            pe8.x = 0.0f;
            idx = idx + 1;
            ff4 = 0.0f;
            ff8 = 999.0f;
            f98 = f94;
            VList *done = list;     // the original keeps the list pointer in a register across the deletes
            if (done && idx >= done->count) {
                Del340(done->nodes);
                Del340(done->f0c);
                Del330(done);
                list = 0;
                idx = 0;
                b89 = 1;
                pa0.x = -1.0f;
                pa0.y = -1.0f;
                pa0.z = -1.0f;
            }
            if (list == 0) {
                b89 = 1;
            } else {
                pa0 = p70;
                p70 = list->nodes[idx];
                sub->FUN_00102b90(&p70, f8c, b91 ? 0 : (unsigned char)b90);
                sub->vfunc_4(a1, a2, a3);
            }
        } else {
            if (pe8.FUN_0022d2b0(&p70, 1e-005f)) {
                if (ff8 - f.L > 0.25f) {
                    ff8 = f.L;
                    ff4 = 0.0f;
                } else {
                    if (!sub->b76)
                        ff4 = a2 + ff4;
                }
            } else {
                ff4 = 0.0f;
                ff8 = 999.0f;
                pe8 = p70;
            }
            bool skip = false;
            if (!(fac < 0.0f) && !(ff4 > DAT_004a1c64))
                skip = true;
            if (!skip && !b91) {
                bool doMove = false;
                if (list == 0 || ff4 > DAT_004a1c64) {
                    doMove = true;
                } else if (idx < list->count) {
                    f.pp = f.pos;
                    f.g.gy = b->f1a64 + 0.25f;
                    f.qv = p70;
                    f.pp.y = FUN_00018710(&f.pp.y, &f.g.gy);
                    f.qv.y = FUN_00018710(&f.qv.y, &f.g.gy);
                    f.fl19 = FUN_00036b10(a1, &f.pp, &f.qv, &f.out1, &f.out2, &f.fl1b, &f.fl19) == 0;
                    if (f.fl19) {
                        doMove = true;
                    } else if (fac < 0.0f) {
                        fac = 2.5f;
                    }
                }
                if (doMove) {
                    f.two = f6c;
                    FUN_00104c60(a1, &f.pos, &p7c, f8c, b90, f94, 0);
                    f6c = f.two;
                }
            }
            if (fe4 < 3.0f) {
                f.g.b = (b90 && !b91 && (list == 0 || idx < list->count - 1)) ? 1 : 0;
                sub->FUN_00102b90(&p70, f8c, f.g.w);
                sub->vfunc_4(a1, a2, a3);
            }
        }

        f.pp.x = 0.0f;
        f.pp.z = 0.0f;
        if (list && !b91) {
            f.dv = f.pos;
            f.L = 2.0f;
            int i = idx;
            if (i >= 0) {
                int off = i * 12;
                for (;;) {
                    f.qv = list->nodes[i];
                    f.o1.x = f.qv.x - f.dv.x;
                    f.o1.y = 0.0f;
                    f.o1.z = f.qv.z - f.dv.z;
                    f.o1.FUN_0022d110();
                    float ln = (float)sqrt(f.o1.z * f.o1.z + f.o1.x * f.o1.x + f.o1.y * f.o1.y);
                    if (ln > f.L || i >= list->count - 1) {
                        float tz = f.o1.z * f.L;
                        f.pp.x = f.o1.x * f.L + f.dv.x;
                        f.pp.z = tz + f.dv.z;
                        break;
                    }
                    f.L = f.L - ln;
                    i++;
                    off += 12;
                    f.dv.x = f.qv.x;
                    f.dv.z = f.qv.z;
                    if (off < 0)
                        break;
                }
            }
        } else {
            f.qv.z = pb0.z + pb0.z;
            f.pp.x = (pb0.x + pb0.x) + f.pos.x;
            f.pp.z = f.qv.z + f.pos.z;
        }
        Body *tb = f.bsave;
        f.h.x = f.pp.x - f.pos.x;
        f.h.y = 0.0f;
        f.h.z = f.pp.z - f.pos.z;
        f.h.FUN_0022d110();
        f.L = a2 * 30.0003f * DAT_004a1c7c;
        float kc;
        if (1.0f < f.L)
            kc = 1.0f;
        else if (0.0f < f.L)
            kc = f.L;
        else
            kc = 0.0f;
        f.qv.x = f.h.x * kc;
        f.qv.y = f.h.y * kc;
        f.qv.z = f.h.z * kc;
        float om = 1.0f - kc;
        f.pp.x = om * pb0.x;
        f.pp.y = om * pb0.y;
        f.qv.z = om * pb0.z + f.qv.z;
        pb0.z = f.qv.z;
        pb0.x = f.pp.x + f.qv.x;
        pb0.y = f.pp.y + f.qv.y;
        pb0.FUN_0022d110();
        tb->v2074.x = pb0.x;
        tb->v2074.y = pb0.y;
        tb->v2074.z = pb0.z;

        f.v3.x = 0.0f;
        f.v3.y = 0.0f;
        f.v3.z = 0.0f;
        f.L = part->b129 ? 1.5f : 0.75f;
        float r = FUN_0010b1c0(a1, tb, f.L, &f.v3);
        f.g.gy = r;
        if (!(r < 0.0f) && !(r > f.L)) {
            part->b129 = 1;
            f.v3.FUN_0022d110();
            float m = (f.L - f.g.gy) / f.L;
            if (1.0f < m)
                m = 1.0f;
            f.v3.x = f.v3.x * m;
            f.v3.y = f.v3.y * m;
            f.v3.z = f.v3.z * m;
        } else {
            part->b129 = 0;
            f.v3.z = 0.0f;
            f.v3.y = 0.0f;
            f.v3.x = 0.0f;
        }
        return fc8->vfunc_4(&p70, &f.pos, tb, a1, a2, &pbc, &f.v3);
    }
}
