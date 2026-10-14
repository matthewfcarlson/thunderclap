// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 11/12, incomplete; run with --inputs 12000)
// CCollisionAction::vfunc_7 @ 0x00014430
struct Vec3_14430 { float x, y, z; };

struct Mat_14430 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3_14430 *in, Vec3_14430 *out);
};

struct Anchor_14430 {
    Vec3_14430 *FUN_001d6b40();
};

struct Registry_14430 {
    Anchor_14430 *FUN_001dee40(int lo, int hi);
};

struct Manager_14430 {
    char pad0[0xc];
    Registry_14430 *registry;
};
extern Manager_14430 *DAT_004dd700;

struct Skeleton {
    char pad0[0x1c];
    Mat_14430 *matrices;
};

struct Body_14430 {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter_14430 { char pad[4]; };
Fighter_14430 *__fastcall FUN_000592a0(void *owner);
void *__fastcall FUN_00059a40(Fighter_14430 *f);
struct Stats_14430 {
    char pad[0x1d70];
    int idLo;
    int idHi;
};
Stats_14430 *__fastcall FUN_00059a30(Fighter_14430 *f);

struct Resource_14430 {
    int lo;
    int hi;
};

struct Data_14430 {
    char pad0[0x20];
    Vec3_14430 offset;
    char pad2c[0x70 - 0x2c];
    Resource_14430 resource;
};

class Sink_14430 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_14430 *m, int arg);
};

class CCollisionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(int arg);
    virtual void vfunc_8();

    char pad04[0x18];
    void *owner;
    Data_14430 *data;
    int matrixIndex;
    char pad28[0x3c - 0x28];
    Sink_14430 *sink;
};

char CCollisionAction::vfunc_7(int arg)
{
    if (matrixIndex != 0)
        return 1;

    Fighter_14430 *fighter = FUN_000592a0(owner);
    Body_14430 *body = (Body_14430 *)FUN_00059a40(fighter);
    Stats_14430 *stats = FUN_00059a30(fighter);
    Mat_14430 *m = &body->skeleton->matrices[matrixIndex];

    Vec3_14430 pos;
    Resource_14430 *res = &data->resource;
    Anchor_14430 *anchor = 0;
    if (res && (res->lo | res->hi) != 0 && (stats->idLo | stats->idHi) != 0)
        anchor = DAT_004dd700->registry->FUN_001dee40(stats->idLo, stats->idHi);

    if (anchor) {
        pos = *anchor->FUN_001d6b40();
        Vec3_14430 off = data->offset;
        pos.x = off.x + pos.x;
        pos.y = off.y + pos.y;
        pos.z = off.z + pos.z;
    } else {
        Vec3_14430 off = data->offset;
        m->FUN_0022c2b0(&off, &pos);
    }

    if (sink) {
        Mat_14430 t;
        t.FUN_0022b980();
        t.m[12] = pos.x;
        t.m[13] = pos.y;
        t.m[14] = pos.z;
        sink->vfunc_6(&t, arg);
    }
    return 1;
}
