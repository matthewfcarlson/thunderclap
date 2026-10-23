// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 38/40, incomplete)
// CSmartPropAttachAction::vfunc_4 @ 0x00015b20
#include "gen/global.h"

struct V3_15b20 {
    float x, y, z;
    float FUN_0022d110();
};

struct Matrix_15b20 {
    float m[12];
    V3_15b20 pos;
    float w;
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022c120();
    void FUN_0022ca90(Matrix_15b20* a, Matrix_15b20* b);
};

struct Key {
    unsigned int lo;
    unsigned int hi;
};

struct Fighter_15b20 {
    char pad00[0x328];
    void* f328;
    char pad32c[0x20a8 - 0x32c];
    int f20a8;
    void FUN_00035160(Matrix_15b20* out);
    void FUN_000393c0();
    void FUN_0003acf0(int a, void* target, unsigned int joint, int d, int e, Matrix_15b20* m);
};

struct JointFinder {
    unsigned int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton_15b20 {
    char pad00[8];
    JointFinder* finder;
    char pad0c[0x1c - 0xc];
    char* table;
};

struct Rig {
    char pad00[0x64];
    Skeleton_15b20* skel;
};

struct Anchor_15b20 {
    Fighter_15b20* FUN_00059a30();
    Rig* FUN_00059a40();
};

struct Owner_15b20 {
    Anchor_15b20* FUN_000592a0();
};

struct Link_15b20 {
    void* link;
    char pad04[8];
    int kind;
};

struct Target;

struct Handle_15b20 {
    char pad00[8];
    Target* target;
    int kind;
};

struct Part_15b20 {
    int FUN_001d4de0();
};

struct Target {
    char pad00[0xec];
    Part_15b20* partEc;
    char padf0[0xfc - 0xf0];
    int state;
    void FUN_0027d4f0(int v);
    void FUN_001d8fc0(float v);
    Handle_15b20* FUN_001d6c90();
    void FUN_001d6ca0(int v);
    bool FUN_001d7300();
    void thunk_FUN_0027d410(const Key* k);
};

struct Attach {
    char pad00[0x14];
    int f14;
    Key joint;
    int f20;
    int f24;
    unsigned char hasLocal;
    char pad29[3];
    V3_15b20 offset;
    V3_15b20 localPos;
    float dist;
    char pad48[0x58 - 0x48];
    Key key;
};

struct Holder_15b20 {
    char pad00[8];
    Target* target;
    int kind;
    Matrix_15b20 mat;
};

struct Frame_15b20 {
    V3_15b20 d;
    float dist;
    Target* target;
    V3_15b20 q;
    Fighter_15b20* fighter;
    int p20;
    int p24;
    Matrix_15b20 m;
    Matrix_15b20 m2;
    Matrix_15b20 m3;
};

// equiv-map: ?thunk_FUN_0027d410@Target@@QAEXPBUKey@@@Z = 0x001d6630

void CSmartPropAttachAction::vfunc_4() {
    Frame_15b20 f;
    if ((*(Holder_15b20 * *)&this->f_24) == 0)
        return;
    if ((*(Holder_15b20 * *)&this->f_24)->kind != 5)
        return;
    Target* t = (*(Holder_15b20 * *)&this->f_24)->target;
    f.target = t;
    if (t == 0)
        return;
    if (t->state == 2 || t->state == 3)
        return;
    if (t->partEc->FUN_001d4de0() == 0) {
        t->FUN_0027d4f0(5);
        t->FUN_001d8fc0(0.001f);
        if (t->FUN_001d6c90() != 0) {
            if (t->FUN_001d6c90()->kind == 5) {
                Target* nt = t->FUN_001d6c90()->target;
                t->FUN_001d6ca0(0);
                f.target = nt;
                t = nt;
            }
        }
    }
    if (t == 0)
        return;
    if (!t->FUN_001d7300())
        return;

    unsigned int joint = 0xffff;
    Anchor_15b20* anchor = (*(Owner_15b20 * *)&this->f_1c)->FUN_000592a0();
    f.fighter = anchor->FUN_00059a30();
    Rig* rig = anchor->FUN_00059a40();
    Skeleton_15b20* skel = 0;
    if (rig != 0) {
        skel = rig->skel;
        if (skel != 0)
            joint = skel->finder->FUN_0027b200((*(Attach * *)&this->f_20)->joint.lo, (*(Attach * *)&this->f_20)->joint.hi);
    }
    f.p24 = (*(Attach * *)&this->f_20)->f24;
    f.p20 = (*(Attach * *)&this->f_20)->f20;
    if ((*(Attach * *)&this->f_20)->hasLocal) {
        f.m.FUN_0022b980();
        f.m.FUN_0022bc20((*(Attach * *)&this->f_20)->localPos.x, (*(Attach * *)&this->f_20)->localPos.y, (*(Attach * *)&this->f_20)->localPos.z);
        f.d = (*(Attach * *)&this->f_20)->offset;
        f.m.pos = (*(Attach * *)&this->f_20)->offset;
    } else {
        if (joint != 0xffff)
            f.m2 = *(Matrix_15b20*)(skel->table + joint * 64);
        else
            f.fighter->FUN_00035160(&f.m2);
        f.m2.FUN_0022c120();
        f.m3 = (*(Holder_15b20 * *)&this->f_24)->mat;
        f.m.FUN_0022ca90(&f.m3, &f.m2);
        f.dist = (*(Attach * *)&this->f_20)->dist;
        if (f.dist > 0.0f) {
            f.d = f.m.pos;
            f.q = (*(Attach * *)&this->f_20)->offset;
            f.d.x = f.d.x - f.q.x;
            f.d.y = f.d.y - f.q.y;
            f.d.z = f.d.z - f.q.z;
            if (f.d.FUN_0022d110() > f.dist) {
                f.d.x = f.d.x * f.dist;
                f.d.y = f.d.y * f.dist;
                f.d.z = f.d.z * f.dist;
                f.q = (*(Attach * *)&this->f_20)->offset;
                f.m.pos.x = f.q.x + f.d.x;
                f.m.pos.y = f.q.y + f.d.y;
                f.m.pos.z = f.q.z + f.d.z;
            }
        }
    }
    Fighter_15b20* fighter = f.fighter;
    fighter->FUN_0003acf0((*(Attach * *)&this->f_20)->f14, f.target, joint, f.p20, f.p24, &f.m);
    if (fighter->f20a8 >= 0 && fighter->f328 == (void*)(*(Holder_15b20 * *)&this->f_24))
        fighter->FUN_000393c0();
    Attach* a = (*(Attach * *)&this->f_20);
    const Key* k = &a->key;
    if (k != 0 && (k->lo | k->hi) != 0)
        f.target->thunk_FUN_0027d410(k);
}
