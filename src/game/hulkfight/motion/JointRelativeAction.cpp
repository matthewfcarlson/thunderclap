// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001714b0..0x00171820 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointRelativeAction
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fb2d01ed {
#define TREE_TU_END }
namespace fn_fb2d01ed {} using namespace fn_fb2d01ed;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb2d01ed {
struct Two_1717f0 {
    void* Fnf_00059a40();
};

} // namespace fn_fb2d01ed

// 0x001714b0 hulkfight::motion::JointRelativeAction::vfunc_3 (517 B): equivalent/0x001714b0.cpp [wrapped: conflict: hulkfight::motion::JointRelativeAction]
// sym: ?vfunc_3@JointRelativeAction@motion@hulkfight@fn_001714b0@@UAE_NHH@Z
namespace fn_001714b0 {
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 14/14)
// hulkfight::motion::JointRelativeAction::vfunc_3 @ 0x001714b0
struct Vec3_1714b0 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct Quat_1714b0 {
    float x, y, z, w;
    void FUN_0022b370(const Matrix* m);
    void FUN_0022b220(float x, float y, float z);
};

extern "C" void FUN_0022b080(Quat_1714b0* out, Quat_1714b0* a, Quat_1714b0* b);
void* FUN_00263ea0(unsigned int size);

struct NameField_1714b0 {
    void FUN_0027b040(const char* s);
};

struct Xform_1714b0 {
    char data[0x54];
    void FUN_00221cf0(const Quat_1714b0* q);
    void FUN_0022be40(const Vec3_1714b0* p);
};

class JointDriver {
public:
    virtual void AddRef();
    char pad04[4];
    NameField_1714b0 name;
    char pad0c[4];
    int jointIndex;
    int flags;
    Xform_1714b0 xform;
    JointDriver* FUN_002248a0();
};

struct Anim_1714b0;

struct Anim_1714b0 {
    char pad00[0x14];
    Quat_1714b0* bindQuats;
    Matrix* bindPoses;
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton {
    char pad00[8];
    Anim_1714b0* anim;
    char pad0c[8];
    Matrix* matrices;
};

struct Player_1714b0 {
    char pad00[0x120];
    Skeleton* skeleton;
};

struct Tracker_1714b0 {
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};

struct Clock_1714b0 {
    Player_1714b0* FUN_00059a30();
    Tracker_1714b0* FUN_00059a40();
};

struct Target_1714b0 {
    Clock_1714b0* FUN_000592a0();
};

struct Config_1714b0 {
    char pad00[0x18];
    unsigned int nameLo;
    unsigned int nameHi;
    char useBind;
    char flag21;
    char pad22[2];
    Vec3_1714b0 offset;
    char flag30;
    char pad31[3];
    Vec3_1714b0 scale;
    float limitA;
    float limitB;
    float limitC;
};

namespace hulkfight {
namespace motion {

class JointRelativeAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    virtual void v4();
    virtual void v5();

    char pad04[0x1c - 4];
    Config_1714b0* cfg;
    Target_1714b0* owner;
    JointDriver* driver;
    Quat_1714b0 jointRot;
    Vec3_1714b0 jointPos;
    Quat_1714b0 relRot;
    Vec3_1714b0 relPos;
};

bool JointRelativeAction::vfunc_3(int a, int b)
{
    Clock_1714b0* clock = owner->FUN_000592a0();
    Player_1714b0* player = clock->FUN_00059a30();
    Tracker_1714b0* tracker = clock->FUN_00059a40();
    if (tracker == 0)
        return false;

    Config_1714b0* c = cfg;
    Skeleton* skel = player->skeleton;
    Anim_1714b0* anim = skel->anim;
    int idx = 0;
    if ((c->nameLo | c->nameHi) != 0) {
        idx = anim->FUN_0027b200(c->nameLo, c->nameHi);
        if (idx == 0xffff)
            idx = 0;
    }

    Vec3_1714b0 unused;
    Matrix m = skel->matrices[idx];
    jointRot.FUN_0022b370(&m);
    jointPos.x = m.m[12];
    jointPos.y = m.m[13];
    jointPos.z = m.m[14];

    Vec3_1714b0 s = cfg->scale;
    relRot.FUN_0022b220(s.x, s.y, s.z);
    unused = cfg->offset;
    relPos = unused;

    if (cfg->useBind) {
        FUN_0022b080(&relRot, &relRot, &anim->bindQuats[idx]);
        const Vec3_1714b0* t = (const Vec3_1714b0*)((char*)anim->bindPoses + idx * 64 + 0x30);
        relPos.x = t->x + relPos.x;
        relPos.y = t->y + relPos.y;
        relPos.z = t->z + relPos.z;
    } else {
        FUN_0022b080(&relRot, &relRot, &jointRot);
        relPos.x = jointPos.x + relPos.x;
        relPos.y = jointPos.y + relPos.y;
        relPos.z = jointPos.z + relPos.z;
    }

    void* mem = FUN_00263ea0(0x70);
    JointDriver* d = 0;
    if (mem)
        d = ((JointDriver*)mem)->FUN_002248a0();
    driver = d;
    d->name.FUN_0027b040("jointRelative");
    driver->AddRef();
    driver->jointIndex = idx;
    driver->xform.FUN_00221cf0(&jointRot);
    driver->xform.FUN_0022be40(&jointPos);
    int flags = 0;
    if (cfg->flag21)
        flags = 1;
    if (cfg->flag30)
        flags |= 2;
    driver->flags = flags;
    tracker->FUN_00222890(driver, -1.0f, cfg->limitA, 1.0f, cfg->limitB, cfg->limitC, -1.0f);
    return true;
}

}
}
} // namespace fn_001714b0


