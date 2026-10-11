// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 10/10)
// CGrappleSwapAction::vfunc_6 @ 0x000157c0
struct Vec3 { float x, y, z; };

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
    void FUN_0022c120();
    void FUN_0022ca90(Mat *a, Mat *b);
};

struct JointFinder {
    unsigned int FUN_0027b200(int a, int b);
};

struct SkeletonData {
    char pad0[8];
    JointFinder *finder;
    char pad0c[0x1c - 0xc];
    Mat *mats;
};

struct Resource {
    char pad0[0x64];
    SkeletonData *skeleton;
};

struct Registry {
    Resource *FUN_00059bf0(int id);
};

struct Globals {
    char pad0[0x44];
    Registry *registry;
};

struct Entity {
    char pad00[0x10];
    int *idPtr;
    char pad14[0x334 - 0x14];
    Entity *link;
    void FUN_000393c0();
    void FUN_00035160(Mat *out);
    void FUN_0003a680(Entity *target, int a, int b, int c, Mat *m, float e5, float e6, float e7);
};

struct GrappleData {
    char pad0[0x10];
    int jointA;
    int jointB;
    int f18;
    int f1c;
    unsigned char useOffset;
    char pad21[3];
    Vec3 offset;
    float angle;
    float f34;
    float f38;
    float f3c;
};

void *__fastcall FUN_000592a0(void *owner);
Entity *__fastcall FUN_00059a30(void *x);
extern Globals *DAT_004dd700;

class CGrappleSwapAction {
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
    void *owner;
    GrappleData *data;
};

char CGrappleSwapAction::vfunc_6(int arg)
{
    Mat swap;
    Mat inv;
    Mat cur;
    Vec3 pos;

    Entity *stats = FUN_00059a30(FUN_000592a0(owner));
    Entity *target = stats->link;
    if (target == 0)
        return 0;

    target->FUN_0003a680(0, -1, 0, 0, 0, 0.0f, 1.0f, data->f3c);
    target->link = stats;
    target->FUN_000393c0();

    int id = 0xffff;
    SkeletonData *skel = 0;
    Resource *res = DAT_004dd700->registry->FUN_00059bf0(*target->idPtr);
    if (res) {
        skel = res->skeleton;
        if (skel)
            id = skel->finder->FUN_0027b200(data->jointA, data->jointB);
    }

    if (data->useOffset) {
        swap.FUN_0022b980();
        pos = data->offset;
        swap.m[12] = pos.x;
        swap.m[13] = pos.y;
        swap.m[14] = pos.z;
        swap.FUN_0022ba70(data->angle);
    } else {
        if (id != 0xffff)
            inv = skel->mats[id];
        else
            target->FUN_00035160(&inv);
        inv.FUN_0022c120();
        target->FUN_00035160(&cur);
        swap.FUN_0022ca90(&cur, &inv);
    }

    stats->link = 0;
    GrappleData *d = data;
    stats->FUN_0003a680(target, id, d->f18, d->f1c, &swap, d->f34, 1.0f, d->f38);
    return 0;
}
