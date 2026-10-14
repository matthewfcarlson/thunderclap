// STATUS: equivalent (tools/equiv.py level 3: 2394 inputs, branch coverage 99/112, incomplete)
// FUN_001de4f0 @ 0x001de4f0
typedef unsigned __int64 u64_1de4f0;

struct V3_1de4f0 { float x, y, z; };
struct Mat4_1de4f0 { float m[16]; };

struct ResName {
    char data[12];
    const char *FUN_0027b010();
    void FUN_0027b040(const char *s);
    void FUN_0027af70(const ResName *other);
};

struct Sub_1de4f0 {
    char pad0[8];
    u64_1de4f0 id;                                  // 8
    int FUN_001d5e80(int a);
    int FUN_001d5dd0(int a);
    u64_1de4f0 FUN_001d4f40();
    float FUN_001d4ea0(int a);
    u64_1de4f0 FUN_001d4f70();
};

struct Dyn {
    char pad0[0x164];
    float f164;
    char pad168[0x1b8 - 0x168];
    float f1b8, f1bc, f1c0;
    char b1c4;
    char pad1c5[0x1e4 - 0x1c5];
    float f1e4;
    float f1e8;
    char pad1ec[0x1f1 - 0x1ec];
    unsigned char b1f1;
    void FUN_002f57d0(const V3_1de4f0 *v);
};

struct Q_1de4f0 {
    char pad0[0x70];
    Dyn *f70;
    void FUN_002ef440(void *what);
};

struct Obj_1de4f0 {
    char pad0[8];
    ResName name;                            // 8
    char padc[0x40 - 0x14];
    int f40;
    char pad44[0xec - 0x44];
    Sub_1de4f0 *fec;
    char padf0[0x148 - 0xf0];
    void *f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    int f19c;

    void FUN_001d6b60(Mat4_1de4f0 m, int z);
    void FUN_001d6270();
    void FUN_0027cb80(int v);
    void FUN_001d7b80(int a, int b);
    void *FUN_001d6b40();
    Q_1de4f0 *FUN_001d72e0();
};

struct Hook_1de4f0 {
    void FUN_001b4540(Obj_1de4f0 *o);
};
Hook_1de4f0 *FUN_001b6580();

struct Sink_1de4f0 {
    void FUN_001eb7e0(ResName *name, u64_1de4f0 *id, void *r, const V3_1de4f0 *a, const V3_1de4f0 *b, V3_1de4f0 zero, int flag);
};

struct Holder_1de4f0 {
    Sink_1de4f0 *FUN_000862e0();
};

struct World2_1de4f0 {
    char pad0[0x54];
    Holder_1de4f0 *f54;
};
extern World2_1de4f0 *DAT_004dd700;

struct Registry_1de4f0 {
    char pad0[8];
    u64_1de4f0 id;                                  // 8
    Obj_1de4f0 *FUN_001d5630(ResName *name, int v);
};

u64_1de4f0 FUN_0027b020(const char *s);
void *FUN_002f2750(u64_1de4f0 id);
void FUN_002f28d0(const char *s, float a, float b, float c, float d);

extern u64_1de4f0 DAT_004e2770;
extern u64_1de4f0 DAT_004dc0c0;
extern u64_1de4f0 DAT_004dc098;
extern u64_1de4f0 DAT_004dc078;
extern unsigned int DAT_004e2720;
extern u64_1de4f0 DAT_004e2718;                     // "car"
extern u64_1de4f0 DAT_004e2710;                     // "bus"
extern u64_1de4f0 DAT_004e2708;                     // "small_object"
extern u64_1de4f0 DAT_004e2700;                     // "large_vehicle"
extern u64_1de4f0 DAT_004e26d0;                     // "dumpster1_dumpster1"
extern u64_1de4f0 DAT_004e26f8;                     // "van_van"
extern u64_1de4f0 DAT_004e26f0;                     // "bus1_bus1"
extern u64_1de4f0 DAT_004e26e8;                     // "suv1_suv1"
extern u64_1de4f0 DAT_004e26e0;                     // "cubeVan_cubeVan"
extern u64_1de4f0 DAT_004e26d8;                     // "ambulance_ambulance"

#define INIT(bit, var, str) if (!(DAT_004e2720 & (bit))) { DAT_004e2720 = DAT_004e2720 | (bit); var = FUN_0027b020(str); }

struct TblA {
    u64_1de4f0 key;
    float f8;
    float fc;
};

struct TblB {
    u64_1de4f0 key;
    float a;
    float b;
    int c;
    int pad;
};

class World {
public:
    char pad0[0x1e824];
    int f1e824;
    char pad1e828[0x1ec60 - 0x1e828];
    TblA tblA[16];                           // 0x1ec60
    TblB tblB[16];                           // 0x1ed60

    Obj_1de4f0 *FUN_001de4f0(Registry_1de4f0 *reg, ResName *rn, int v, const Mat4_1de4f0 *m);
};

