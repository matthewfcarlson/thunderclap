// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00308a30..0x00308dd0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f05f0e87 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f05f0e87 {} using namespace fn_f05f0e87;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f05f0e87 {
struct X_308a50 {
    char pad[0x1c];
};
struct V3_308a80 {
    float x, y, z;
};
class Sub_308a80 {
public:
    virtual void Start(float delay, float volume, int flags);
    virtual void v1();
    virtual float Elapsed();
};
class Trigger_308a80 {
public:
    virtual void v0();
    virtual void v1();
    virtual V3_308a80 *Position();
    char pad04[0x28];
    Sub_308a80 subObj;
    char pad30[0x10];
    float radius;
    float delay;
    char pad48[4];
    float volume;
    char pad50[0xd];
    char armed;

    void FUN_00308a80(int unused);
};
struct Vec3_308b20 { float x, y, z; };
class Sink_308b20 {
public:
    virtual bool v0(int a, float b, int c);
};
class Mover_308b20 {
public:
    virtual void v0(Vec3_308b20* out, Vec3_308b20* in1, Vec3_308b20* in2);
    char pad04[0x28];
    Sink_308b20 sink;
    char pad30[0x10];
    float f40;
    int f44;
    char pad48[4];
    float f4c;
    char pad50[0xc];
    char busy;
    char dirty;
    bool FUN_00308b20();
};
namespace physics {
struct SimCGSValue { virtual void* slot0_002ecdc0(char); float a; float value; void FUN_002ecca0(); };
}
namespace physics {
struct SimLength : SimCGSValue { void FUN_002ecf20(int); void vfunc_1_002ecd50(float); };
}
struct Body_308ba0 { float FUN_002ef420(); };
struct Properties_308ba0 { char pad[0x28]; float mass; float unused; float stiffness; };
struct Owner_308ba0 { char pad[0x10]; Body_308ba0* body; char pad2[8]; Properties_308ba0* properties; };
struct Target_308ba0 {
char pad[0x40]; float damping; float rate; float length; float period; float periodScale; float dampingScale; float lengthScale; unsigned char dirty; char pad2[3]; Owner_308ba0* owner;
void FUN_00308b20(); bool update(float dt);
};
class SimpleFilter3D_308cc0 {
  public:
    virtual void f();
    char pad[0x28];
    SimpleFilter3D_308cc0();
};
class SimpleFilter1D_308cc0 {
  public:
    SimpleFilter1D_308cc0();
    char pad[0x14];
};
class SimpleFilterAbs3D : public SimpleFilter3D_308cc0 {
  public:
    SimpleFilter1D_308cc0 sub;
    int a, b, c, d;
    float x, y, z;
    unsigned char flag, flag2;
    char pad2[2];
    int last;
    SimpleFilterAbs3D();
    virtual void f();
};
class HairclubPhysicsObject {
  public:
    hulk_intptr vftable;
    char pad4[0x20];
    int field24;
    char pad28[0x1d0];
    int field1f8;
};
struct ThisCall_002f5480 {
    void BaseCtor_002f5480();
};

} // namespace fn_f05f0e87

// 0x00308a30 FUN_00308a30 (18 B): matches/0x00308a30.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0SimpleFilterAbs3D@physics@fn_00308a30@@QAE@XZ
namespace fn_00308a30 {
namespace physics {
class Base_308a30 {
  public:
    Base_308a30();
    virtual void V();
};
class SimpleFilterAbs3D : public Base_308a30 {
  public:
    SimpleFilterAbs3D();
    virtual void V();
};
void SimpleFilterAbs3D::V() {}
SimpleFilterAbs3D::SimpleFilterAbs3D() {}
} // namespace physics
} // namespace fn_00308a30

namespace fn_f05f0e87 {

// 0x00308a50 physics::SimpleFilter3D::vfunc_2 (4 B): matches/0x00308a50.cpp
// sym: ?target@fn_f05f0e87@@YIPAXPAUX_308a50@1@@Z
// Same code shape as 0x001c3990 (propagated; names are from that function)
void* __fastcall target(X_308a50* p) {
    return p->pad + 0x1c;
}


// 0x00308a60 FUN_00308a60 (1 B): matches/0x00308a60.cpp
// sym: ?FUN_00308a60@fn_f05f0e87@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00308a60() {}

} // namespace fn_f05f0e87

