// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 38/38)
// FUN_0003ba60 @ 0x0003ba60
struct V3_3ba60 {
    float x, y, z;
};

struct Mat4_3ba60 {
    float m[12];
    V3_3ba60 trans;
    float w;
    void FUN_0022c120();
    void FUN_0022ca90(const Mat4_3ba60 *a, const Mat4_3ba60 *b);
};

struct Xform_3ba60 {
    char data[0x54];
    void FUN_00221b70(const Mat4_3ba60 *m);
    void FUN_00221e60(const Mat4_3ba60 *m);
    Mat4_3ba60 *FUN_00221c40();
};

struct EventFlags {
    char pad0[0x18];
    char flag18;
};

struct EventMid {
    char pad0[0x20];
    EventFlags *flags;
};

struct Event_3ba60 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat4_3ba60 *m, int arg);
    char pad04[0x74 - 4];
    EventMid *mid;
    void FUN_002ef8b0(int v);
};

struct Link_3ba60 {
    int FUN_001d5e80(int v);
    unsigned __int64 FUN_001d4f70();
};

struct Effect_3ba60 {
    char pad0[0x20];
    char b20, b21, b22, b23;
    void FUN_002845a0();
};

struct Holder_3ba60 {
    char pad0[0x18];
    Effect_3ba60 *effect;
};

struct Bank {
    int FUN_000446c0(int index);
};

struct Prop_3ba60 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Mat4_3ba60 *v15();
    char pad04[0x40 - 4];
    int f40;
    char pad44[0xec - 0x44];
    Link_3ba60 *link;                 // 0xec
    char padf0[0x11c - 0xf0];
    Holder_3ba60 *holder;             // 0x11c
    char pad120[0x1ec - 0x120];
    char b1ec;
    char pad1ed[3];
    V3_3ba60 offset;                  // 0x1f0
    Event_3ba60 *FUN_001d72e0();
    V3_3ba60 *FUN_001d6b40();
    void FUN_001d6b60(Mat4_3ba60 m, int flag);
};

struct Bones_3ba60 {
    char pad0[0x1c];
    char *mats;                 // 0x1c
};

struct SceneXf {
    char data[0x54];
    Mat4_3ba60 *FUN_00221c40();
};

struct Scene_3ba60 {
    char pad0[0x10];
    SceneXf xf;                 // 0x10
    Bones_3ba60 *bones;               // 0x64
    void FUN_00224260(unsigned int lo, unsigned int hi, Xform_3ba60 *x);
};

struct OwnerLink {
    char pad0[0x124];
    void *self;                 // 0x124
};

struct Args_3ba60 {
    char pad0[0x20];
    OwnerLink *link;            // 0x20
};

struct Source_3ba60 {
    Prop_3ba60 *prop;
    unsigned int bone;          // 0x04
    unsigned int idLo;          // 0x08
    unsigned int idHi;          // 0x0c
    Mat4_3ba60 mat;                   // 0x10
};

struct Holder10_3ba60 {
    Scene_3ba60 *FUN_00059a40();
};

extern unsigned __int64 DAT_004dc0c0;
extern unsigned __int64 DAT_004dc098;

struct Frame_3ba60 {
    class Fighter_3ba60 *self;        // 0x10
    Scene_3ba60 *scene;               // 0x14
    Source_3ba60 *src;                // 0x18
    int i;                      // 0x1c
    V3_3ba60 p;                       // 0x20
    OwnerLink *owner20;         // 0x2c
    Event_3ba60 *ev;                  // 0x30
    int pad34;
    float t38, t3c;             // 0x38
    Mat4_3ba60 m3;                    // 0x40
    Mat4_3ba60 m0;                    // 0x80
    Mat4_3ba60 m1;                    // 0xc0
    Xform_3ba60 x;                    // 0x100
    Mat4_3ba60 m2;                    // 0x154
    Mat4_3ba60 r;                     // 0x194
};

