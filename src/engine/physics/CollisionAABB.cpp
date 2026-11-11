// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00312900..0x00312d50 (kind game, layer engine, confidence high), dominant class physics::CollisionAABB
#include "tree_prelude.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f7ee75ab {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f7ee75ab {} using namespace fn_f7ee75ab;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f7ee75ab {
class CollisionVolume_312900 {
  public:
    virtual void f();
    CollisionVolume_312900();
};
struct Z {
    int a, b, c;
    Z() {
        a = 0;
        _ReadWriteBarrier();
        b = 0;
        c = 0;
    }
};
class CollisionAABB : public CollisionVolume_312900 {
  public:
    virtual void f();
    CollisionAABB();
    char pad[0x34];
    Z z;
};
class pddiObject_312920 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_312920 : public pddiObject_312920 {};
class pddiBaseShader_312920 : public pddiShader_312920 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_312920 : public pddiBaseShader_312920 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class C_312930 {
  public:
    char pad[0x38];
};
class C_312940 {
  public:
    char pad[0x38];
};
extern void* hulk_at_00432274[];
class CollisionVolume_3129b0 {
  public:
    void Destroy_00306ac0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionAABB_3129b0 : public CollisionVolume_3129b0 {
  public:
    CollisionAABB_3129b0* vfunc_5(signed char flags);
};
struct Vec_3129e0 { float x,y,z; };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec_3129e0* position();
 char pad[0x24];
 Vec_3129e0 extent;
};


// 0x00312900 FUN_00312900 (29 B): matches/0x00312900.cpp
// sym: ??0CollisionAABB@fn_f7ee75ab@@QAE@XZ
CollisionAABB::CollisionAABB() : CollisionVolume_312900() {}

} // namespace fn_f7ee75ab

// 0x00312920 physics::CollisionAABB::vfunc_6 (6 B): matches/0x00312920.cpp
// sym: ?vfunc_6@CollisionAABB@physics@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int physics::CollisionAABB::vfunc_6() {
    return 1;
}

namespace fn_f7ee75ab {

// 0x00312930 physics::CollisionAABB::vfunc_4 (4 B): matches/0x00312930.cpp
// sym: ?FUN_00312930@fn_f7ee75ab@@YIPAVC_312930@1@PAV21@@Z
// Same code shape as 0x00092050 (propagated; names are from that function)
C_312930* __fastcall FUN_00312930(C_312930* p) {
    return (C_312930*)((char*)p + 0x38);
}


// 0x00312940 physics::CollisionAABB::vfunc_3 (4 B): matches/0x00312940.cpp
// sym: ?FUN_00312940@fn_f7ee75ab@@YIPAVC_312940@1@PAV21@@Z
// Same code shape as 0x00092050 (propagated; names are from that function)
C_312940* __fastcall FUN_00312940(C_312940* p) {
    return (C_312940*)((char*)p + 0x38);
}

} // namespace fn_f7ee75ab

// 0x00312960 physics::CollisionAABB::vfunc_14 (51 B): matches/0x00312960.cpp [wrapped: conflict: CollisionAABB]
// sym: ?vfunc_14@CollisionAABB@fn_00312960@@UAEXPAVCollisionVolume@2@@Z
namespace fn_00312960 {
struct Vec_312960 {
    unsigned x, y, z;
};
class CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec_312960* v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void vfunc_14(CollisionVolume*);
};
class CollisionAABB : public CollisionVolume {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void vfunc_14(CollisionVolume*);
};
void CollisionAABB::vfunc_14(CollisionVolume* param) {
    CollisionVolume::vfunc_14(param);
    Vec_312960* a = v4();
    Vec_312960* b = param->v4();
    b->x = a->x;
    b->y = a->y;
    b->z = a->z;
}
} // namespace fn_00312960


// 0x003129a0 physics::CollisionAABB::vfunc_5 (3 B): matches/0x003129a0.cpp
// sym: ?vfunc_5@CollisionAABB@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::CollisionAABB::vfunc_5(int a, int b) {}

namespace fn_f7ee75ab {

// 0x003129b0 physics::CollisionAABB::vfunc_2 (36 B): matches/0x003129b0.cpp
// sym: ?vfunc_5@CollisionAABB_3129b0@fn_f7ee75ab@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionAABB_3129b0* CollisionAABB_3129b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00432274;
    Destroy_00306ac0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x003129e0 FUN_003129e0 (208 B): equivalent/0x003129e0.cpp
// sym: ?FUN_003129e0@fn_f7ee75ab@@YGXPAUVec_3129e0@1@0PAUObject@1@@Z @7820a0a901f4 @w0ef89127c5de
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_003129e0 @ 0x003129e0
void __stdcall FUN_003129e0(Vec_3129e0* upper, Vec_3129e0* lower, Object* object) {
 Vec_3129e0* p = object->position();
 double v = (double)object->extent.x + p->x;
 upper->x = v > upper->x ? (float)v : upper->x;
 p = object->position();
 v = (double)p->x - object->extent.x;
 lower->x = v > lower->x ? lower->x : (float)v;
 p = object->position();
 v = (double)p->y + object->extent.y;
 upper->y = v > upper->y ? (float)v : upper->y;
 p = object->position();
 v = (double)p->y - object->extent.y;
 lower->y = v > lower->y ? lower->y : (float)v;
 p = object->position();
 v = (double)p->z + object->extent.z;
 upper->z = v > upper->z ? (float)v : upper->z;
 p = object->position();
 v = (double)p->z - object->extent.z;
 lower->z = v > lower->z ? lower->z : (float)v;
}

} // namespace fn_f7ee75ab