// 0x00308a70 FUN_00308a70 (10 B): matches/0x00308a70.cpp
// sym: ?FUN_00308a70@C_308a70@owners@@QAEXH@Z
void owners::C_308a70::FUN_00308a70(hulk_intptr x) {
    value = ((int)x);
}

namespace fn_f05f0e87 {

// 0x00308a80 FUN_00308a80 (157 B): equivalent/0x00308a80.cpp
// sym: ?FUN_00308a80@Trigger_308a80@fn_f05f0e87@@QAEXH@Z @a13800de8b6d @wf3fb1497dc4e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00308a80 @ 0x00308a80
// FUN_00308a80: arm the trigger once the tracked point is inside 1.5x the radius
void Trigger_308a80::FUN_00308a80(int unused)
{
    if (armed == 1)
        return;
    Sub_308a80 *sub = &subObj;
    V3_308a80 p = *Position();
    float r = radius;
    if (p.y > r || p.x > r * 1.5f || p.z > r * 1.5f) {
        sub->Start(delay, 0.5f * volume, 0);
        return;
    }
    if (!(sub->Elapsed() > delay))
        armed = 1;
}


// 0x00308b20 FUN_00308b20 (120 B): equivalent/0x00308b20.cpp
// sym: ?FUN_00308b20@Mover_308b20@fn_f05f0e87@@QAE_NXZ @002949a357e3 @w6d5687db3807
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// FUN_00308b20 @ 0x00308b20
bool Mover_308b20::FUN_00308b20() {
    char wasBusy = busy;
    dirty = 0;
    if (wasBusy)
        return false;
    float a = f40;
    float b = f4c;
    Vec3_308b20 hi = { b, b, b };
    Vec3_308b20 lo = { a, a, a };
    float half = b;
    v0(&lo, &hi, &hi);
    return (&sink)->v0(f44, 0.5f * half, 0);
}


// 0x00308ba0 FUN_00308ba0 (276 B): equivalent/0x00308ba0.cpp
// sym: ?update@Target_308ba0@fn_f05f0e87@@QAE_NM@Z @645eaa5381b0 @w2338a4e50657
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00308ba0 @ 0x00308ba0
bool Target_308ba0::update(float dt) {
 if(dirty) {
  Properties_308ba0* p=owner->properties;
  if(p && p->mass>0.0f) {
   double ratio=(double)p->stiffness/p->mass;
   double t=(double)dt/sqrt(ratio+ratio);
   period=(float)(sqrt(ratio)*(1.0-DAT_004d3120*10.0+DAT_004d3120*t)*periodScale*5.0);
   damping=(float)(sqrt((double)p->mass*p->stiffness*2.0)*(DAT_004d311c*t+DAT_004d3118)*dampingScale*0.1f);
  } else { damping=0.0f; period=1000000000.0f; }
  physics::SimCGSValue storage;
  physics::SimLength& temp=static_cast<physics::SimLength&>(storage);
  temp.FUN_002ecf20(0);
  Body_308ba0* b=owner->body;
  temp.vfunc_1_002ecd50(b ? b->FUN_002ef420() : 100.0f);
  double v=(double)lengthScale/temp.value;
  length=temp.value;
  dirty=0;
  rate=(float)(v*damping*2.0);
  if(owner->body) FUN_00308b20();
  temp.FUN_002ecca0();
 }
 return true;
}


// 0x00308cc0 FUN_00308cc0 (64 B): matches/0x00308cc0.cpp
// sym: ??0SimpleFilterAbs3D@fn_f05f0e87@@QAE@XZ
SimpleFilterAbs3D::SimpleFilterAbs3D()
    : SimpleFilter3D_308cc0(), sub(), a(0), b(0), c(0), d(0), x(1.0f), y(1.0f), z(1.0f), flag(1), flag2(0), last(0) {}


// 0x00308da0 FUN_00308da0 (35 B): matches/0x00308da0.cpp
// sym: ?FUN_00308da0@fn_f05f0e87@@YIPAVHairclubPhysicsObject@1@PAV21@@Z
HairclubPhysicsObject* __fastcall FUN_00308da0(HairclubPhysicsObject* self) {
    ((ThisCall_002f5480*)(self))->BaseCtor_002f5480();
    self->vftable = ((hulk_intptr)DAT_00431d1c);
    self->field1f8 = 0;
    self->field24 = 2;
    return self;
}

} // namespace fn_f05f0e87
