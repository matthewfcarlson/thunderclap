// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::ThreatBallAction::vfunc_5 @ 0x0012b910
#include "gen/hulkfight.h"
#include "decls/address.h"

struct Vec3_12b910 { float x, y, z; };

struct Mat_12b910 {
    float m[16];
    void FUN_0022ca90(Mat_12b910 *src, int arg);
    void FUN_0022c2b0(const Vec3_12b910 *in, Vec3_12b910 *out);
};

struct JointFinder_12b910 {
    unsigned int FUN_0027b200(int a, int b);
};

struct Skeleton_12b910 {
    char pad0[8];
    JointFinder_12b910 *finder;
    char pad0c[0x1c - 0xc];
    Mat_12b910 *matrices;
};

class Attach_12b910 {
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
    Skeleton_12b910 *FUN_001d68d0();
};

struct Stats_12b910 {
    char pad0[0x120];
    Skeleton_12b910 *skeleton;
    Attach_12b910 *FUN_00035ef0(int slot);
};

struct Fighter_12b910 { char pad[4]; };
Fighter_12b910 *__fastcall FUN_000592a0(void *owner);
Stats_12b910 *__fastcall FUN_00059a30(Fighter_12b910 *f);

struct Sink_12b910;

struct Request_12b910 {
    void *source;
    Vec3_12b910 pos;
    float extra;
    char pad14[0x20 - 0x14];
    void FUN_00067e20();
    void FUN_000679c0();
};

struct Sink_12b910 {
    void FUN_00067c30(int arg, Request_12b910 *req);
};

struct SinkHolder_12b910 {
    char pad0[8];
    Sink_12b910 *sink;
};

struct World {
    char pad0[0x20];
    SinkHolder_12b910 *holder;
};

struct Owner_12b910 {
    char pad0[8];
    void *f08;
};

struct Data_12b910 {
    char pad0[0x14];
    int slot;
    int f18;
    int f1c;
    Vec3_12b910 offset;
    float f2c;
};

bool hulkfight::ai::ThreatBallAction::vfunc_5(int msg, int unused) {
    if (msg == 1) {
        Sink_12b910 *sink = DAT_004dd700->holder->sink;
        Stats_12b910 *stats = FUN_00059a30(FUN_000592a0((*(Owner_12b910 * *)&this->f_20)));
        int slot = (*(Data_12b910 * *)&this->f_1c)->slot;
        Skeleton_12b910 *skel = stats->skeleton;
        Attach_12b910 *att = 0;
        unsigned int joint = 0;
        if (slot >= 0 && slot < 8) {
            att = stats->FUN_00035ef0(slot);
            if (att != 0) skel = att->FUN_001d68d0();
        }
        if (skel != 0) {
            JointFinder_12b910 *finder = skel->finder;
            if (((*(Data_12b910 * *)&this->f_1c)->f18 | (*(Data_12b910 * *)&this->f_1c)->f1c) != 0) {
                joint = finder->FUN_0027b200((*(Data_12b910 * *)&this->f_1c)->f18, (*(Data_12b910 * *)&this->f_1c)->f1c);
                if (joint == 0xffff) joint = 0;
            }
        }
        Vec3_12b910 world;
        Mat_12b910 M;
        world.x = 0; world.y = 0; world.z = 0;
        if (skel != 0) {
            Mat_12b910 *src = skel->matrices + joint;
            if (att != 0) {
                M.FUN_0022ca90(src, att->v15());
            } else {
                M = *src;
            }
            Vec3_12b910 local = (*(Data_12b910 * *)&this->f_1c)->offset;
            M.FUN_0022c2b0(&local, &world);
        }
        Request_12b910 req;
        req.FUN_00067e20();
        req.source = (*(Owner_12b910 * *)&this->f_20)->f08;
        req.pos = world;
        req.extra = (*(Data_12b910 * *)&this->f_1c)->f2c;
        sink->FUN_00067c30(this->f_24, &req);
        req.FUN_000679c0();
    }
    return true;
}
