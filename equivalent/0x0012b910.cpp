// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::ThreatBallAction::vfunc_5 @ 0x0012b910
struct Vec3 { float x, y, z; };

struct Mat {
    float m[16];
    void FUN_0022ca90(Mat *src, int arg);
    void FUN_0022c2b0(const Vec3 *in, Vec3 *out);
};

struct JointFinder {
    unsigned int FUN_0027b200(int a, int b);
};

struct Skeleton {
    char pad0[8];
    JointFinder *finder;
    char pad0c[0x1c - 0xc];
    Mat *matrices;
};

class Attach {
public:
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
    virtual int v15();
    Skeleton *FUN_001d68d0();
};

struct Stats {
    char pad0[0x120];
    Skeleton *skeleton;
    Attach *FUN_00035ef0(int slot);
};

struct Fighter { char pad[4]; };
Fighter *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(Fighter *f);

struct Sink;

struct Request {
    void *source;
    Vec3 pos;
    float extra;
    char pad14[0x20 - 0x14];
    void FUN_00067e20();
    void FUN_000679c0();
};

struct Sink {
    void FUN_00067c30(int arg, Request *req);
};

struct SinkHolder {
    char pad0[8];
    Sink *sink;
};

struct World {
    char pad0[0x20];
    SinkHolder *holder;
};
extern World *DAT_004dd700;

struct Owner {
    char pad0[8];
    void *f08;
};

struct Data {
    char pad0[0x14];
    int slot;
    int f18;
    int f1c;
    Vec3 offset;
    float f2c;
};

class ThreatBallAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int msg, int unused);
    char pad04[0x1c - 4];
    Data *data;
    Owner *owner;
    int arg;
};

bool ThreatBallAction::vfunc_5(int msg, int unused)
{
    if (msg == 1) {
        Sink *sink = DAT_004dd700->holder->sink;
        Stats *stats = FUN_00059a30(FUN_000592a0(owner));
        int slot = data->slot;
        Skeleton *skel = stats->skeleton;
        Attach *att = 0;
        unsigned int joint = 0;
        if (slot >= 0 && slot < 8) {
            att = stats->FUN_00035ef0(slot);
            if (att != 0) skel = att->FUN_001d68d0();
        }
        if (skel != 0) {
            JointFinder *finder = skel->finder;
            if ((data->f18 | data->f1c) != 0) {
                joint = finder->FUN_0027b200(data->f18, data->f1c);
                if (joint == 0xffff) joint = 0;
            }
        }
        Vec3 world;
        Mat M;
        world.x = 0; world.y = 0; world.z = 0;
        if (skel != 0) {
            Mat *src = skel->matrices + joint;
            if (att != 0) {
                M.FUN_0022ca90(src, att->v15());
            } else {
                M = *src;
            }
            Vec3 local = data->offset;
            M.FUN_0022c2b0(&local, &world);
        }
        Request req;
        req.FUN_00067e20();
        req.source = owner->f08;
        req.pos = world;
        req.extra = data->f2c;
        sink->FUN_00067c30(arg, &req);
        req.FUN_000679c0();
    }
    return true;
}
