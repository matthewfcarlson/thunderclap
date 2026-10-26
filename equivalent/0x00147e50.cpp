// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::CivilianDetachAction::vfunc_3 @ 0x00147e50
// hulkfight::motion::CivilianDetachAction::vfunc_3 @ 0x00147e50
// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x0027af30
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "decls/address.h"

struct Name {
    int lo;
    int hi;
    Name(const Name &o) throw();
};

struct Vec3_147e50 {
    float x, y, z;
};

struct Mat_147e50 {
    float m[12];
    Vec3_147e50 trans;
    float w;
    Mat_147e50 *FUN_0022ca90(Mat_147e50 *a, Mat_147e50 *b);
    void FUN_0022ba00();
    void FUN_0022bc20(float x, float y, float z);
};

struct Msg_147e50 {
    char data[0x20];
    void FUN_001c9cd0(Name key);
};

struct Dispatcher_147e50 {
    void FUN_001cbc20(Msg_147e50 *m);
};

struct World {
    char pad0[0x30];
    Dispatcher_147e50 *dispatcher;
};

struct Names_147e50 {
    int FUN_0027b200(__int64 key);
};

struct Skel_147e50 {
    char pad0[8];
    Names_147e50 *names;
    char pad0c[0x1c - 0x0c];
    Mat_147e50 *joints;
};

struct Target_147e50 {
    char pad0[8];
    Name name;
    char pad10[0x20 - 0x10];
    int f20;
    int f24;
    void FUN_00080cb0(int v);
    void FUN_00080e50(Mat_147e50 *m);
};

struct Fighter_147e50 {
    char pad0[0x120];
    Skel_147e50 *skel;
    Target_147e50 *FUN_00036020();
    void FUN_0003b160(Target_147e50 *t);
};

struct Holder_147e50 {
    Fighter_147e50 *FUN_00059a30();
};

struct Params_147e50 {
    Holder_147e50 *FUN_000592a0();
};

struct Xform_147e50 {
    char pad0[0x10];
    Vec3_147e50 pos;
    Vec3_147e50 rot;
};


struct Frame_147e50 {
    Vec3_147e50 tmp;
    Mat_147e50 a;
    Msg_147e50 msg;
    Mat_147e50 b;
};

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::CivilianDetachAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Fighter_147e50 *fighter = (*(Params_147e50 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return false;
    Target_147e50 *target = fighter->FUN_00036020();
    if (target == 0)
        return false;

    Frame_147e50 fr;
    fr.msg.FUN_001c9cd0(target->name);
    DAT_004dd700->dispatcher->FUN_001cbc20(&fr.msg);
    fighter->FUN_0003b160(0);
    target->FUN_00080cb0(4);
    target->f20 = 1;
    target->f24 = 0;

    Skel_147e50 *skel = fighter->skel;
    Names_147e50 *names = skel->names;
    int idx = names->FUN_0027b200(FUN_002672f0("Motion_Root", 0, 0));
    Mat_147e50 *joint = fighter->skel->joints + idx;

    fr.a.FUN_0022ba00();
    Xform_147e50 *xf = (*(Xform_147e50 * *)&this->f_1c);
    fr.tmp = xf->pos;
    fr.a.trans = fr.tmp;
    fr.a.FUN_0022bc20(xf->rot.x, xf->rot.y, xf->rot.z);
    fr.b.FUN_0022ca90(&fr.a, joint);
    target->FUN_00080e50(&fr.b);
    return true;
}
