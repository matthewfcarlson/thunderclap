// STATUS: equivalent (tools/equiv.py level 3: 1839 inputs, branch coverage 260/271, incomplete)
// FUN_001d8fc0 @ 0x001d8fc0
// CSPHulkPropInstance per-frame update (FUN_001d8fc0): steering of the prop's velocity vectors,
// ground/water level crossings, StateProp event keys.
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();          // normalize in place, returns the old length
    void FUN_00011140(float s);
};

struct Matrix {
    float m0, m1, m2, m3;
    float m4, m5, m6, m7;
    float m8, m9, m10, m11;
    Vec3 t;
    float m15;
    void FUN_0022b980();           // identity
    void FUN_0022ba70(float ang);
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
    void FUN_0022c3b0(const Vec3 *in, Vec3 *out);
    void FUN_0022be40(const Vec3 *v);
};

struct Key64 {
    unsigned int lo;
    unsigned int hi;
};

struct Bounds {
    float x, y, z, w;
};

struct Descriptor {
    unsigned int kind;
    Bounds bounds;
    char rest[12];
    struct Desc0;
    void FUN_00067e60(const void *src);
    void FUN_000679c0();
};

struct Mgr {
    void *FUN_00067ad0(int h);
    void FUN_00067c30(int h, Descriptor *d);
    void FUN_00067c80(int h);
};

struct Sink {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(const Vec3 *from, Vec3 *out, int mode);
};

struct Ctl {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(int a);
    virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual bool v11();
    virtual void v12();
    virtual void v13();
    char pad4[0x10 - 4];
    Sink *p10;
    char pad14[0x72 - 0x14];
    unsigned char b72;
    char pad73[0x98 - 0x73];
    Vec3 v98;
    void FUN_002f5a20(const Vec3 *v);
    void FUN_0016fc90(Vec3 *out);
};

struct P20 {
    char pad0[0x34];
    float f34;
};

struct Sub74 {
    char pad0[0x20];
    P20 *p20;
    char pad24[0x50 - 0x24];
    unsigned char b50;
    char pad51[0x72 - 0x51];
    unsigned char b72;
};

struct Entity {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7();
    char pad4[0x50 - 4];
    Vec3 v50;
    Vec3 v5c;
    char pad68[0x70 - 0x68];
    Ctl *p70;
    Sub74 *p74;
    void FUN_002ef8b0(int a);
};

struct Holder {
    char pad0[0x10];
    Entity *p10;
    Matrix *FUN_002fc6f0();
};

struct Hit8 {
    char pad0[0x148];
    int i148;
};

struct Hit {
    char pad0[8];
    Hit8 *p8;
    int type;
    char pad10[0x74 - 0x10];
    Sub74 *p74;
};

struct PosProvider {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3 *v4();
};

struct StateObj {
    bool FUN_001d4e50();
    int FUN_001d4de0();
    int FUN_001d5e80(int a);
    bool FUN_001d4e40();
};

struct Rng {
    float FUN_00078780();
};

struct Singleton {
    bool FUN_001c3c90();
    Vec3 *FUN_001c39d0();
    void FUN_001c3ca0(int on);
};

struct Elem {
    Vec3 v0;
    char pad0c[0x28 - 0x0c];
    unsigned int lo28;
    unsigned int hi2c;
    char pad30[0x40 - 0x30];
    unsigned int lo40;
    unsigned int hi44;
    char pad48[0x50 - 0x48];
    float f50;
    char pad54[0x58 - 0x54];
};

struct ObjList {
    char pad0[0x44];
    int count;
    Elem *elems;
};

struct ObjArr {
    char pad0[0x1c];
    ObjList **arr;
};

struct Item24 {
    Vec3 v;
    int i0c;
    char pad10[0x24 - 0x10];
};

struct Waypoints {
    virtual void v0();
    virtual void v1();
    char pad4[0x14 - 4];
    int i14;
    Item24 *FUN_00106160(int i);
};

struct Obj24c {
    virtual void v0();
    virtual void v1();
    char pad4[0xc - 4];
    int i0c;
};

