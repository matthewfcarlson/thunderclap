// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 15/16, incomplete)
// CCollisionAction::vfunc_6 @ 0x0001a150
struct Vec3_1a150 { float x, y, z; };

struct Mat_1a150 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3_1a150 *in, Vec3_1a150 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat_1a150 *matrices;
};

struct Body_1a150 {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter_1a150 { char pad[4]; };
Fighter_1a150 *__fastcall FUN_000592a0(void *owner);
Body_1a150 *__fastcall FUN_00059a40(Fighter_1a150 *f);

class Link_1a150 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Stats_1a150 {
    char pad0[0x1b49];
    unsigned char hit;           // 0x1b49
    char pad1b4a[0x1d70 - 0x1b4a];
    unsigned int targetLo;       // 0x1d70
    unsigned int targetHi;       // 0x1d74
    bool FUN_00035ab0();
    void FUN_0003b580(int a, float b, float c);
};
Stats_1a150 *__fastcall FUN_00059a30(Fighter_1a150 *f);

struct Data_1a150 {
    char pad0[0x20];
    Vec3_1a150 offset;                 // 0x20
    int handle;                  // 0x2c
    char pad30[0x39 - 0x30];
    unsigned char flag39;
    char pad3a[0x58 - 0x3a];
    float f58;                   // 0x58
    char pad5c[0x70 - 0x5c];
    unsigned int idLo;           // 0x70
    unsigned int idHi;           // 0x74
};

struct Flags_1a150 {
    char pad0[0x70];
    unsigned char on;
    char pad71;
    unsigned char off;
};

class CAction;
class Effect_1a150 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_1a150 *m, int arg);
    char pad04[4];
    CAction *owner;
    int mode;
    char pad10[0x74 - 0x10];
    Flags_1a150 *flags;
};

struct EffectInit_1a150 {
    EffectInit_1a150 *FUN_002efe50(Vec3_1a150 *v, int handle);
};

void *__cdecl FUN_0008d690(unsigned int size);
Effect_1a150 *__cdecl FUN_002efca0(EffectInit_1a150 *init, const char *name);

struct Sys_1a150 {
    char pad0[8];
    void FUN_001b4190(Effect_1a150 *e);
};
Sys_1a150 *__cdecl FUN_001b6580();

struct Actor_1a150 {
    Vec3_1a150 *FUN_001d6b40();
};

struct Table_1a150 {
    Actor_1a150 *FUN_001dee40(unsigned int lo, unsigned int hi);
};

struct World {
    char pad0[0xc];
    Table_1a150 *table;                // 0x0c
};
extern World *DAT_004dd700;

class CAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void *ownerObj;              // 0x1c
    Data_1a150 *data;                  // 0x20
    int matrixIndex;             // 0x24
    Vec3_1a150 pos;                    // 0x28
    char pad34[0x3c - 0x34];
    Effect_1a150 *effect;              // 0x3c
};

class CCollisionAction : public CAction {
public:
    virtual char vfunc_6(int arg);
};

char CCollisionAction::vfunc_6(int arg)
{
    Fighter_1a150 *fighter = FUN_000592a0(ownerObj);
    Stats_1a150 *stats = FUN_00059a30(fighter);
    Body_1a150 *body = FUN_00059a40(fighter);
    stats->hit = 1;
    if (data->flag39) {
        if (stats->FUN_00035ab0())
            stats->FUN_0003b580(1, 3.1415927f, data->f58);
    }

    Vec3_1a150 off = data->offset;
    body->skeleton->matrices[matrixIndex].FUN_0022c2b0(&off, &pos);

    if ((data->idLo | data->idHi) != 0) {
        if ((stats->targetLo | stats->targetHi) != 0) {
            Actor_1a150 *a = DAT_004dd700->table->FUN_001dee40(stats->targetLo, stats->targetHi);
            if (a) {
                pos = *a->FUN_001d6b40();
                off = data->offset;
                pos.x = off.x + pos.x;
                pos.y = off.y + pos.y;
                pos.z = off.z + pos.z;
            }
        }
    }

    EffectInit_1a150 *init = 0;
    void *mem = FUN_0008d690(0x48);
    if (mem != 0) {
        off.x = 0;
        off.y = 0;
        off.z = 0;
        int handle = data->handle;
        init = ((EffectInit_1a150 *)mem)->FUN_002efe50(&off, handle);
    }
    Effect_1a150 *e = FUN_002efca0(init, 0);
    e->mode = 3;
    e->owner = this;
    e->vfunc_0();
    if (effect != 0)
        ((Link_1a150 *)effect)->vfunc_1();
    effect = e;
    Flags_1a150 *fl = e->flags;
    fl->on = 1;
    fl->off = 0;
    FUN_001b6580()->FUN_001b4190(effect);
    Mat_1a150 t;
    t.FUN_0022b980();
    t.m[12] = pos.x;
    t.m[14] = pos.z;
    t.m[13] = pos.y;
    effect->vfunc_6(&t, 0);
    return 1;
}
