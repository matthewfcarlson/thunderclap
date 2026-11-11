// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00020de0..0x000213b0 (kind game, layer game, confidence medium), dominant class CWallSlideAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f1852733 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1852733 {} using namespace fn_f1852733;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f1852733 {
struct Vec3_20de0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const Vec3_20de0 *other, float eps);
};
struct Transform_20de0 {
    void FUN_00222180(const Vec3_20de0 *dir);
};
struct ResourceName_20de0 {
    char data[12];
    void FUN_0027b040(const char *name);
};
class JointDriver_20de0 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_20de0 name;
    char pad14[0x18 - 0x14];
    Transform_20de0 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_20de0)];
    JointDriver_20de0 *FUN_002248f0(unsigned int id);
};
struct Scene_20de0 {
    void FUN_00222890(JointDriver_20de0 *obj, float a, int b, float c, float d, float e, float f);
};
struct Tracker_20de0 {
    char pad[0x1ae0];
    Vec3_20de0 alt;
    char pad2[0x1af8 - 0x1aec];
    Vec3_20de0 main;
    bool FUN_000356c0(Vec3_20de0 *out);
};
struct Fighter_20de0 {
    Tracker_20de0 *FUN_00059a30();
    Scene_20de0 *FUN_00059a40();
};
struct Owner_20de0 {
    Fighter_20de0 *FUN_000592a0();
};
class Shape_20de0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    char pad04[0x14 - 4];
    float f14;
    char pad18[0x24 - 0x18];
    int f24;
    float f28;
    float f2c;
};
void *__cdecl FUN_00263ea0(unsigned int size);
class CWallSlideAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x1c - 4 - 0x0];
    Owner_20de0 *owner;
    Shape_20de0 *shape;
    JointDriver_20de0 *joint;
    float k;
    Vec3_20de0 slide;
};
struct Frame_20de0 {
    float r;
    float g28;
    Vec3_20de0 V;
    Vec3_20de0 W;
    Vec3_20de0 T;
};


// 0x00020de0 CWallSlideAction::vfunc_6 (649 B): equivalent/0x00020de0.cpp
// sym: ?vfunc_6@CWallSlideAction@fn_f1852733@@UAE_NH@Z
// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 16/16)
// CWallSlideAction::vfunc_6 @ 0x00020de0
bool CWallSlideAction::vfunc_6(int arg)
{
    Fighter_20de0 *fighter = owner->FUN_000592a0();
    Tracker_20de0 *trk = fighter->FUN_00059a30();
    Scene_20de0 *scene = fighter->FUN_00059a40();
    if (scene == 0)
        return false;

    Frame_20de0 fr;
    fr.V = trk->main;
    fr.W.x = 0.0f;
    fr.W.y = 0.0f;
    fr.W.z = 0.0f;
    if (fr.V.FUN_0022d2b0(&fr.W, 1e-05f)) {
        fr.V = trk->alt;
        fr.W.x = 0.0f;
        fr.W.y = 0.0f;
        fr.W.z = 0.0f;
        if (fr.V.FUN_0022d2b0(&fr.W, 1e-05f))
            return false;
    }

    slide.z = 0.0f;
    slide.y = 0.0f;
    slide.x = 0.0f;
    if (!trk->FUN_000356c0(&slide))
        return false;

    if ((fr.V.z * slide.z + fr.V.y * slide.y + fr.V.x * slide.x) < 0.0f) {
        double n = -(fr.V.z * slide.z + fr.V.y * slide.y + fr.V.x * slide.x);
        float tx = fr.V.x;
        float ty = fr.V.y;
        float tz = fr.V.z;
        double px = tx * n;
        volatile float py = (float)(ty * n);
        volatile float pz = (float)(tz * n);
        slide.x = (float)(px + slide.x);
        slide.y = py + slide.y;
        slide.z = pz + slide.z;
    }

    k = shape->f14;
    fr.r = shape->vfunc_7();
    if (fr.r > 0.0f) {
        double len = sqrt((double)(slide.x * slide.x + slide.y * slide.y + slide.z * slide.z));
        if (len > fr.r * k)
            k = (float)(len / fr.r);
    }

    Shape_20de0 *sh = shape;
    float g28 = sh->f28;
    float g2c = sh->f2c;
    int g24 = sh->f24;
    void *mem = FUN_00263ea0(0x70);
    JointDriver_20de0 *obj = 0;
    if (mem)
        obj = ((JointDriver_20de0 *)mem)->FUN_002248f0(0);
    joint = obj;
    obj->name.FUN_0027b040("wallSlide");
    joint->vfunc_0();

    fr.T.x = fr.V.x * -1.0f;
    fr.T.y = 0.0f * -1.0f;
    fr.T.z = fr.V.z * -1.0f;
    fr.T.FUN_0022d110();
    joint->transform.FUN_00222180(&fr.T);

    scene->FUN_00222890(joint, -1.0f, g24, 1.0f, g28, g2c, -1.0f);
    return true;
}

} // namespace fn_f1852733