struct Obj21c {
    virtual void v0();
    virtual void v1();
};

struct Layer54 {
    int FUN_00204200(float x, float y, float z);
    bool FUN_00204440(int idx);
};

struct Mid54 {
    Layer54 *FUN_000862a0();
};

struct Fx {
    void FUN_00283a40(const unsigned int *key, const Matrix *m, float a, float b);
};

struct Fx34 {
    void FUN_001ec060(void *inst, const char *s);
};

struct Fx10;

struct Root24 {
    char pad0[0x18];
    float f18;
    char pad1c[0x20 - 0x1c];
    unsigned int lo20;
    unsigned int hi24;
    char c28[1];
};

struct Q20 {
    char pad0[8];
    Mgr *p8;
    void FUN_00029bb0(Entity *e, Obj21c *o, float f);
};

struct Root10 {
    void FUN_001b4620(Vec3 v, int idx, Entity *e, Obj24c *o);
};

class CSPHulkPropInstance;

struct Root0c {
    CSPHulkPropInstance *FUN_001e47e0(CSPHulkPropInstance *inst, Elem *el);
};

struct Root {
    char pad0[0xc];
    Root0c *p0c;
    Root10 *p10;
    char pad14[0x20 - 0x14];
    Q20 *p20;
    Root24 *p24;
    char pad28[0x34 - 0x28];
    Fx34 *p34;
    char pad38[0x54 - 0x38];
    Mid54 *p54;
};

struct Key2 {
    unsigned int lo;
    unsigned int hi;
};

namespace pure3d {
namespace prop {
class StateProp {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(float dt, int a);
    virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual Matrix *vfunc_15();
};
}
}

struct Obj72e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(const Matrix *m, int a);
    char pad4[0x40 - 4];
    Vec3 v40;
};

extern float FUN_00224f10(const Vec3 *v);
extern float FUN_00224fc0(float a, float b);
extern float FUN_00083d90(const float *p);
extern void FUN_00224d70(float ang, Vec3 *v);
extern void FUN_00224db0(Matrix *out, const Vec3 *from, const Vec3 *to);
extern bool FUN_00018960(float a, float b, float eps);
extern Key64 FUN_0027b020(const char *s);
extern Rng *FUN_000964d0();
extern Singleton *FUN_001c3d90();
extern Fx *FUN_0027f250();
extern int FUN_00098190(float a, float b, int c, int d, Obj21c *e, float f, Vec3 *g, Vec3 *h, int i,
                        int j, int k, int l);
extern bool FUN_00202560(const Vec3 *a, float b, int c, Vec3 *d, Bounds *e, Vec3 *f, Hit **g, int h);


extern Root *DAT_004dd700;
extern unsigned int DAT_004e263c;
extern Vec3 DAT_004e2630;
extern unsigned int DAT_004e2628;
extern unsigned int DAT_004e262c;
extern unsigned int DAT_004e2620;
extern unsigned int DAT_004e2624;
extern Key2 DAT_004e25a0[6];
extern Vec3 DAT_004c6068;

// The original keeps these in fixed stack words and hands pointers to them to callees (the checker
// compares what lies around them), and re-uses the same words for different values over time.
struct Frame {
    float f140;             // E-0x140: sec, later the heading a1, later the water level wl
    union {
        float f13c;         // E-0x13c: flag / ff / l / a3
        unsigned int u13c;
    };
    char p138[3];
    bool A3;                // E-0x135
    float f134;             // E-0x134: l2, secCopy, sc
    Vec3 v130;              // E-0x130: scratch vector
    Vec3 dir;               // E-0x124
    union {
        float f118;         // E-0x118
        Sub74 *s74;
    };
    char p114[3];
    unsigned char sv;       // E-0x111
    union {
        float f110;         // E-0x110
        Hit *hitObj;
        int count;
    };
    Vec3 v10c;              // E-0x10c
    union {
        float f100;         // E-0x100
        ObjList *o;
        Root24 *r24;
    };
    char pfc[3];
    bool A5;                // E-0xf9
    Vec3 v0f8;              // E-0xf8
    Bounds b0ec;            // E-0xec
    float f0dc;             // E-0xdc
    Vec3 v0d8;              // E-0xd8
    Matrix mcc;             // E-0xcc
    Vec3 v08c;              // E-0x8c
    Matrix m80;             // E-0x80
    Matrix m40;             // E-0x40
};