// 0x001716c0 hulkfight::motion::JointRelativeAction::vfunc_5 (299 B): equivalent/0x001716c0.cpp [wrapped: conflict: hulkfight::motion::JointRelativeAction]
// sym: ?vfunc_5@JointRelativeAction@motion@hulkfight@fn_001716c0@@UAE_NHM@Z
namespace fn_001716c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::JointRelativeAction::vfunc_5 @ 0x001716c0
struct Quaternion_1716c0 { float x,y,z,w; void FUN_0022b750(const Quaternion_1716c0*, const Quaternion_1716c0*, float); };
struct Vector { float x,y,z; };
struct Transform_1716c0 { void FUN_00221cf0(const Quaternion_1716c0*); void FUN_0022be40(const Vector*); };
struct Joint_1716c0 { char pad[0x18]; Transform_1716c0 transform; };
struct Actor_1716c0 { Actor_1716c0* FUN_000592a0(); void FUN_00059a30(); int FUN_00059a40(); };
struct Duration { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); };
namespace hulkfight { namespace motion {
struct JointRelativeAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, float);
 char pad[0x18]; Duration* duration; Actor_1716c0* actor; Joint_1716c0* joint; Quaternion_1716c0 startRotation; Vector startPosition; Quaternion_1716c0 endRotation; Vector endPosition; float elapsed;
};
bool JointRelativeAction::vfunc_5(int mode, float delta) {
 if (mode != 0) return true;
 Actor_1716c0* a = actor->FUN_000592a0();
 a->FUN_00059a30();
 if (!a->FUN_00059a40()) return false;
 elapsed += delta;
 float total = duration->slot7();
 float fraction;
 if (!(total <= 0.0f) && !(elapsed > total)) fraction = elapsed / total;
 else fraction = 1.0f;
 Quaternion_1716c0 rotation = startRotation;
 rotation.FUN_0022b750(&rotation, &endRotation, fraction);
 joint->transform.FUN_00221cf0(&rotation);
 Vector position = startPosition;
 position.x = (endPosition.x - position.x) * fraction + position.x;
 position.y = (endPosition.y - position.y) * fraction + position.y;
 position.z = (endPosition.z - position.z) * fraction + position.z;
 joint->transform.FUN_0022be40(&position);
 return true;
}
}}
} // namespace fn_001716c0


// 0x001717f0 hulkfight::motion::JointRelativeAction::vfunc_4 (37 B): matches/0x001717f0.cpp
// sym: ?vfunc_4@JointRelativeAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::JointRelativeAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_1717f0*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}