// 0x00021070 CWallSlideAction::vfunc_7 (830 B): equivalent/0x00021070.cpp [wrapped: conflict: CWallSlideAction]
// sym: ?vfunc_7@CWallSlideAction@fn_00021070@@UAEDM@Z
namespace fn_00021070 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CWallSlideAction::vfunc_7 @ 0x00021070

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_21070 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Xform_21070 {
    void FUN_0022be40(Vec3_21070* pos);
};

struct Entity {
    char pad00[0x2064];
    Vec3_21070 f2064;
    float f2070;
    void FUN_000359c0(int mode);
    void FUN_00035660(Vec3_21070* out);
};

struct Anchor_21070 {
    void FUN_00059a50(Vec3_21070* out);
};

struct Params {
    char pad00[0x18];
    float f18;
    float f1c;
    float f20;
};

struct Data2 {
    char pad00[0x18];
    Xform_21070 xf;
};

void* __fastcall FUN_000592a0(void* owner);
extern "C" Entity* __fastcall FUN_00059a30(void* anchor);

class CWallSlideAction {
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
    void* owner;
    Params* params;
    Data2* data;
    float f28;
    Vec3_21070 vel;
};

char CWallSlideAction::vfunc_7(float dt)
{
    struct Frame {
        float step;
        float len;
        float lim;
        Vec3_21070 W;
        Vec3_21070 Z;
        Vec3_21070 v;
        Vec3_21070 U;
        Vec3_21070 O;
        Vec3_21070 P;
    } f;
    if (data == 0)
        return 0;
    Anchor_21070* anchor = (Anchor_21070*)FUN_000592a0(owner);
    Entity* ent = FUN_00059a30(anchor);
    ent->FUN_000359c0(4);
    vel.y = vel.y - dt * params->f18;
    f.v = vel;
    f.len = f.v.FUN_0022d110();
    double stepx = dt * f28;
    f.step = (float)stepx;
    f.W = vel;
    f.lim = params->f20;
    f.U = f.v;
    if (stepx > f.len) {
        vel.x = 0.0f;
        vel.y = 0.0f;
        vel.z = 0.0f;
    } else {
        double X;
        {
            volatile float c = f.U.z * f.step;
            f.W.x = f.W.x - f.U.x * f.step;
            f.W.y = f.W.y - f.U.y * f.step;
            f.U = ent->f2064;
            f.W.z = f.W.z - c;
        }
        f.U.FUN_0022d110();
        double d = f.v.z * f.U.z + f.v.y * f.U.y + f.v.x * f.U.x;
        if (d < -0.5f) {
            double t = 0.5f - (d + 1.0f);
            t = t + t;
            X = t * ent->f2070 * params->f1c * dt;
        } else {
            X = 0.0f;
        }
        if (f.step + X > f.len) {
            vel.x = 0.0f;
            vel.y = 0.0f;
            vel.z = 0.0f;
        } else {
            f.U.x = f.v.x * X;
            f.U.y = f.v.y * X;
            f.U.z = f.v.z * X;
            f.W.y = f.W.y - f.U.y;
            f.W.z = f.W.z - f.U.z;
            vel.x = f.W.x - f.U.x;
            vel.y = f.W.y;
            vel.z = f.W.z;
        }
    }
    f.Z.x = vel.x * dt;
    f.Z.y = vel.y * dt;
    f.Z.z = vel.z * dt;
    f.O.x = 0.0f;
    f.O.y = 0.0f;
    f.O.z = 0.0f;
    anchor->FUN_00059a50(&f.O);
    f.Z.x = f.O.x + f.Z.x;
    f.Z.y = f.O.y + f.Z.y;
    f.Z.z = f.O.z + f.Z.z;
    data->xf.FUN_0022be40(&f.Z);
    dt = (float)sqrt(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
    ent->FUN_00035660(&f.P);
    float pl = (float)sqrt(f.P.z * f.P.z + f.P.y * f.P.y + f.P.x * f.P.x);
    if (pl < dt)
        dt = pl;
    if (f.lim < 0.0f)
        return 1;
    return dt > f.lim;
}
} // namespace fn_00021070