// 0x00312ab0 physics::CollisionAABB::vfunc_11 (88 B): equivalent/0x00312ab0.cpp [wrapped: conflict: physics::CollisionAABB; physics::CollisionVolume]
// sym: ?vfunc_11@CollisionAABB@physics@fn_00312ab0@@UAEXPAX@Z @495e52101dc8 @w9ce318db7dd4
namespace fn_00312ab0 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 7/8, incomplete)
// physics::CollisionAABB::vfunc_11 @ 0x00312ab0
namespace physics {
struct CollisionVolume {
  virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
  virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
  virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
  virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(void*);
  virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
};
struct Children { CollisionVolume** begin; CollisionVolume** end; };
struct CollisionAABB : CollisionVolume {
  char pad[0x10];
  Children* children;
  void vfunc_11(void* argument);
};
void CollisionAABB::vfunc_11(void* argument) {
  if (children) {
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); ++i)
      children->begin[i]->vfunc_11(argument);
  }
  vfunc_8();
}
}
} // namespace fn_00312ab0


// 0x00312b10 physics::CollisionAABB::vfunc_8 (424 B): equivalent/0x00312b10.cpp [wrapped: conflict: physics::CollisionAABB]
// sym: ?RecomputeBounds@CollisionAABB@physics@fn_00312b10@@UAEXXZ @fb43b99a1dff @wc450af6e5c5a
namespace fn_00312b10 {
// STATUS: equivalent (tools/equiv.py level 3: 15504 inputs, branch coverage 21/22, incomplete)
// physics::CollisionAABB::vfunc_8 @ 0x00312b10
// physics::CollisionAABB::vfunc_8 @ 0x00312b10
struct Vec3_312b10 { float x, y, z; };

namespace physics {

class CollisionAABB;

struct VolumeList {
    CollisionAABB **begin;
    CollisionAABB **end;
};

class CollisionAABB {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_312b10 *GetCenter();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void RecomputeBounds();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    char pad04[0xc];
    CollisionAABB *parent;
    VolumeList *children;
    unsigned char active;
    unsigned char dirty;
    char pad1a[6];
    CollisionAABB *owned;
    char pad24[4];
    Vec3_312b10 halfExtent;
    float radius;
    void FUN_003129e0(Vec3_312b10 *hi, Vec3_312b10 *lo, CollisionAABB *child);
};

}

void physics::CollisionAABB::RecomputeBounds()
{
    bool first = true;
    dirty = 1;
    if (!active)
        return;
    if (children == 0)
        return;
    if ((unsigned int)(children->end - children->begin) == 0)
        return;

    Vec3_312b10 hi;
    Vec3_312b10 lo;
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); i++) {
        CollisionAABB *child = children->begin[i];
        if (child->active) {
            child->RecomputeBounds();
            if (first) {
                first = false;
                Vec3_312b10 *c = child->GetCenter();
                hi.x = c->x + child->halfExtent.x;
                hi.y = c->y + child->halfExtent.y;
                hi.z = c->z + child->halfExtent.z;
                c = child->GetCenter();
                lo.x = c->x - child->halfExtent.x;
                lo.y = c->y - child->halfExtent.y;
                lo.z = c->z - child->halfExtent.z;
            } else {
                FUN_003129e0(&hi, &lo, child);
            }
        }
    }

    Vec3_312b10 *c = GetCenter();
    c->x = lo.x + hi.x;
    c->y = lo.y + hi.y;
    c->z = lo.z + hi.z;
    c = GetCenter();
    c->x = c->x * 0.5f;
    c->y = c->y * 0.5f;
    c->z = c->z * 0.5f;

    // the difference is stored as a float before it is halved (it can overflow to infinity)
    volatile Vec3_312b10 *half = &halfExtent;
    half->x = hi.x - lo.x;
    half->y = hi.y - lo.y;
    half->z = hi.z - lo.z;
    half->x = half->x * 0.5f;
    half->y = half->y * 0.5f;
    half->z = half->z * 0.5f;

    if (parent != 0 && parent->owned == this) {
        float m = (halfExtent.y < halfExtent.z) ? halfExtent.z : halfExtent.y;
        if (!(m > halfExtent.x))
            m = halfExtent.x;
        radius = m * 1.732f;
    }
}
} // namespace fn_00312b10

