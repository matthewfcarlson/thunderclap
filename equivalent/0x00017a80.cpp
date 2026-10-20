// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// CSnapToWallAction::vfunc_6 @ 0x00017a80
#include "gen/global.h"

struct V3_17a80 {
    float x, y, z;
    float FUN_0022d110();
};

struct NameField_17a80 {
    void FUN_0027b040(const char *s);
};

struct Sub18_17a80 {
    void FUN_00221d20(float a);
    void FUN_0022be40(const V3_17a80 *v);
};

class Obj70_17a80 {
public:
    virtual void v0();
    char pad4[4];
    NameField_17a80 name;
    char pad1[0x18 - 0x9];
    Sub18_17a80 s18;
    char pad2[0x70 - 0x19];
    Obj70_17a80 *FUN_002248f0(int a);
};

struct Tracker_17a80 {
    void FUN_00222890(Obj70_17a80 *o, float a, float b, float c, float d, float e, float f);
};

struct Player_17a80 {
    char pad0[0x1a64];
    float f1a64;
    char pad1[0x1ab8 - 0x1a68];
    V3_17a80 f1ab8;
    V3_17a80 f1ac4;
};

struct Mgr_17a80 {
    Player_17a80 *FUN_00059a30();
    Tracker_17a80 *FUN_00059a40();
    bool FUN_00059a50(V3_17a80 *out);
};

struct Holder_17a80 {
    Mgr_17a80 *FUN_000592a0();
};

struct Cfg_17a80 {
    char pad0[0x14];
    float f14;
    V3_17a80 f18;
    char flag24;
    char pad3[3];
    float f28;
    float f2c;
    float f30;
};

void *FUN_00263ea0(unsigned int);
float FUN_00224f10(const V3_17a80 *v);
void FUN_00224d70(float angle, V3_17a80 *v);

bool CSnapToWallAction::vfunc_6(int arg) {
    struct Frame {
        union {
            float cf30;
            float ang;      // (reuses cf30's slot once the tracker call has consumed it)
        };
        float cf2c;
        Mgr_17a80 *mgr;
        V3_17a80 w;
        V3_17a80 u;
        V3_17a80 v;
        union {
            V3_17a80 t;
            float cf28;     // (dead until t is used: the original keeps cf28 in this frame's spare room)
        };
    } fr;
    fr.mgr = (*(Holder_17a80 * *)&this->f_1c)->FUN_000592a0();
    Player_17a80 *pl = fr.mgr->FUN_00059a30();
    Tracker_17a80 *tr = fr.mgr->FUN_00059a40();
    if (tr == 0)
        return false;
    Cfg_17a80 *c0 = (*(Cfg_17a80 * *)&this->f_20);
    fr.cf28 = c0->f28;
    fr.cf2c = c0->f2c;
    fr.cf30 = c0->f30;
    void *mem = FUN_00263ea0(0x70);
    Obj70_17a80 *o = 0;
    if (mem)
        o = ((Obj70_17a80 *)mem)->FUN_002248f0(0);
    (*(Obj70_17a80 * *)&this->f_24) = o;
    o->name.FUN_0027b040("snapToWall");
    (*(Obj70_17a80 * *)&this->f_24)->v0();
    tr->FUN_00222890((*(Obj70_17a80 * *)&this->f_24), -1.0f, fr.cf28, 1.0f, fr.cf2c, fr.cf30, -1.0f);

    fr.v = pl->f1ac4;
    fr.v.y = 0.0f;
    fr.v.FUN_0022d110();
    fr.ang = FUN_00224f10(&fr.v);
    (*(Obj70_17a80 * *)&this->f_24)->s18.FUN_00221d20(fr.ang + (*(Cfg_17a80 * *)&this->f_20)->f14);

    fr.w = pl->f1ab8;
    fr.u = (*(Cfg_17a80 * *)&this->f_20)->f18;
    FUN_00224d70(fr.ang, &fr.u);
    fr.w.x = fr.u.x + fr.w.x;
    fr.w.y = fr.u.y + fr.w.y;
    fr.w.z = fr.u.z + fr.w.z;
    if ((*(Cfg_17a80 * *)&this->f_20)->flag24) {
        fr.w.y = pl->f1a64;
    } else {
        fr.t.x = 0.0f;
        fr.t.y = 0.0f;
        fr.t.z = 0.0f;
        fr.mgr->FUN_00059a50(&fr.t);
        fr.w.y = fr.t.y;
    }
    (*(Obj70_17a80 * *)&this->f_24)->s18.FUN_0022be40(&fr.w);
    return true;
}
