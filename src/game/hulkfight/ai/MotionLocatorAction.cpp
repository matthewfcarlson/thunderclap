// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// clang-flags: -fexceptions -fcxx-exceptions   (gx2, D22: kept until its --wine proof passes again; docs/native-build.md "gx2")
// object 0x00117350..0x001178e0 (kind game, layer game, confidence medium), dominant class hulkfight::ai::MotionLocatorAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdfac53b {
#define TREE_TU_END }
namespace fn_fdfac53b {} using namespace fn_fdfac53b;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fdfac53b {
extern "C" char DAT_0040ed2c[];
struct Ref_117350 {
    virtual void Add();
    virtual void Release();
};
struct ThisCall_00232660 {
    void Init_00232660();
};
extern void* hulk_at_0040ed2c[];
class Ref_1173b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1173b0 {
  public:
    void* vptr;
};
class MotionLocatorAction_1173b0 : public Action_1173b0 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_1173b0* m20;
    ~MotionLocatorAction_1173b0();
};
struct R_1173f0 {
    char p[0x18];
    float lo, hi, lo2, hi2;
};
struct MotionLocatorAction_1173f0 {
    char p[0x1c];
    R_1173f0* r;
    char p20[4];
    float m24, m28, m2c;
    bool f();
};
struct V3_117480 {
    float x, y, z;
    float FUN_0022d110();
};
class Target_117480 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void getPosition(V3_117480 *out);
};
struct Registry_117480 {
    Target_117480 *FUN_001fc8c0(unsigned __int64 id);
};
} // namespace fn_fdfac53b
struct World {
    char pad[0x28];
    Registry_117480 *registry;
};
namespace fn_fdfac53b {
struct Strings_117480 {
    const char *FUN_001d3030(const char *name, const char *tag);
};
Strings_117480 *FUN_001d4c90();
struct Info_117480 {
    char pad0[0x14];
    float f14;
    float rangeMin;
    float rangeMax;
    float f20;
    float f24;
    char flag28;
    char flag29;
    char flag2a;
    char flag2b;
    unsigned __int64 id2c;
};
struct Anchor_117480 {
    char pad0[0xa0];
    unsigned __int64 id;
};
struct Pos_117480 {
    void FUN_00059a50(V3_117480 *out);
};
struct Owner_117480;
struct Inner_117480 {
    Owner_117480 *FUN_00059a30();
};
struct Owner_117480 {
    char pad0[0x10];
    Pos_117480 *pos;
    char pad14[0x1ca0 - 0x14];
    Anchor_117480 *anchor;
    char pad1ca4[0x1d70 - 0x1ca4];
    unsigned __int64 id1d70;
    char pad1d78[0x2064 - 0x1d78];
    V3_117480 dir;
    float strength;
    const char *FUN_00036d00();
};
struct Source_117480 {
    Inner_117480 *FUN_000592a0();
};
union Arg1_117480 {
    int v;
    float len;
};
class MotionLocatorAction {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual char v5(Arg1_117480 a1, int a2);
    char _m_pad_4[0x18];
    union { Info_117480 *info; volatile unsigned int mArg; };
    union { Ref_117350* mOld; Source_117480 *source; };
    union { float f24; unsigned int mZero; };
    union { float distance; unsigned int mMin1; };
    union { float height; unsigned int mMin2; };
    MotionLocatorAction* Build(unsigned int a, Ref_117350* r);
    char FUN_001173f0();
};


// 0x00117350 FUN_00117350 (90 B): matches/0x00117350.cpp
// sym: ?Build@MotionLocatorAction@fn_fdfac53b@@QAEPAV12@IPAURef_117350@2@@Z
MotionLocatorAction* MotionLocatorAction::Build(unsigned int a, Ref_117350* r) {
    ((ThisCall_00232660*)(this))->Init_00232660();
    mMin1 = 0x7f7fffff;
    mMin2 = 0x7f7fffff;
    *(volatile hulk_uintptr*)this = ((hulk_intptr)DAT_0040ed2c);
    mArg = 0;
    mOld = 0;
    mZero = 0;
    mArg = a;
    if (r)
        r->Add();
    if (mOld)
        mOld->Release();
    mOld = r;
    return this;
}


// 0x001173b0 FUN_001173b0 (50 B): matches/0x001173b0.cpp
// sym: ??1MotionLocatorAction_1173b0@fn_fdfac53b@@QAE@XZ
MotionLocatorAction_1173b0::~MotionLocatorAction_1173b0() {
    vptr = hulk_at_0040ed2c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1173b0 *)this)->FUN_002326a0();
}


