// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001fab0..0x0001fc60 (kind game, layer game, confidence medium), dominant class COrientAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f1d726b8 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1d726b8 {} using namespace fn_f1d726b8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f1d726b8 {
struct Vec3_1fab0 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_1fab0 *other, float epsilon);
};
struct Transform_1fab0 {
    void FUN_00221d20(float v);
};
struct JointObject_1fab0 {
    char pad0[0x18];
    Transform_1fab0 transform;
};
struct Stats_1fab0 {
    char pad0[0x2064];
    Vec3_1fab0 dirB;
    char pad2070[4];
    Vec3_1fab0 dirA;
    hulk_freg FUN_000354c0();
    void FUN_00035550(Vec3_1fab0 *out);
};
struct OrientData {
    char pad0[0x14];
    float turnRate;
    float offset;
    unsigned char noDirA;
};
void *__fastcall FUN_000592a0(void *owner);
Stats_1fab0 *__fastcall FUN_00059a30(void *x);
extern "C" hulk_freg FUN_00224f10(Vec3_1fab0 *v);
extern "C" hulk_freg FUN_00224fc0(float from, float to);
class COrientAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(float dt);
    virtual void vfunc_8();
    char pad04[0x18];
    void *owner;
    OrientData *data;
    JointObject_1fab0 *joint;
};


// 0x0001fab0 COrientAction::vfunc_7 (428 B): equivalent/0x0001fab0.cpp
// sym: ?vfunc_7@COrientAction@fn_f1d726b8@@UAEDM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 14/14)
// COrientAction::vfunc_7 @ 0x0001fab0
char COrientAction::vfunc_7(float dt)
{
    if (joint == 0)
        return 0;

    Stats_1fab0 *stats = FUN_00059a30(FUN_000592a0(owner));
    float stored = stats->FUN_000354c0();   // the original stores the heading to its frame (fstp) first; a plain
    hulk_freg angle = stored;               // (float) cast would be undone by clang_probe's retfix (fpext of the call)

    Vec3_1fab0 dir;
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 0.0f;
    if (!data->noDirA)
        dir = stats->dirA;

    Vec3_1fab0 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (dir.FUN_0022d2b0(&zero, 1e-5f)) {
        dir = stats->dirB;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        if (dir.FUN_0022d2b0(&zero, 1e-5f))
            stats->FUN_00035550(&dir);
    }

    hulk_freg heading = FUN_00224f10(&dir);
    hulk_freg target = heading + data->offset;
    hulk_freg rate = data->turnRate;
    if (!(rate < 0.0f)) {
        hulk_freg diff = FUN_00224fc0(angle, target);
        float step = rate * dt;
        union {
            float f;
            unsigned int u;
        } a;
        a.f = diff;
        a.u &= 0x7fffffff;
        if (a.f <= step) {
            angle = target;
        } else if (!(diff < 0.0f)) {
            angle = step + angle;
        } else {
            angle = angle - step;
        }
    } else {
        angle = target;
    }

    joint->transform.FUN_00221d20(angle);
    return 1;
}

} // namespace fn_f1d726b8
