// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00013b70..0x00013d70 (kind game, layer game, confidence medium), dominant class CJumpAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcbb3961 {
#define TREE_TU_END }
namespace fn_fcbb3961 {} using namespace fn_fcbb3961;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fcbb3961 {
class CAction_13b70 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual bool vfunc_7(int);
    virtual void a8();
};
struct X_13b70 {
    X_13b70* f2_00059a30();
    int f3_000359c0(int);
};

} // namespace fn_fcbb3961

// 0x00013b70 CClimbingAction::vfunc_7 (29 B): matches/0x00013b70.cpp
// sym: ?vfunc_7@CClimbingAction@@UAE_NH@Z
bool CClimbingAction::vfunc_7(int ) {
    X_13b70* x = (X_13b70*)(*(void * *)&this->f_1c);
    x = ((X_13b70 *)((owners::Object_592a0 *)x)->FUN_000592a0());
    x = x->f2_00059a30();
    x->f3_000359c0(4);
    return true;
}


// 0x00013b90 CJumpAction::vfunc_6 (422 B): equivalent/0x00013b90.cpp [wrapped: conflict: CJumpAction]
// sym: ?vfunc_6@CJumpAction@fn_00013b90@@UAEDH@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00013b90 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 11/12, incomplete)
// CJumpAction::vfunc_6 @ 0x00013b90
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_13b90 {
    float x, y, z;
};

struct Pose {
    char data[1];
};

struct Transform_13b90 {
    void FUN_00221be0(const Pose *pose);
    void FUN_00221d20(float v);
};

struct ResourceName_13b90 {
    char data[12];
    void FUN_0027b040(const char *name);
};

class JointDriver_13b90 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_13b90 name;
    unsigned int flags;
    Transform_13b90 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_13b90)];
    JointDriver_13b90 *FUN_002248f0(unsigned int id);
};

struct Scene_13b90 {
    char pad0[0x10];
    Pose pose;
    void FUN_00222890(JointDriver_13b90 *obj, float a, int b, float c, float d, float e, float f);
};

struct Mount_13b90 {
    void FUN_00059a50(Vec3_13b90 *out);
};

struct Stats_13b90 {
    char pad0[0x10];
    Mount_13b90 *mount;
    char pad14[0x2064 - 0x14];
    Vec3_13b90 charge;
    float chargeTime;
    float FUN_0003ec00(int arg);
    void FUN_000354e0(float v);
};

struct Controller_13b90 {
    void FUN_001ec980(Stats_13b90 *stats, const char *name);
};

struct Manager_13b90 {
    void FUN_00099d20(struct World *g, Stats_13b90 *s, float a, float b, float c);
};

struct World {
    char pad0[8];
    Manager_13b90 *manager;
    char pad0c[0x34 - 0xc];
    Controller_13b90 *controller;
};

class Input_13b90 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual int vfunc_26();
    virtual void vfunc_27();
    virtual float vfunc_28();
    virtual float vfunc_29();
    virtual void vfunc_30();
    virtual char vfunc_31();
    hulk_freg FUN_0006b540(float v);
    hulk_freg FUN_00069210(float v);
    hulk_freg FUN_000692c0(float v);
};

void *__fastcall FUN_000592a0(void *owner);
extern "C" Stats_13b90 *__fastcall FUN_00059a30(void *x);
Scene_13b90 *__fastcall FUN_00059a40(void *x);
extern "C" hulk_freg FUN_00224f10(Vec3_13b90 *v);
void *__cdecl FUN_00263ea0(unsigned int size);

class CJumpAction {
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
    Input_13b90 *input;
    JointDriver_13b90 *joint;
    float f28;
    float f2c;
    float f30;
};

char CJumpAction::vfunc_6(int arg)
{
    void *fighter = FUN_000592a0(owner);
    Stats_13b90 *stats = FUN_00059a30(fighter);
    Scene_13b90 *scene = FUN_00059a40(fighter);
    if (scene == 0)
        return 0;

    void *mem = FUN_00263ea0(0x70);
    JointDriver_13b90 *obj = 0;
    if (mem)
        obj = ((JointDriver_13b90 *)mem)->FUN_002248f0(0);
    joint = obj;

    obj->name.FUN_0027b040("jump");
    joint->vfunc_0();
    joint->transform.FUN_00221be0(&scene->pose);

    if (input->vfunc_31() && stats->chargeTime > 0.0f) {
        float t = FUN_00224f10(&stats->charge);
        joint->transform.FUN_00221d20(t);
        stats->FUN_000354e0(t);
    }

    int a = input->vfunc_26();
    float e1 = input->vfunc_28();
    float e2 = input->vfunc_29();
    scene->FUN_00222890(joint, -1.0f, a, 1.0f, e1, e2, -1.0f);

    float speed = stats->FUN_0003ec00(0);
    f28 = input->FUN_0006b540(speed);
    f2c = input->FUN_00069210(speed);
    f30 = input->FUN_000692c0(speed);

    World *g = DAT_004dd700;
    g->manager->FUN_00099d20(g, stats, f2c, f28, f30);

    Vec3_13b90 out;
    stats->mount->FUN_00059a50(&out);
    if (!(speed < 1.0f) && out.y > 100.0f)
        g->controller->FUN_001ec980(stats, "StartChargedJump");
    return 1;
}
} // namespace fn_00013b90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

