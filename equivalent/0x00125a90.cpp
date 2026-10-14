// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 25/26, incomplete)
// hulkfight::ai::TargetArcCondition::vfunc_6 @ 0x00125a90
struct V3_125a90 {
    float x, y, z;
    float FUN_0022d110();
};

struct M4_125a90 {
    float m[16];
    void FUN_0022c3b0(V3_125a90* in, V3_125a90* out);
};

struct Entity {
    char pad00[0x40];
    V3_125a90 pos;                     // 0x40
};

struct Mount_125a90 {
    void FUN_00059a50(V3_125a90* out);
};

struct Finder_125a90 {
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton {
    char pad00[8];
    Finder_125a90* finder;             // 0x08
    char pad0c[0x1c - 0xc];
    M4_125a90* matrices;               // 0x1c
};

struct Fighter_125a90 {
    char pad00[0x12c];
    Entity* lock;               // 0x12c
};

struct Stats_125a90 {
    char pad00[0x10];
    Mount_125a90* mount;               // 0x10
    char pad14[0x120 - 0x14];
    Skeleton* skeleton;         // 0x120
    char pad124[0x328 - 0x124];
    Entity* target;             // 0x328
    char pad32c[0x330 - 0x32c];
    Fighter_125a90* fighter;           // 0x330
    char pad334[4];
    int f338;                   // 0x338
    float FUN_000354c0();
};

struct Handle_125a90 {
    Stats_125a90* FUN_00059a30();
};

struct Owner_125a90 {
    char pad00[0x124];
    Fighter_125a90* current;           // 0x124
};

struct Globals_125a90 {
    char pad00[0x20];
    Owner_125a90* owner;               // 0x20
};

struct Singleton_125a90 {
    V3_125a90* FUN_001c39c0();
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle_125a90* FUN_000592a0();
};

extern Globals_125a90* DAT_004dd700;
Singleton_125a90* FUN_001c3d90();
float FUN_00224f10(V3_125a90* v);
float FUN_00224fc0(float a, float b);
float FUN_00018a20(float v);

namespace hulkfight {
namespace ai {
class TargetArcCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a1, fight::Params* params, int a3);

    char pad04[8];
    float f0c;
    float f10;                  // 0x10: half-arc
    char b14;                   // 0x14
    char pad15[3];
    unsigned int idLo;          // 0x18
    unsigned int idHi;          // 0x1c
    V3_125a90 offset;                  // 0x20
    char b2c;                   // 0x2c
};

bool TargetArcCondition::vfunc_6(int a1, fight::Params* params, int a3)
{
    if (!dynamic_cast<CFightParams*>(params))
        return false;

    Stats_125a90* stats = ((CFightParams*)params)->FUN_000592a0()->FUN_00059a30();
    V3_125a90 dir;
    if (b14) {
        dir = *FUN_001c3d90()->FUN_001c39c0();
    } else {
        Fighter_125a90* holder;
        Entity* e;
        bool viaHolder;
        if (b2c) {
            holder = DAT_004dd700->owner->current;
            viaHolder = holder != 0;
        } else {
            holder = stats->fighter;
            viaHolder = holder != 0 && stats->f338 == 0;
        }
        e = 0;
        if (viaHolder)
            e = holder->lock;
        if (!e) {
            e = stats->target;
            if (!e)
                return false;
        }
        V3_125a90 pos;
        pos.x = 0.0f;
        pos.y = 0.0f;
        pos.z = 0.0f;
        stats->mount->FUN_00059a50(&pos);
        V3_125a90 t = e->pos;
        dir.x = t.x - pos.x;
        dir.y = t.y - pos.y;
        dir.z = t.z - pos.z;
    }

    float angle = FUN_00224f10(&dir);
    float diff;
    if ((idLo | idHi) == 0) {
        diff = FUN_00224fc0(stats->FUN_000354c0() + f0c, angle);
    } else {
        Skeleton* skel = stats->skeleton;
        int idx = 0;
        if (skel) {
            idx = skel->finder->FUN_0027b200(idLo, idHi);
            if (idx == 0xffff)
                idx = 0;
        }
        V3_125a90 d2;
        d2.x = 0.0f;
        d2.y = 0.0f;
        d2.z = -1.0f;
        if (skel) {
            M4_125a90 mx = skel->matrices[idx];
            V3_125a90 tv = offset;
            mx.FUN_0022c3b0(&tv, &d2);
            d2.FUN_0022d110();
        }
        dir.FUN_0022d110();
        diff = FUN_00018a20(d2.z * dir.z + d2.y * dir.y + d2.x * dir.x);
    }

    union { float f; unsigned int u; } ad;
    ad.f = diff;
    ad.u &= 0x7fffffff;
    return f10 * 0.5f > ad.f;
}
}
}
