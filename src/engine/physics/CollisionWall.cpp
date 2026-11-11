// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030e630..0x0030ea00 (kind game, layer engine, confidence high), dominant class physics::CollisionWall
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fc25916f {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fc25916f {} using namespace fn_fc25916f;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fc25916f {
class ParamValue_30e6b0 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class CollisionWall {
  public:
    char pad[0x54];
    void vfunc_15(unsigned int* p);
};
struct Vec3_30e760 {
    float x, y, z;
    void FUN_0022d180();
};
struct Ray_30e760 {
    char pad00[0x1c];
    Vec3_30e760 origin;       // 0x1c
    char pad28[0x34 - 0x28];
    float range;       // 0x34
    Vec3_30e760 dir;          // 0x38
    char pad44[0x48 - 0x44];
    Vec3_30e760 dirCopy;      // 0x48
    Vec3_30e760 start;        // 0x54
    void FUN_003060e0();
    void Init(const Vec3_30e760* from, const Vec3_30e760* direction);
};
class CollisionVolume_30e7d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int* q();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(void*);
};
class CollisionWall_30e7d0 : public CollisionVolume_30e7d0 {
  public:
    char pad[0x38 - sizeof(CollisionVolume_30e7d0)];
    int x38, x3c, x40, x44;
    int x48, x4c, x50;
    virtual void w13();
    virtual void vfunc_14(CollisionWall_30e7d0*);
};
} // namespace fn_fc25916f
namespace physics {
struct WallResult {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void *vfunc_4(unsigned int);
};
}
namespace physics {
struct WallOwner { char pad[0x18]; WallResult *result; };
}
namespace fn_fc25916f {
struct WallResponse {  };
extern void* hulk_at_0043201c[];
class CollisionVolume_30e930 {
  public:
    void Destroy_00306ac0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionWall_30e930 : public CollisionVolume_30e930 {
  public:
    CollisionWall_30e930* vfunc_5(signed char flags);
};

} // namespace fn_fc25916f

// 0x0030e630 FUN_0030e630 (116 B): matches/0x0030e630.cpp [wrapped: conflict: physics::CollisionWall]
// sym: ??0CollisionWall@physics@fn_0030e630@@QAE@PBUV3_30e630@2@0@Z
namespace fn_0030e630 {
struct V3_30e630 {
    int x, y, z;
    void Fix_0022d180();
};
struct CollisionVolume_30e630 {
    CollisionVolume_30e630();
    virtual void v0_00018b30();
    char p[0x18];
};
namespace physics {
struct CollisionWall : CollisionVolume_30e630 {
    V3_30e630 a;
    char q[0x0c];
    int k;
    V3_30e630 b;
    int gap;
    V3_30e630 c;
    V3_30e630 d;
    CollisionWall(const V3_30e630* pa, const V3_30e630* pb);
    virtual void v1_00018b40();
};
} // namespace physics
physics::CollisionWall::CollisionWall(const V3_30e630* pa, const V3_30e630* pb) {
    b = *pb;
    d.x = pa->x;
    d.y = pa->y;
    d.z = pa->z;
    a.x = pa->x;
    a.y = pa->y;
    a.z = pa->z;
    V3_30e630* p = &b;
    p->Fix_0022d180();
    c.x = p->x;
    c.y = p->y;
    c.z = p->z;
    int* q = &k;
    *q = 0x4e6e6b28;
}
} // namespace fn_0030e630


// 0x0030e6b0 physics::CollisionWall::vfunc_6 (6 B): matches/0x0030e6b0.cpp
// sym: ?vfunc_6@CollisionWall@physics@@UAEHXZ
// Same code shape as 0x00234f10 (propagated; names are from that function)
int physics::CollisionWall::vfunc_6() {
    return 8;
}

namespace fn_fc25916f {

// 0x0030e6c0 physics::CollisionWall::vfunc_4 (4 B): matches/0x0030e6c0.cpp
// sym: ?CollisionWall_vfunc_4@fn_fc25916f@@YIPAVCollisionWall@1@PAV21@@Z
CollisionWall* __fastcall CollisionWall_vfunc_4(CollisionWall* self) {
    return (CollisionWall*)((char*)self + 0x54);
}

} // namespace fn_fc25916f

// 0x0030e6d0 physics::CollisionWall::vfunc_3 (4 B): matches/0x0030e6d0.cpp [wrapped: same definition as 0x0030e6c0 in this TU]
// sym: ?CollisionWall_vfunc_4@fn_0030e6d0@@YIPAUCollisionWall@1@PAU21@@Z
namespace fn_0030e6d0 {
// Same code shape as 0x0030e6c0 (propagated; names are from that function)
struct CollisionWall {
    char pad[0x54];
};
CollisionWall* __fastcall CollisionWall_vfunc_4(CollisionWall* self) {
    return (CollisionWall*)((char*)self + 0x54);
}
} // namespace fn_0030e6d0

namespace fn_fc25916f {

// 0x0030e6e0 physics::CollisionWall::vfunc_15 (24 B): matches/0x0030e6e0.cpp
// sym: ?vfunc_15@CollisionWall@fn_fc25916f@@QAEXPAI@Z
void CollisionWall::vfunc_15(unsigned int* p) {
    *(unsigned int*)(pad + 0x54) = p[0];
    *(unsigned int*)(pad + 0x58) = p[1];
    *(unsigned int*)(pad + 0x5c) = p[2];
}

} // namespace fn_fc25916f

// 0x0030e700 FUN_0030e700 (69 B): equivalent/0x0030e700.cpp [wrapped: conflict: CollisionWall]
// sym: ??0CollisionWall@fn_0030e700@@QAE@XZ @35097ea1399c @w3624ad621839
namespace fn_0030e700 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030e700 @ 0x0030e700
struct FUN_003060a0 { virtual void slot0_00018b30(); FUN_003060a0(); char pad[0x30]; }; struct CollisionWall : FUN_003060a0 { int id; float x,y,z,w; float x2,y2,z2; int a,b,c; CollisionWall(); }; CollisionWall::CollisionWall() { a=0; b=0; c=0; x=0.0f; z=0.0f; y=1.0f; x2=0.0f; y2=y; z2=z; w=0.0f; id=0x4e6e6b28; }
} // namespace fn_0030e700

