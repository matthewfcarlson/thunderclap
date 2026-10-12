// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 11/12, incomplete; run with --inputs 12000)
// CCollisionAction::vfunc_7 @ 0x00014430
struct Vec3 { float x, y, z; };

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3 *in, Vec3 *out);
};

struct Anchor {
    Vec3 *FUN_001d6b40();
};

struct Registry {
    Anchor *FUN_001dee40(int lo, int hi);
};

struct Manager {
    char pad0[0xc];
    Registry *registry;
};
extern Manager *DAT_004dd700;

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
void *__fastcall FUN_00059a40(Fighter *f);
struct Stats {
    char pad[0x1d70];
    int idLo;
    int idHi;
};
Stats *__fastcall FUN_00059a30(Fighter *f);

struct Resource {
    int lo;
    int hi;
};

struct Data {
    char pad0[0x20];
    Vec3 offset;
    char pad2c[0x70 - 0x2c];
    Resource resource;
};

class Sink {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat *m, int arg);
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
    Data *data;
    int matrixIndex;
    char pad28[0x3c - 0x28];
    Sink *sink;
};

char CCollisionAction::vfunc_7(int arg)
{
    if (matrixIndex != 0)
        return 1;

    Fighter *fighter = FUN_000592a0(owner);
    Body *body = (Body *)FUN_00059a40(fighter);
    Stats *stats = FUN_00059a30(fighter);
    Mat *m = &body->skeleton->matrices[matrixIndex];

    Vec3 pos;
    Resource *res = &data->resource;
    Anchor *anchor = 0;
    if (res && (res->lo | res->hi) != 0 && (stats->idLo | stats->idHi) != 0)
        anchor = DAT_004dd700->registry->FUN_001dee40(stats->idLo, stats->idHi);

    if (anchor) {
        pos = *anchor->FUN_001d6b40();
        Vec3 off = data->offset;
        pos.x = off.x + pos.x;
        pos.y = off.y + pos.y;
        pos.z = off.z + pos.z;
    } else {
        Vec3 off = data->offset;
        m->FUN_0022c2b0(&off, &pos);
    }

    if (sink) {
        Mat t;
        t.FUN_0022b980();
        t.m[12] = pos.x;
        t.m[13] = pos.y;
        t.m[14] = pos.z;
        sink->vfunc_6(&t, arg);
    }
    return 1;
}
