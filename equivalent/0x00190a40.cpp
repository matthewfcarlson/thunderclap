// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 20/20)
// hulkfight::motion::ImpulseVelocityAction::vfunc_5 @ 0x00190a40
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct V3_190a40 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_190a40 *other, float eps);
};

struct Mat_190a40 {
    float m[16];
    void FUN_0022c2b0(const V3_190a40 *in, V3_190a40 *out);
    void FUN_0022c3b0(const V3_190a40 *in, V3_190a40 *out);
};

float __cdecl FUN_000186b0(float *v, float *lo, float *hi);

struct Prop_190a40 {
    char pad0[0x1e58];
    float scale;
};

struct Table_190a40 {
    char pad0[0x10];
    unsigned int count;
    char pad14[0x10];
    unsigned int *ids;
    unsigned int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton_190a40 {
    char pad0[8];
    Table_190a40 *table;
    char pad0c[0x10];
    Mat_190a40 *mats;
};

struct Holder_190a40 {
    char pad0[0x120];
    Skeleton_190a40 *skel;
    char pad124[0x210];
    Prop_190a40 *propB;    // 0x334
    Prop_190a40 *propA;    // 0x338
    void FUN_00038410(V3_190a40 *a, V3_190a40 *b);
};

struct Source_190a40 {
    char pad0[8];
    V3_190a40 posA;
    char pad14[0x14];
    V3_190a40 velB;
    char pad34[0xc];
};

struct Params_190a40 {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
    V3_190a40 anchor;      // 0x18
    V3_190a40 start;       // 0x24
    V3_190a40 end;         // 0x30
    char pad3c;
    char pad3d[3];
    float factor;   // 0x40
};

struct Handle_190a40 {
    Holder_190a40 *FUN_00059a30();
};

struct Owner_190a40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Source_190a40 *GetSource();
    Handle_190a40 *FUN_000592a0();
};

struct ArgBlock {
    char pad0[0x28];
    V3_190a40 vel;
};

bool hulkfight::motion::ImpulseVelocityAction::vfunc_5(hulk_intptr a, int b) {
    if (a != 0)
        return true;
    Holder_190a40 *holder = (*(Owner_190a40 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
    Skeleton_190a40 *skel = holder->skel;
    if (skel == 0)
        return false;
    unsigned int idx = 0;
    if (((*(Params_190a40 * *)&this->f_1c)->idLo | (*(Params_190a40 * *)&this->f_1c)->idHi) != 0) {
        idx = skel->table->FUN_0027b200((*(Params_190a40 * *)&this->f_1c)->idLo, (*(Params_190a40 * *)&this->f_1c)->idHi);
        if (idx == 0xffff)
            idx = 0;
    }
    Mat_190a40 m = skel->mats[idx];
    V3_190a40 zero;
    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    V3_190a40 t1 = (*(Params_190a40 * *)&this->f_1c)->anchor;
    m.FUN_0022c2b0(&t1, &zero);
    V3_190a40 p = (*(Params_190a40 * *)&this->f_1c)->start;
    t1 = (*(Params_190a40 * *)&this->f_1c)->end;
    if (t1.z * t1.z + t1.y * t1.y + t1.x * t1.x > 0.0f) {
        float scale = 0;
        if (holder->propA != 0) {
            scale = holder->propA->scale;
        } else if (holder->propB != 0) {
            scale = holder->propB->scale;
        }
        t1.x = t1.x - p.x;
        t1.y = t1.y - p.y;
        float one = 1.0f;
        float lo = 0;
        t1.z = t1.z - p.z;
        float c = FUN_000186b0(&scale, &lo, &one);
        float dx = t1.x * c;
        t1.y = t1.y * c;
        t1.z = t1.z * c;
        p.x = p.x + dx;
        p.y = p.y + t1.y;
        p.z = p.z + t1.z;
    }
    V3_190a40 w;
    w.x = 0;
    w.y = 0;
    w.z = 0;
    m.FUN_0022c3b0(&p, &w);
    bool doSet = (*(Params_190a40 * *)&this->f_1c)->pad3c != 0;
    if (!doSet) {
        t1.x = 0;
        t1.y = 0;
        t1.z = 0;
        doSet = w.FUN_0022d2b0(&t1, 0.00001f);
    }
    if (doSet) {
        Source_190a40 *src = (*(Owner_190a40 * *)&this->f_20)->GetSource();
        if (src != 0) {
            zero = src->posA;
            w = ((ArgBlock *)src)->vel;
            float k = (*(Params_190a40 * *)&this->f_1c)->factor;
            w.x = w.x * k;
            w.y = w.y * k;
            w.z = w.z * k;
        }
    }
    holder->FUN_00038410(&zero, &w);
    return false;
}