namespace fn_fc25916f {

// 0x0030e760 FUN_0030e760 (107 B): equivalent/0x0030e760.cpp
// sym: ?Init@Ray_30e760@fn_fc25916f@@QAEXPBUVec3_30e760@2@0@Z @1f323cd13f73 @w56893ae4e562
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030e760 @ 0x0030e760
void Ray_30e760::Init(const Vec3_30e760* from, const Vec3_30e760* direction)
{
    FUN_003060e0();
    dir = *direction;
    start = *from;
    origin = *from;
    dir.FUN_0022d180();
    dirCopy = dir;
    range = 1.0e9f;
}


// 0x0030e7d0 physics::CollisionWall::vfunc_14 (95 B): matches/0x0030e7d0.cpp
// sym: ?vfunc_14@CollisionWall_30e7d0@fn_fc25916f@@UAEXPAV12@@Z
void CollisionWall_30e7d0::vfunc_14(CollisionWall_30e7d0* out) {
    CollisionVolume_30e7d0::f14(out);
    int* a = this->q();
    int* b = out->q();
    b[0] = a[0];
    b[1] = a[1];
    b[2] = a[2];
    out->x38 = x38;
    out->x3c = x3c;
    out->x40 = x40;
    out->x48 = x48;
    out->x4c = x4c;
    out->x50 = x50;
    out->x44 = x44;
}

} // namespace fn_fc25916f

