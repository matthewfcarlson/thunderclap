// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000139b0..0x00013b70 (kind game, layer game, confidence medium), dominant class CJointAction
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_faa3d017 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faa3d017 {} using namespace fn_faa3d017;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faa3d017 {
struct Pair { int first; int second; };
struct Worker { int FUN_0027b670(int, int); };
struct Mid { char pad[8]; Worker *worker; };
struct Obj { char pad[0x120]; Mid *mid; };
struct Context { struct Obj2 *FUN_000592a0(); };
struct Obj2 { Obj *FUN_00059a30(); };
struct Receiver { void FUN_002224a0(int); };
struct Vec3_13a00 {
    float x, y, z;
};
struct Quat_13a00 {
    float x, y, z, w;
    void FUN_0022b220(float rx, float ry, float rz);
};
struct Transform_13a00 {
    void FUN_0022be40(const Vec3_13a00 *pos);
    void FUN_00221cf0(const Quat_13a00 *rot);
};
struct ResourceName_13a00 {
    char data[12];
    void FUN_0027b040(const char *name);
};
class JointDriver_13a00 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_13a00 name;
    unsigned int flags;
    Transform_13a00 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_13a00)];
    JointDriver_13a00 *FUN_002248f0(unsigned int id);
};
struct JointFinder_13a00 {
    unsigned int FUN_0027b200(int a, int b);
};
struct Scene_13a00 {
    JointFinder_13a00 *FUN_002226b0();
    void FUN_00222890(JointDriver_13a00 *obj, float a, float b, float c, float d, float e, float f);
};
struct JointData_13a00 {
    char pad0[0x18];
    int jointA;
    int jointB;
    unsigned char flag20;
    char pad21[3];
    Vec3_13a00 offset;
    unsigned char flag30;
    char pad31[3];
    Vec3_13a00 euler;
    float extentX;
    float extentY;
    float extentZ;
};
void *__fastcall FUN_000592a0(void *owner);
Scene_13a00 *__fastcall FUN_00059a40(void *x);
void *__cdecl FUN_00263ea0(unsigned int size);
class CJointAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void *owner;
    JointData_13a00 *data;
    JointDriver_13a00 *joint;
};


// 0x000139b0 FUN_000139b0 (66 B): equivalent/0x000139b0.cpp
// sym: _FUN_000139b0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000139b0 @ 0x000139b0
extern "C" void __cdecl FUN_000139b0(Pair *p, Context *context, Receiver *receiver) { int a=p->first; int b=p->second; if(a || b) { Obj2 *intermediate=context->FUN_000592a0(); Obj *obj=intermediate->FUN_00059a30(); int result=obj->mid->worker->FUN_0027b670(a,b); if(result) receiver->FUN_002224a0(result); } }


// 0x00013a00 CJointAction::vfunc_6 (305 B): equivalent/0x00013a00.cpp
// sym: ?vfunc_6@CJointAction@fn_faa3d017@@UAEDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19948 inputs, branch coverage 10/10)
// CJointAction::vfunc_6 @ 0x00013a00
char CJointAction::vfunc_6(int arg)
{
    Vec3_13a00 pos;
    Quat_13a00 rot;

    Scene_13a00 *scene = FUN_00059a40(FUN_000592a0(owner));
    if (scene == 0)
        return 0;

    int arg1_ = data->jointB;
    int arg2_ = data->jointA;
    unsigned int id = scene->FUN_002226b0()->FUN_0027b200(arg2_, arg1_);
    if (id == 0xffff)
        return 0;

    void *mem = FUN_00263ea0(0x70);
    JointDriver_13a00 *obj = 0;
    if (mem)
        obj = ((JointDriver_13a00 *)mem)->FUN_002248f0(id);
    joint = obj;

    obj->name.FUN_0027b040("joint");
    joint->vfunc_0();

    unsigned int f = 0;
    if (data->flag20)
        f = 1;
    if (data->flag30)
        f |= 2;
    joint->flags = f;

    pos = data->offset;
    joint->transform.FUN_0022be40(&pos);

    rot.FUN_0022b220(data->euler.x, data->euler.y, data->euler.z);
    joint->transform.FUN_00221cf0(&rot);

    scene->FUN_00222890(joint, -1.0f, data->extentX, 1.0f, data->extentY, data->extentZ, -1.0f);
    return 1;
}

} // namespace fn_faa3d017