Obj_1de4f0 *World::FUN_001de4f0(Registry_1de4f0 *reg, ResName *rn, int v, const Mat4_1de4f0 *m)
{
    Obj_1de4f0 *o = reg->FUN_001d5630(rn, v);
    if (o == 0)
        return o;

    o->name.FUN_0027b040(rn->FUN_0027b010());
    o->name.FUN_0027af70(rn);
    o->FUN_001d6b60(*m, 0);
    o->FUN_001d6270();
    if (o->fec->id == DAT_004e2770) {
        o->f198 = 2;
        o->f19c = 0;
    }
    o->FUN_0027cb80(f1e824);
    FUN_001b6580()->FUN_001b4540(o);
    o->FUN_001d7b80(0, 5);

    int flag = 5;
    if (o->f148 != 0)
        flag = 2;
    World2_1de4f0 *w2 = DAT_004dd700;
    Sub_1de4f0 *s0 = o->fec;
    Holder_1de4f0 *h = w2->f54;
    V3_1de4f0 up;
    up.x = 0.0f; up.y = 1.0f; up.z = 0.0f;
    V3_1de4f0 zero;
    zero.x = 0.0f; zero.y = 0.0f; zero.z = 0.0f;
    V3_1de4f0 zv;
    zv.x = 0.0f; zv.y = 0.0f; zv.z = 0.0f;
    void *r = o->FUN_001d6b40();
    h->FUN_000862e0()->FUN_001eb7e0(&o->name, &s0->id, r, &zero, &up, zv, flag);

    if (o->fec->FUN_001d5e80(o->f40) == 3 || o->fec->FUN_001d5dd0(o->f40) == 3) {
        FUN_002f28d0("bowling_ball", 1.05f, 100.0f, -0.25f, 1000.0f);
        void *w = FUN_002f2750(FUN_0027b020("bowling_ball"));
        o->FUN_001d72e0()->FUN_002ef440(w);
        Dyn *d = o->FUN_001d72e0()->f70;
        d->f1b8 = 5.0f;
        d->f1bc = 5.0f;
        d->f1c0 = 5.0f;
        d->b1c4 = 1;
    } else if (o->FUN_001d72e0() != 0) {
        Sub_1de4f0 *s = o->fec;
        u64_1de4f0 none = FUN_0027b020("NONE");
        if (s->FUN_001d4f40() != none) {
            void *w = FUN_002f2750(o->fec->FUN_001d4f40());
            if (w != 0)
                o->FUN_001d72e0()->FUN_002ef440(w);
        }
    }

    if (o->FUN_001d72e0() == 0)
        return o;
    if (o->FUN_001d72e0()->f70 == 0)
        return o;
    Dyn *p = o->FUN_001d72e0()->f70;
    p->f164 = 1.0f;

    u64_1de4f0 key = reg->id;
    int idx = -1;
    int i;
    for (i = 0; i < 16; i++) {
        if (tblB[i].key == key) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) {
        p->f1e8 = tblB[idx].a;
        p->f1e4 = tblB[idx].b;
        int c = tblB[idx].c;
        if (c < 0)
            p->b1f1 = 0xff;
        else
            p->b1f1 = (unsigned char)c;
    } else {
        INIT(1, DAT_004e2718, "car");
        INIT(2, DAT_004e2710, "bus");
        INIT(4, DAT_004e2708, "small_object");
        INIT(8, DAT_004e2700, "large_vehicle");
        volatile float v = o->fec->FUN_001d4ea0(o->f40);
        if (v > 0.0f) {
            int j = -1;
            for (i = 0; i < 16; i++) {
                volatile float d = v - tblA[i].f8;
                volatile int bits = *(volatile int *)&d & 0x7fffffff;
                float ad = *(volatile float *)&bits;
                if (ad <= 1e-05f) {
                    j = i;
                    break;
                }
            }
            if (j >= 0) {
                u64_1de4f0 k = tblA[j].key;
                float val = 0.0f;
                bool store = true;
                if (k == DAT_004e2718) {
                    INIT(0x10, DAT_004e26d0, "dumpster1_dumpster1");
                    if (reg->id != DAT_004e26d0) {
                        val = 15.0f;
                        p->b1f1 = 0;
                    } else {
                        p->b1f1 = 1;
                        val = 6.0f;
                    }
                } else if (k == DAT_004e2710) {
                    val = 20.0f;
                } else if (k == DAT_004e2700) {
                    val = 10.0f;
                } else if (k == DAT_004e2708) {
                    val = 60.0f;
                } else {
                    store = false;
                }
                if (store) {
                    p->f1e8 = val;
                    p->f1e4 = val;
                }
            } else {
                INIT(0x20, DAT_004e26f8, "van_van");
                INIT(0x40, DAT_004e26f0, "bus1_bus1");
                INIT(0x80, DAT_004e26e8, "suv1_suv1");
                INIT(0x100, DAT_004e26e0, "cubeVan_cubeVan");
                INIT(0x200, DAT_004e26d8, "ambulance_ambulance");
                u64_1de4f0 k2 = reg->id;
                float val = 0.0f;
                bool store = true;
                if (k2 == DAT_004e26f8) {
                    val = 10.0f;
                    p->b1f1 = 0;
                } else if (k2 == DAT_004e26f0) {
                    val = 25.0f;
                    p->b1f1 = 0;
                } else if (k2 == DAT_004e26e0) {
                    val = 25.0f;
                    p->b1f1 = 1;
                } else if (k2 == DAT_004e26d8 || k2 == DAT_004e26e8) {
                    val = 10.0f;
                    p->b1f1 = 0;
                } else {
                    store = false;
                }
                if (store) {
                    p->f1e8 = val;
                    p->f1e4 = val;
                }
            }
        }
    }

    u64_1de4f0 st = o->fec->FUN_001d4f70();
    if (st == DAT_004dc0c0 || st == DAT_004dc098 || st == DAT_004dc078) {
        V3_1de4f0 dir;
        dir.x = 0.0f; dir.y = -0.5f; dir.z = 0.0f;
        o->FUN_001d72e0()->f70->FUN_002f57d0(&dir);
    }
    return o;
}