class Fighter_3ba60 {
public:
    char pad0[0x10];
    Holder10_3ba60 *holder;           // 0x10
    char pad14[0x11c - 0x14];
    Bank *bank;                 // 0x11c
    char pad120[0x3a8 - 0x120];
    Source_3ba60 slots[8];            // 0x3a8
    char pad628[0x22e9 - 0x628];
    char b22e9;
    void FUN_0003acf0(int slot, int a, int b, int c, int d, int e);
    void FUN_0003ba60(Args_3ba60 *args, int arg2);
};

void Fighter_3ba60::FUN_0003ba60(Args_3ba60 *args, int arg2)
{
    Frame_3ba60 f;
    f.owner20 = args->link;
    f.self = this;
    f.scene = holder->FUN_00059a40();
    if (!b22e9)
        return;
    f.i = 0;
    f.src = &slots[0];
    do {
        Prop_3ba60 *prop = f.src->prop;
        if (prop != 0) {
            if (prop->FUN_001d72e0() != 0) {
                if (!prop->FUN_001d72e0()->mid->flags->flag18) {
                    bool release = true;
                    if (bank != 0) {
                        Link_3ba60 *l = prop->link;
                        int r = bank->FUN_000446c0(f.i);
                        release = l != (Link_3ba60 *)r;
                    }
                    if (release) {
                        FUN_0003acf0(f.i, 0, -1, 0, 0, 0);
                        goto next;
                    }
                }
            }
            f.ev = prop->FUN_001d72e0();
            if (f.ev != 0)
                f.ev->FUN_002ef8b0(0);
            if (prop->link->FUN_001d5e80(prop->f40) == 4) {
                if (prop->link->FUN_001d4f70() == DAT_004dc0c0 || prop->link->FUN_001d4f70() == DAT_004dc098) {
                    Effect_3ba60 *e = prop->holder->effect;
                    e->FUN_002845a0();
                    e->b22 = 0;
                    e->b23 = 0;
                    e->b20 = 0;
                    e->b21 = 0;
                }
            }
            if (f.owner20 != 0 && prop->b1ec && f.owner20->self != (void *)this) {
                V3_3ba60 *pos = prop->FUN_001d6b40();
                float ox = prop->offset.x;
                float oy = prop->offset.y;
                float oz = prop->offset.z;
                f.p.x = ox + pos->x;
                f.p.y = oy + pos->y;
                f.p.z = oz + pos->z;
                f.m3 = *prop->v15();
                f.m3.trans.y = f.p.y;
                f.m3.trans.x = f.p.x;
                f.m3.trans.z = f.p.z;
                prop->FUN_001d6b60(f.m3, 0);
                return;
            }
            f.m0 = *prop->v15();
            Mat4_3ba60 *base;
            if (f.src->bone != 0xffff)
                base = (Mat4_3ba60 *)(f.scene->bones->mats + (f.src->bone << 6));
            else
                base = f.scene->xf.FUN_00221c40();
            f.m1 = *base;
            if ((f.src->idLo | f.src->idHi) != 0) {
                f.m2 = f.m1;
                f.m2.FUN_0022c120();
                f.m3 = f.src->mat;
                f.m3.FUN_0022c120();
                f.x.FUN_00221b70(&f.m3);
                f.x.FUN_00221e60(&f.m0);
                f.x.FUN_00221e60(&f.m2);
                f.scene->FUN_00224260(f.src->idLo, f.src->idHi, &f.x);
                f.r.FUN_0022ca90(&f.src->mat, f.x.FUN_00221c40());
            } else {
                f.r = f.src->mat;
            }
            f.m0.FUN_0022ca90(&f.r, &f.m1);
            if (f.ev != 0)
                f.ev->v6(&f.m0, arg2);
            prop->FUN_001d6b60(f.m0, 0);
        }
    next:
        f.i++;
        f.src++;
    } while (f.i < 8);
}