class CSPHulkPropInstance : public pure3d::prop::StateProp {
public:
    char pad4[0x40 - 4];
    int i40;
    float f44;
    char pad48[0x98 - 0x48];
    ObjArr *p98;
    char pad9c[0xa0 - 0x9c];
    Holder *pa0;
    char pada4[0xec - 0xa4];
    StateObj *pec;
    char padf0[0x111 - 0xf0];
    unsigned char b111;
    char pad112[0x114 - 0x112];
    int i114;
    char pad118[0x11c - 0x118];
    PosProvider *p11c;
    Waypoints *p120;
    int i124;
    float f128;
    unsigned char b12c;
    char pad12d[0x154 - 0x12d];
    float f154;
    Vec3 v158;
    char pad164[0x1c8 - 0x164];
    unsigned char b1c8;
    unsigned char b1c9;
    char pad1ca[0x1cc - 0x1ca];
    int h1cc;
    char pad1d0[0x200 - 0x1d0];
    Vec3 v200;
    Vec3 v20c;
    float f218;
    Obj21c *p21c;
    int i220;
    char pad224[0x248 - 0x224];
    int i248;
    Obj24c *p24c;
    char pad250[0x258 - 0x250];
    Entity *p258;
    float f25c, f260, f264, f268;
    unsigned char b26c;
    char pad26d[0x270 - 0x26d];
    float f270;

    void FUN_001d8fc0(float dt);

    void FUN_001d69f0(Vec3 *out);
    void FUN_001d82a0();
    void FUN_001d8cd0();
    void FUN_001d8d90(int on);
    void FUN_001d71e0(int a);
    bool FUN_001d7360(Bounds *b);
    Obj72e0 *FUN_001d72e0();
    void FUN_001d7d50();
    float FUN_001d8160();
    void FUN_001d6b60(Matrix m, float s);

    Entity *GetEntity() { return pa0 ? pa0->p10 : 0; }
    const Vec3 *GetPos()
    {
        if (pa0)
            return &pa0->FUN_002fc6f0()->t;
        return p11c->v4();
    }
};

