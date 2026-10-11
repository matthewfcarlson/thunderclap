// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 8/8)
// CGrabAction::vfunc_6 @ 0x0001e480
struct Vec3 { float x, y, z; };

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3 *in, Vec3 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat *matrices;
};

struct Body {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter { char pad[4]; };
Fighter *__fastcall FUN_000592a0(void *owner);
Body *__fastcall FUN_00059a40(Fighter *f);

class CGrabAction;

class Link {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Stats {
    char pad0[0x130];
    int active;
    char pad134[0x330 - 0x134];
    int f330;
    char pad334[0x1b64 - 0x334];
    CGrabAction *grab;
    void FUN_0003b190(Link *link);
};
Stats *__fastcall FUN_00059a30(Fighter *f);

struct Data {
    char pad0[0x20];
    Vec3 offset;
    int handle;
};

struct Flags {
    char pad0[0x70];
    unsigned char on;
    char pad71;
    unsigned char off;
};

class Effect {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat *m, int arg);
    char pad04[4];
    CGrabAction *owner;
    int mode;
    char pad10[0x74 - 0x10];
    Flags *flags;
};

struct EffectInit {
    EffectInit *FUN_002efe50(Vec3 *v, int handle);
};

void *__cdecl FUN_0008d690(unsigned int size);
Effect *__cdecl FUN_002efca0(EffectInit *init, const char *name);

struct Sys {
    char pad0[8];
    void FUN_001b4230(Effect *e);
};
Sys *__cdecl FUN_001b6580();

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
    Data *data;
    int matrixIndex;
    Effect *effect;
    Vec3 pos;
};

class CGrabAction : public CAction {
public:
    virtual char vfunc_6(int arg);
};

char CGrabAction::vfunc_6(int arg)
{
    Fighter *fighter = FUN_000592a0(ownerObj);
    Stats *stats = FUN_00059a30(fighter);
    Body *body = FUN_00059a40(fighter);
    if (body == 0)
        return 0;

    Vec3 off = data->offset;
    body->skeleton->matrices[matrixIndex].FUN_0022c2b0(&off, &pos);

    stats->grab = this;
    stats->f330 = 0;
    stats->FUN_0003b190(0);
    if (stats->active != 0) {
        EffectInit *init = 0;
        void *mem = FUN_0008d690(0x48);
        if (mem != 0) {
            Vec3 zero;
            zero.x = 0; zero.y = 0; zero.z = 0;
            int handle = data->handle;
            init = ((EffectInit *)mem)->FUN_002efe50(&zero, handle);
        }
        Effect *e = FUN_002efca0(init, 0);
        e->mode = 4;
        e->owner = this;
        e->vfunc_0();
        if (effect != 0)
            ((Link *)effect)->vfunc_1();
        effect = e;
        Flags *fl = e->flags;
        fl->on = 1;
        fl->off = 0;
        FUN_001b6580()->FUN_001b4230(effect);
        Mat t;
        t.FUN_0022b980();
        t.m[12] = pos.x;
        t.m[14] = pos.z;
        t.m[13] = pos.y;
        effect->vfunc_6(&t, 0);
    }
    return 1;
}