// 0x0030e830 physics::CollisionWall::vfunc_7 (61 B): matches/0x0030e830.cpp [wrapped: conflict: physics::CollisionWall]
// sym: ?vfunc_7@CollisionWall@physics@fn_0030e830@@QAEXM@Z
namespace fn_0030e830 {
// data: one = DAT_003f32dc

class CollisionVolume {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(float);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
struct Vec3_30e830 {
    float x, y, z;
    void Normalize_0022d180();
};
namespace physics {
class CollisionWall : public CollisionVolume {
  public:
    char pad[0x44];
    Vec3_30e830 v;
    void vfunc_7(float);
};
} // namespace physics
void physics::CollisionWall::vfunc_7(float x) {
    Vec3_30e830* p = &v;
    p->Normalize_0022d180();
    hulk_freg q = DAT_003f32dc / x;
    p->x *= q;
    p->y *= q;
    p->z *= q;
    CollisionVolume::f7(x);
}
} // namespace fn_0030e830


// 0x0030e870 physics::CollisionWall::vfunc_13 (39 B): equivalent/0x0030e870.cpp
// sym: ?vfunc_13@CollisionWall@physics@@UAEXXZ @1de21a83c1ce @w78bba1aafffd
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// physics::CollisionWall::vfunc_13 @ 0x0030e870
void physics::CollisionWall::vfunc_13() {
    this->f_19 = 1;
    WallResponse *response = (WallResponse *)(*(WallOwner * *)&this->f_10)->result->vfunc_4((*(unsigned int *)&this->f_08));
    ((owners::M_22c3b0 *)response)->FUN_0022c3b0((float *)((*(char (*)[4])&this->f_48)), (float *)((*(char (*)[16])&this->f_38)));
}


// 0x0030e8a0 FUN_0030e8a0 (116 B): matches/0x0030e8a0.cpp
// sym: ?FUN_0030e8a0@Obj_30e8a0@owners@@QAEXXZ
// data: threshold_30e8a0 = DAT_004d2fb8
void owners::Obj_30e8a0::FUN_0030e8a0() {
    state = 0;
    if (a > (*(const float*)&DAT_004d2fb8)) {
        state = 2;
        a = 1.0f;
        c = 0.0f;
        b = 0.0f;
        return;
    }
    if (b > (*(const float*)&DAT_004d2fb8)) {
        state = 3;
        a = 0.0f;
        b = 1.0f;
        c = 0.0f;
        return;
    }
    if (c > (*(const float*)&DAT_004d2fb8)) {
        state = 4;
        a = 0.0f;
        c = 1.0f;
        b = 0.0f;
    }
}


// 0x0030e920 physics::CollisionWall::vfunc_5 (3 B): matches/0x0030e920.cpp
// sym: ?vfunc_5@CollisionWall@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::CollisionWall::vfunc_5(int a, int b) {}

namespace fn_fc25916f {

// 0x0030e930 physics::CollisionWall::vfunc_2 (36 B): matches/0x0030e930.cpp
// sym: ?vfunc_5@CollisionWall_30e930@fn_fc25916f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionWall_30e930* CollisionWall_30e930::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0043201c;
    Destroy_00306ac0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fc25916f

// 0x0030e960 physics::CollisionWall::vfunc_8 (157 B): matches/0x0030e960.cpp [wrapped: conflict: CollisionWall]
// sym: ?FUN_0030e960@CollisionWall@fn_0030e960@@QAEXXZ
namespace fn_0030e960 {
// physics::CollisionWall::vfunc_8 @ 0x0030e960
// physics::CollisionWall::vfunc_8: per-axis inverse extents, "infinite" (5e8) unless the axis is a unit direction
class CollisionWall {
public:
    char pad00[0x28];
    float inv[3];
    char pad34[4];
    float dir[3];

    void FUN_0030e960();
};

union FloatBits_30e960 {
    float f;
    unsigned int u;
};

void CollisionWall::FUN_0030e960()
{
    FloatBits_30e960 a;
    a.f = dir[0];
    a.u &= 0x7fffffff;
    inv[0] = (1.0f - a.f < 1e-5f) ? 0.0f : 5e8f;
    FloatBits_30e960 b;
    b.f = dir[1];
    b.u &= 0x7fffffff;
    inv[1] = (1.0f - b.f < 1e-5f) ? 0.0f : 5e8f;
    FloatBits_30e960 c;
    c.f = dir[2];
    c.u &= 0x7fffffff;
    inv[2] = (1.0f - c.f < 1e-5f) ? 0.0f : 5e8f;
}
} // namespace fn_0030e960