void CSPHulkPropInstance::FUN_001d8fc0(float dt)
{
    Frame F;
    float &sec = F.f140;

    sec = dt * 0.001f;
    f154 = f154 + sec;
    b111 = 0;
    if (f270 > 0.0f) {
        if (pa0) {
            Entity *e = pa0->p10;
            if (e) {
                Ctl *c = e->p70;
                if (c) {
                    if (c->v11())
                        GetEntity()->p70->v13();
                }
            }
        }
        f270 = f270 - sec;
    }

    b1c8 = 0;
    if (pa0) {
        Entity *e = pa0->p10;
        if (e) {
            Ctl *c = e->p70;
            if (c) {
                if (!c->v11()) {
                    if (FUN_000964d0()->FUN_00078780() < 0.005f)
                        GetEntity()->p70->v10();
                }
            }
        }
    }

    if (pec->FUN_001d4e50()) {
        bool b = FUN_001c3d90()->FUN_001c3c90();
        if (!b || b26c) {
            F.v130 = *FUN_001c3d90()->FUN_001c39d0();
            const Vec3 *p = GetPos();
            float dx = F.v130.x - p->x;
            float dy = F.v130.y - p->y;
            float dz = F.v130.z - p->z;
            bool nearP = (dx * dx + dy * dy + dz * dz) <= 6400.0f;
            if (!b) {
                if (nearP) {
                    b26c = 1;
                    FUN_001c3d90()->FUN_001c3ca0(1);
                }
            } else if (!nearP) {
                FUN_001c3d90()->FUN_001c3ca0(0);
                b26c = 0;
            }
        }
    }

    if (b1c9) {
        F.A5 = pec->FUN_001d4de0() == 5;
        F.A3 = pec->FUN_001d5e80(i40) == 3;
        bool A2 = pec->FUN_001d5e80(i40) == 2;
        Ctl *ctl = GetEntity()->p70;

        if (f218 > 0.0f) {
            F.dir = v200;
            f218 = f218 - (float)sqrt(v200.x * v200.x + v200.y * v200.y + v200.z * v200.z) * sec;
            F.f134 = F.dir.FUN_0022d110();          // l2
            if (p21c != 0) {
                F.v130.x = 0.0f;
                F.v130.y = 0.0f;
                F.v130.z = 0.0f;
                if (ctl)
                    F.v130 = ctl->v98;
                else
                    FUN_001d69f0(&F.v130);
                F.f13c = 0.0f;
                if (A2)
                    F.f13c = 1.0f;
                if (FUN_00098190(sec, F.f134, i220, 0, p21c, F.f13c, &F.v130, &F.dir, 0, 0, 0, 1)) {
                    v200 = F.dir;
                    v200.x = F.f134 * v200.x;
                    v200.y = F.f134 * v200.y;
                    v200.z = F.f134 * v200.z;
                    DAT_004dd700->p20->FUN_00029bb0(GetEntity(), p21c, f218);
                } else {
                    FUN_001d82a0();
                }
            }

            if (F.A3) {
                F.v0d8.x = 0.0f;
                F.v0d8.y = 0.0f;
                F.v0d8.z = 0.0f;
                if (ctl)
                    F.v0d8 = ctl->v98;
                else
                    FUN_001d69f0(&F.v0d8);
                F.f13c = 0.0f;
                F.s74 = 0;
                if (pa0) {
                    Entity *e = pa0->p10;
                    if (e) {
                        F.s74 = e->p74;
                        if (F.s74) {
                            P20 *q = F.s74->p20;
                            if (q)
                                F.f13c = q->f34;
                        }
                    }
                }
                F.sv = 1;
                if (F.s74) {
                    F.sv = F.s74->b72;
                    F.s74->b72 = 0;
                }
                F.v0f8.x = F.v0d8.x;
                F.v0f8.y = F.v0d8.y + 0.5f;
                F.v0f8.z = F.v0d8.z;
                F.hitObj = 0;
                if (FUN_00202560(&F.v0f8, F.f13c + 1.0f, 1, &F.v10c, &F.b0ec, &F.v130, &F.hitObj, 0)) {
                    if (F.hitObj) {
                        switch (F.hitObj->type) {
                        case 1:
                        case 6:
                        case 7:
                            F.v10c = F.v130;
                            break;
                        case 5: {
                            Hit8 *h8 = F.hitObj->p8;
                            if (h8) {
                                if (h8->i148 != 0)
                                    F.v10c = F.v130;
                                else if (!F.hitObj->p74->b50)
                                    F.v10c = F.v130;
                            }
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    F.f100 = F.v0d8.y - F.v10c.y;
                    bool done = false;
                    if (F.f100 < F.f13c + 0.5f) {
                        F.f0dc = v200.FUN_0022d110();
                        v200.y = F.dir.y;
                        v200.x = F.dir.x;
                        v200.z = F.dir.z;
                        v200.y = 0.0f;
                        v200.FUN_0022d110();
                        v200.FUN_00011140(F.f0dc);
                        if (F.f100 < F.f13c && ctl) {
                            ctl->v6(0);
                            ctl->FUN_0016fc90(&F.v08c);
                            v200.y = F.v08c.y * 0.25f;
                            v200.FUN_0022d110();
                            v200.FUN_00011140(F.f0dc);
                            done = true;
                        }
                    }
                    if (!done) {
                        if (p21c == 0)
                            i248 = 1;
                    }
                } else {
                    F.A3 = false;
                }
                if (F.s74)
                    F.s74->b72 = F.sv;
            }

            if (i248 <= 0) {
                if (F.A5) {
                    if (!(DAT_004e263c & 1)) {
                        DAT_004e263c |= 1;
                        DAT_004e2630.x = 0.0f;
                        DAT_004e2630.y = -1.0f;
                        DAT_004e2630.z = 0.0f;
                    }
                    if (F.f134 > 0.0f) {
                        F.m80.FUN_0022b980();
                        if (!FUN_00018960(F.dir.y, DAT_004e2630.y, 1e-05f))
                            FUN_00224db0(&F.m80, &DAT_004e2630, &F.dir);
                        v20c.z = dt * v20c.x * 0.001f + v20c.z;
                        F.m40.FUN_0022b980();
                        F.m40.FUN_0022ba70(v20c.z);
                        F.mcc.FUN_0022b980();
                        F.mcc.FUN_0022ca90(&F.m40, &F.m80);
                        F.mcc.t = FUN_001d72e0()->v40;
                        FUN_001d72e0()->v6(&F.mcc, 0);
                    }
                } else {
                    Entity *e = GetEntity();
                    e->v5c.x = v20c.x;
                    e->v5c.y = v20c.y;
                    e->v5c.z = v20c.z;
                }
                if (ctl) {
                    ctl->v6(0);
                    ctl->FUN_002f5a20(&v200);
                }
            } else {
                if (F.A3) {
                    ctl->v6(0);
                    ctl->p10->v8(&ctl->v98, &F.v0f8, -1);
                    F.f13c = v200.FUN_0022d110();
                    v200.y = F.v0f8.y;
                    v200.x = F.v0f8.x;
                    v200.z = F.v0f8.z;
                    v200.FUN_0022d110();
                    v200.x = F.f13c * v200.x;
                    v200.y = F.f13c * v200.y;
                    v200.z = F.f13c * v200.z;

                    Vec3 *s = &v20c;
                    F.f13c = (float)sqrt(s->x * s->x + s->y * s->y + s->z * s->z);
                    Entity *e = GetEntity();
                    s->x = e->v5c.x;
                    s->y = e->v5c.y;
                    s->z = e->v5c.z;
                    s->FUN_0022d110();
                    s->x = F.f13c * s->x;
                    s->y = F.f13c * s->y;
                    s->z = F.f13c * s->z;
                }
            }

            i248 = i248 - 1;
            if (!F.A3 && p21c == 0)
                FUN_001d8cd0();
        }

        {
            Entity *e = GetEntity();
            if (e->v50.x * e->v50.x + e->v50.y * e->v50.y + e->v50.z * e->v50.z < 25.0f) {
                FUN_001d8d90(0);
                FUN_001d71e0(0);
            }
        }
    }

    if (h1cc != 0) {
        Mgr *mgr = DAT_004dd700->p20->p8;
        void *d0 = mgr->FUN_00067ad0(h1cc);
        if (d0) {
            if (FUN_001d7360(&F.b0ec)) {
                Descriptor &desc = (Descriptor &)F.mcc;
                desc.FUN_00067e60(d0);
                Entity *e = GetEntity();
                if (e) {
                    F.v130 = e->v50;
                    // the returned length stays unrounded on the x87 stack (no float local)
                    F.b0ec.w = (F.v130.FUN_0022d110() * dt * 0.001f + F.b0ec.w) * 4.0f;
                    // the original multiplies by the stored (float-rounded) w, not the x87 register
                    volatile float *rw = &F.b0ec.w;
                    F.v130.z = F.v130.z * *rw;
                    F.b0ec.x = F.b0ec.x + F.v130.x * *rw;
                    F.b0ec.y = F.b0ec.y + F.v130.y * *rw;
                    F.b0ec.z = F.b0ec.z + F.v130.z;
                }
                desc.bounds = F.b0ec;
                mgr->FUN_00067c30(h1cc, &desc);
                desc.FUN_000679c0();
            } else {
                mgr->FUN_00067c80(h1cc);
                h1cc = 0;
            }
        } else {
            h1cc = 0;
        }
    }

    if (p120) {
        if (i124 >= 0 && i124 < p120->i14) {
            Entity *e = GetEntity();
            if (e) {
                e->FUN_002ef8b0(0);
                e->v7();
            }
            F.f134 = sec;
            Item24 *item = p120->FUN_00106160(i124);
            F.dir = *GetPos();
            float tz = item->v.z - F.dir.z;
            float ty = item->v.y - F.dir.y;
            float tx = item->v.x - F.dir.x;
            F.v0f8.x = tx;
            F.v0f8.y = ty;
            F.v0f8.z = tz;
            if (F.v0f8.FUN_0022d110() <= 0.5f)
                i124 = item->i0c;
            F.v10c.y = 0.0f;
            if (b12c) {
                F.v10c.x = -1.0f;
                F.v10c.z = 0.0f;
            } else {
                F.v10c.x = 0.0f;
                F.v10c.z = -1.0f;
            }
            vfunc_15()->FUN_0022c3b0(&F.v10c, &F.v130);
            F.f140 = FUN_00224f10(&F.v130);
            F.f118 = FUN_00224f10(&F.v0f8);
            F.f110 = F.f134 * 3.0f;
            F.f100 = FUN_00224fc0(F.f140, F.f118);
            F.f13c = F.f100;
            F.u13c &= 0x7fffffff;
            if (F.f13c <= F.f110)
                F.f140 = F.f118;
            else
                F.f140 = FUN_00083d90(&F.f100) * F.f110 + F.f140;
            F.v130 = DAT_004c6068;
            FUN_00224d70(F.f140, &F.v130);
            float step = F.f134 * f128;
            F.f118 = -1.5707964f;
            F.dir.x = F.v130.x * step + F.dir.x;
            F.dir.y = F.v130.y * step + F.dir.y;
            F.dir.z = F.v130.z * step + F.dir.z;
            if (!b12c)
                F.f118 = 0.0f;
            F.mcc.FUN_0022b980();
            F.mcc.FUN_0022ba70(F.f118 + F.f140);
            F.mcc.FUN_0022be40(&F.dir);
            FUN_001d6b60(F.mcc, F.f134);
        } else {
            p120->v1();
            p120 = 0;
            f128 = 10.0f;
            i124 = 0;
            b12c = 1;
        }
    }

    if (p24c) {
        if (p24c->i0c == 0) {
            p24c->v1();
            p24c = 0;
        }
    }

    int old40 = i40;
    F.f118 = f44;
    pure3d::prop::StateProp::vfunc_6(dt, 0);
    int new40 = i40;
    F.f0dc = f44;
    if (new40 != old40)
        F.f118 = 0.0f;
    FUN_001d7d50();
    if (new40 != -1) {
        F.o = p98->arr[i40];
        F.count = F.o->count;
        if (F.count > 0) {
            int off = 0;
            do {
                Elem *el = (Elem *)((char *)F.o->elems + off);
                if (!(DAT_004e263c & 2)) {
                    DAT_004e263c |= 2;
                    Key64 k = FUN_0027b020("StateProp");
                    DAT_004e2628 = k.lo;
                    DAT_004e262c = k.hi;
                }
                if (!(DAT_004e263c & 4)) {
                    DAT_004e263c |= 4;
                    Key64 k = FUN_0027b020("Explosion");
                    DAT_004e2620 = k.lo;
                    DAT_004e2624 = k.hi;
                }
                if (!(el->f50 < F.f118) && el->f50 < F.f0dc) {
                    if (el->lo40 == DAT_004e2628 && el->hi44 == DAT_004e262c) {
                        Root *g = DAT_004dd700;
                        if (g) {
                            Root0c *m = g->p0c;
                            if (m) {
                                CSPHulkPropInstance *r = m->FUN_001e47e0(this, el);
                                if (r)
                                    p258 = r->GetEntity();
                            }
                        }
                    } else if (el->lo40 == DAT_004e2620 && el->hi44 == DAT_004e2624) {
                        F.dir = el->v0;
                        vfunc_15()->FUN_0022c3b0(&F.dir, &F.dir);
                        const Vec3 *pp = GetPos();
                        F.dir.x = F.dir.x + pp->x;
                        F.dir.y = F.dir.y + pp->y;
                        F.dir.z = F.dir.z + pp->z;
                        int idx = 0;
                        while (idx < 6) {
                            if (el->lo28 == DAT_004e25a0[idx].lo && el->hi2c == DAT_004e25a0[idx].hi)
                                break;
                            idx++;
                        }
                        Obj24c *ob = 0;
                        if (p24c && p24c->i0c == 1)
                            ob = p24c;
                        DAT_004dd700->p10->FUN_001b4620(F.dir, idx, GetEntity(), ob);
                    }
                }
                off += 0x58;
                F.count--;
            } while (F.count != 0);
        }
    }

    // water level crossing
    const Vec3 *ppos = GetPos();
    F.v10c.z = ppos->z;
    F.v10c.y = ppos->y;
    float posX = ppos->x;
    Root *g = DAT_004dd700;
    F.f140 = g->p24->f18;                    // water level wl
    F.r24 = g->p24;
    bool cross;
    if (F.v10c.y <= F.f140 && v158.y > F.f140)
        cross = true;
    else
        cross = (F.v10c.y >= F.f140) && (v158.y < F.f140);
    if (cross) {
        Layer54 *lay = g->p54->FUN_000862a0();
        int r = lay->FUN_00204200(posX, F.v10c.y, F.v10c.z);
        if (r < 0 || lay->FUN_00204440(r)) {
            Root24 *r24 = F.r24;
            if ((r24->lo20 | r24->hi24) != 0) {
                Fx *fx = FUN_0027f250();
                F.mcc.FUN_0022b980();
                const Vec3 *p2 = GetPos();
                F.mcc.t.x = p2->x;
                F.mcc.t.y = p2->y;
                F.mcc.t.z = p2->z;
                F.mcc.t.y = F.f140;
                F.f134 = FUN_001d8160() * 0.01f;
                if (!(F.f134 < 0.5f)) {
                    if (!(F.f134 <= 10.0f))
                        F.f134 = 10.0f;
                } else {
                    F.f134 = 0.5f;
                }
                fx->FUN_00283a40(&r24->lo20, &F.mcc, -1.0f, F.f134);
            }
            if (r24->c28[0] != 0)
                g->p34->FUN_001ec060(this, r24->c28);
            if (F.v10c.y <= F.f140) {
                if (i114 == 0) {
                    Ctl *c2 = GetEntity()->p70;
                    if (c2) {
                        c2->v6(0);
                        c2->p10->v8(&c2->v98, &F.v130, -1);
                        F.v130.x = F.v130.x * 0.25f;
                        F.v130.y = F.v130.y * 0.25f;
                        F.v130.z = F.v130.z * 0.25f;
                        c2->FUN_002f5a20(&F.v130);
                        Entity *e2 = GetEntity();
                        e2->v5c.x = e2->v5c.x * 0.25f;
                        e2->v5c.y = e2->v5c.y * 0.25f;
                        e2->v5c.z = e2->v5c.z * 0.25f;
                        if (f218 > 0.0f) {
                            f218 = f218 * 0.25f;
                            v200.x = v200.x * 0.25f;
                            v200.y = v200.y * 0.25f;
                            v200.z = v200.z * 0.25f;
                            v20c.x = v20c.x * 0.25f;
                            v20c.y = v20c.y * 0.25f;
                            v20c.z = v20c.z * 0.25f;
                        }
                    }
                }
            }
        }
    }

    if (F.v10c.y < F.f140) {
        if (pa0 && pa0->p10) {
            if (!pec->FUN_001d4e40()) {
                Ctl *c3 = GetEntity()->p70;
                if (c3) {
                    c3->v6(0);
                    c3->p10->v8(&c3->v98, &F.v0f8, -1);
                    if (F.v0f8.y < -10.0f) {
                        F.v0f8.y = -10.0f;
                        c3->FUN_002f5a20(&F.v0f8);
                    }
                }
            }
        }
    }

    const Vec3 *pf = GetPos();
    v158.x = pf->x;
    v158.y = pf->y;
    v158.z = pf->z;
    if (f268 > 0.5f) {
        f264 = 0.0f;
        f260 = 0.0f;
        f25c = 0.0f;
        f268 = 0.0f;
    }
    f268 = dt + f268;
}
