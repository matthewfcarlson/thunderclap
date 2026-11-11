// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3230..0x002c3650 (kind game, layer engine, confidence medium), dominant class pure3d::PointCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8d4cfbc {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8d4cfbc {} using namespace fn_f8d4cfbc;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f8d4cfbc {
extern "C" char DAT_0042ed30[];
struct Caller_2c3230 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n(void* p);
};
class Camera_2c32a0 {
  public:
    virtual void f();
    char pad[0xcc];
    Camera_2c32a0();
};
class PointCamera : public Camera_2c32a0 {
  public:
    int a, b, c, d, e, f0, g;
    float h;
    int i, j;
    PointCamera();
    virtual void f();
};
struct Triple_2c3410 {
    int a, b, c;
};
struct Object {
    char pad[0xcc];
    unsigned char flag;
    char pad2[0xe8 - 0xcd];
    int x, y, z;
    void Set(Triple_2c3410* p);
};
extern void* hulk_at_0042ed5c[];
class Camera_2c3460 {
  public:
    void Destroy_002926c0(); // FUN_00236d60, __thiscall, this in ecx
};
class PointCamera_2c3460 : public Camera_2c3460 {
  public:
    PointCamera_2c3460* vfunc_5(signed char flags);
};
struct Vec3_2c3490 {
    float x, y, z;
    void FUN_0022d180();
};
struct Mat4_2c3490 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float angle);
    void FUN_0022bec0(Vec3_2c3490* dir, Vec3_2c3490* up);
    void FUN_0022ca90(Mat4_2c3490* a, Mat4_2c3490* b);
    void FUN_0022c120();
};
namespace pure3d {
class PointCamera {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25();
    virtual void vfunc_26();
    char pad04[0x4c - 4];
    Mat4_2c3490 camera;
    Mat4_2c3490 view;
    char dirty;
    char padcd[3];
    Vec3_2c3490 eye;
    Vec3_2c3490 target;
    Vec3_2c3490 up;
    float roll;
};
}


// 0x002c3230 FUN_002c3230 (46 B): matches/0x002c3230.cpp
// sym: _FUN_002c3230
// data: g_flag_2c3230 = DAT_00554bdc, g_slot_2c3230 = DAT_00554bd8
extern "C" void FUN_002c3230(Caller_2c3230* p) {
    unsigned int one = 1;
    if ((((unsigned char)(*(unsigned int*)&DAT_00554bdc)) & one) == 0) {
        (*(unsigned int*)&DAT_00554bdc) |= one;
        (*(void**)&DAT_00554bd8) = (void*)DAT_0042ed30;  // a pointer slot (config/data-ptrs.json): 8 bytes on 64-bit
    }
    p->n((void*)&(*(unsigned int*)&DAT_00554bd8));
}


// 0x002c32a0 FUN_002c32a0 (84 B): matches/0x002c32a0.cpp
// sym: ??0PointCamera@fn_f8d4cfbc@@QAE@XZ
PointCamera::PointCamera() {
    volatile int* p = &a;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[8] = 0;
    h = 1.0f;
    p[9] = 0;
}

} // namespace fn_f8d4cfbc

// 0x002c33b0 FUN_002c33b0 (40 B): matches/0x002c33b0.cpp
// sym: ?FUN_002c33b0@C_2c33b0@owners@@QAEXPAH@Z
// Same code shape as 0x00293a90 (propagated; names are from that function)
void owners::C_2c33b0::FUN_002c33b0(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    flag = 0;
}


// 0x002c33e0 FUN_002c33e0 (40 B): matches/0x002c33e0.cpp
// sym: ?FUN_002c33e0@C_2c33e0@owners@@QAEXPAH@Z
// Same code shape as 0x00293af0 (propagated; names are from that function)
void owners::C_2c33e0::FUN_002c33e0(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    flag = 0;
}

namespace fn_f8d4cfbc {

// 0x002c3410 FUN_002c3410 (40 B): matches/0x002c3410.cpp
// sym: ?Set@Object@fn_f8d4cfbc@@QAEXPAUTriple_2c3410@2@@Z
// Same code shape as 0x00293ac0 (propagated; names are from that function)
void Object::Set(Triple_2c3410* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    flag = 0;
}


// 0x002c3460 pure3d::PointCamera::vfunc_2 (36 B): matches/0x002c3460.cpp
// sym: ?vfunc_5@PointCamera_2c3460@fn_f8d4cfbc@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PointCamera_2c3460* PointCamera_2c3460::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042ed5c;
    Destroy_002926c0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002c3490 pure3d::PointCamera::vfunc_26 (377 B): equivalent/0x002c3490.cpp
// sym: ?vfunc_26@PointCamera@pure3d@fn_f8d4cfbc@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 6/6)
// pure3d::PointCamera::vfunc_26 @ 0x002c3490
namespace pure3d {
void PointCamera::vfunc_26()
{
    Mat4_2c3490 look;
    look.FUN_0022b980();
    Vec3_2c3490 dir;
    dir.x = target.x - eye.x;
    dir.y = target.y - eye.y;
    dir.z = target.z - eye.z;
    dir.FUN_0022d180();
    float d = (float)fabs(dir.z * up.z + dir.y * up.y + dir.x * up.x);
    float t = (float)fabs(d - 1.0f);
    if (t <= 1e-05f) {
        Vec3_2c3490 alt;
        if (dir.y == 0.0f && dir.z == 0.0f) {
            alt.x = 0.0f;
            alt.y = 1.0f;
            alt.z = 0.0f;
        } else {
            alt.x = 1.0f;
            alt.y = 0.0f;
            alt.z = 0.0f;
        }
        look.FUN_0022bec0(&dir, &alt);
    } else {
        look.FUN_0022bec0(&dir, &up);
    }
    Mat4_2c3490 rot;
    rot.FUN_0022b980();
    rot.FUN_0022bab0(roll);
    view.FUN_0022ca90(&rot, &look);
    view.m[12] = eye.x;
    view.m[13] = eye.y;
    view.m[14] = eye.z;
    camera = view;
    camera.FUN_0022c120();
    dirty = 1;
}
}

} // namespace fn_f8d4cfbc
