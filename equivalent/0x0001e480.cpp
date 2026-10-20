// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8)
// CGrabAction::vfunc_6 @ 0x0001e480
struct Vec3_1e480 { float x, y, z; };

struct Mat_1e480 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3_1e480 *in, Vec3_1e480 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat_1e480 *matrices;
};

struct Body_1e480 {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter_1e480 { char pad[4]; };
Fighter_1e480 *__fastcall FUN_000592a0(void *owner);
Body_1e480 *__fastcall FUN_00059a40(Fighter_1e480 *f);

class CGrabAction;

class Link_1e480 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Stats_1e480 {
    char pad0[0x130];
    int active;
    char pad134[0x330 - 0x134];
    int f330;
    char pad334[0x1b64 - 0x334];
    CGrabAction *grab;
    void FUN_0003b190(Link_1e480 *link);
};
Stats_1e480 *__fastcall FUN_00059a30(Fighter_1e480 *f);

struct Data_1e480 {
    char pad0[0x20];
    Vec3_1e480 offset;
    int handle;
};

struct Flags_1e480 {
    char pad0[0x70];
    unsigned char on;
    char pad71;
    unsigned char off;
};

class Effect_1e480 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_1e480 *m, int arg);
    char pad04[4];
    CGrabAction *owner;
    int mode;
    char pad10[0x74 - 0x10];
    Flags_1e480 *flags;
};

struct EffectInit_1e480 {
    EffectInit_1e480 *FUN_002efe50(Vec3_1e480 *v, int handle);
};

void *__cdecl FUN_0008d690(unsigned int size);
Effect_1e480 *__cdecl FUN_002efca0(EffectInit_1e480 *init, const char *name);

struct Sys_1e480 {
    char pad0[8];
    void FUN_001b4230(Effect_1e480 *e);
};
Sys_1e480 *__cdecl FUN_001b6580();

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
    void *ownerObj;
    Data_1e480 *data;
    int matrixIndex;
    Effect_1e480 *effect;
    Vec3_1e480 pos;
};

class CGrabAction : public CAction {
public:
    virtual char vfunc_6(int arg);
};

char CGrabAction::vfunc_6(int arg)
{
    Fighter_1e480 *fighter = FUN_000592a0(ownerObj);
    Stats_1e480 *stats = FUN_00059a30(fighter);
    Body_1e480 *body = FUN_00059a40(fighter);
    if (body == 0)
        return 0;

    Vec3_1e480 off = data->offset;
    body->skeleton->matrices[matrixIndex].FUN_0022c2b0(&off, &pos);

    stats->grab = this;
    stats->f330 = 0;
    stats->FUN_0003b190(0);
    if (stats->active != 0) {
        EffectInit_1e480 *init = 0;
        void *mem = FUN_0008d690(0x48);
        if (mem != 0) {
            Vec3_1e480 zero;
            zero.x = 0; zero.y = 0; zero.z = 0;
            int handle = data->handle;
            init = ((EffectInit_1e480 *)mem)->FUN_002efe50(&zero, handle);
        }
        Effect_1e480 *e = FUN_002efca0(init, 0);
        e->mode = 4;
        e->owner = this;
        e->vfunc_0();
        if (effect != 0)
            ((Link_1e480 *)effect)->vfunc_1();
        effect = e;
        Flags_1e480 *fl = e->flags;
        fl->on = 1;
        fl->off = 0;
        FUN_001b6580()->FUN_001b4230(effect);
        Mat_1e480 t;
        t.FUN_0022b980();
        t.m[12] = pos.x;
        t.m[14] = pos.z;
        t.m[13] = pos.y;
        effect->vfunc_6(&t, 0);
    }
    return 1;
}