// 0x001173f0 FUN_001173f0 (132 B): matches/0x001173f0.cpp
// sym: ?f@MotionLocatorAction_1173f0@fn_fdfac53b@@QAE_NXZ
bool MotionLocatorAction_1173f0::f() {
    bool a = m28 <= r->hi && m28 >= r->lo;
    bool b = m2c <= r->hi2 && m2c >= r->lo2;
    union {
        float f;
        unsigned i;
    } u;
    u.f = m24;
    u.i &= 0x7fffffff;
    bool c = u.f <= 1e-05f;
    return a && b && c;
}


// 0x00117480 hulkfight::ai::MotionLocatorAction::vfunc_5 (1108 B): equivalent/0x00117480.cpp
// sym: ?v5@MotionLocatorAction@fn_fdfac53b@@UAEDTArg1_117480@2@H@Z @b0ff6c415211 @wad437a8dc280
// STATUS: equivalent (tools/equiv.py level 3: 3085 inputs, branch coverage 54/61, incomplete)
// hulkfight::ai::MotionLocatorAction::vfunc_5 @ 0x00117480
char MotionLocatorAction::v5(Arg1_117480 a1, int a2)
{
    if (a1.v)
        return 1;
    if (!source)
        return 0;
    Inner_117480 *inner = source->FUN_000592a0();
    Owner_117480 *owner = inner->FUN_00059a30();
    if (!owner || !inner)
        return 0;
    unsigned __int64 id;
    Info_117480 *inf = info;
    if (inf->flag2b) {
        id = inf->id2c;
    } else if (inf->flag2a && owner->anchor) {
        id = owner->anchor->id;
    } else if (inf->flag29) {
        id = owner->id1d70;
    } else if (inf->flag28) {
        id = FUN_002672f0(FUN_001d4c90()->FUN_001d3030(owner->FUN_00036d00(), "locator"), 0, 0);
        if (id == 0) {
            id = owner->id1d70;
            if (id == 0)
                return 0;
        }
    } else {
        return 0;
    }
    Target_117480 *target = DAT_004dd700->registry->FUN_001fc8c0(id);
    if (!target)
        return 0;
    V3_117480 pos;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    V3_117480 tp;
    target->getPosition(&tp);
    owner->pos->FUN_00059a50(&pos);
    V3_117480 d;
    d.x = tp.x - pos.x;
    d.y = 0;
    float dy = tp.y - pos.y;
    d.z = tp.z - pos.z;
    float ny = -dy;
    a1.len = d.FUN_0022d110();
    distance = a1.len;
    height = ny;
    V3_117480 out;
    out.x = 0;
    out.y = 0;
    out.z = 0;
    inf = info;
    float rangeMin = inf->rangeMin;
    float rangeMax = inf->rangeMax;
    float s = 0.0f;
    if (a1.len < rangeMin) {
        out.x = d.x * -1.0f;
        out.y = d.y * -1.0f;
        out.z = d.z * -1.0f;
        s = inf->f14;
    } else if (a1.len > rangeMax) {
        out.x = d.x;
        out.y = d.y;
        out.z = d.z;
        s = inf->f14;
    }
    float f24v = inf->f24;
    if (ny < inf->f20) {
        if (a1.len >= rangeMin && a1.len <= rangeMax) {
            out.y = 1.0f;
            out.FUN_0022d110();
            s = info->f14;
        } else if (a1.len < rangeMin && rangeMin > 0.0f) {
            out.y = 1.0f - (rangeMin - a1.len) / rangeMin;
            out.FUN_0022d110();
            s = info->f14;
        } else {
            float twice = rangeMax + rangeMax;
            if (a1.len > rangeMax && a1.len < twice && rangeMax > 0.0f) {
                out.y = (twice - a1.len) / twice;
                out.FUN_0022d110();
                s = info->f14;
            } else {
                out.y = 0.0f;
            }
        }
    } else if (ny > f24v) {
        if (a1.len >= rangeMin && a1.len <= rangeMax) {
            out.y = -1.0f;
            out.FUN_0022d110();
            s = info->f14;
        } else if (a1.len < rangeMin && rangeMin > 0.0f) {
            out.y = (rangeMin - a1.len) / rangeMin - 1.0f;
            out.FUN_0022d110();
            s = info->f14;
        } else {
            float twice = rangeMax + rangeMax;
            if (a1.len > rangeMax && a1.len < twice && rangeMax > 0.0f) {
                out.y = -((twice - a1.len) / twice);
                out.FUN_0022d110();
                s = info->f14;
            } else {
                out.y = 0.0f;
            }
        }
    }
    owner->dir = out;
    owner->strength = s;
    f24 = s;
    return FUN_001173f0() == 0;
}

} // namespace fn_fdfac53b
