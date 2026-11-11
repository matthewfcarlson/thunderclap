// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fb600..0x002fbf20 (kind game, layer engine, confidence high), dominant class physics::CollisionOBB
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f34550b1 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f34550b1 {} using namespace fn_f34550b1;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f34550b1 {
class CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7(float p);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};
class CollisionOBB : public CollisionVolume {
  public:
    virtual void vfunc_7(float p);
    char pad[0x48 - 4];
    float x, y, z;
    char pad2[0x88 - 0x54];
    float sx, sy, sz;
};
struct Mat_2fb7a0 {
    float m[16];
};
struct Prov_2fb7a0;
struct Prov_2fb7a0 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual Mat_2fb7a0* Get(int id);
};
struct Mid_2fb7a0 {
    char pad[0x18];
    Prov_2fb7a0* prov;
    Mat_2fb7a0* Get(int id) { return prov->Get(id); }
};
struct Obj_2fb810 {
    char pad[256];
};
struct Vec_2fb860 {
    float x, y, z;
};
struct Obj_2fb860 {
    char pad[0x38];
    int mode;
    char pad2[12];
    float sx, sy, sz;
    Vec_2fb860 a, b, c;
    void FUN_002fb860(Vec_2fb860* out, int index);
};
typedef unsigned int u32_2fb950;
struct Vec_2fb950 {
    float x, y, z;
};
class C_2fb950 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Vec_2fb950* get();
    void helper_002fb860(Vec_2fb950*, u32_2fb950);
    void sum(Vec_2fb950*, u32_2fb950);
};
struct V3_2fb990 {
    float x, y, z;
};
class Basis_2fb990 {
public:
    char pad0[0x48];
    float w[3];     // 0x48
    V3_2fb990 axis[3];     // 0x54
    void FUN_002fb990(V3_2fb990* out, int a, int negate);
};
struct Bits3 { unsigned int x,y,z; };
struct Vec3_2fba80 { float x,y,z; };
struct CollisionOBB_2fba80 {
 char pad0[0x1c]; Bits3 position; char pad28[0xc]; float radius; unsigned int flags; Bits3 savedPosition; Vec3_2fba80 scale; Bits3 axisX,axisY,axisZ; char pad78[0x10]; Vec3_2fba80 savedScale; Bits3 savedX,savedY,savedZ;
 void FUN_002fba80(const Bits3* p,const Vec3_2fba80* s,const Bits3* x,const Bits3* y,const Bits3* z);
};
struct Vec_2fbcd0 { float x,y,z; };
struct Shape_2fbcd0 {
 char pad0[0x38]; int axisAligned; char pad1[0xc];
 float extentX,extentY,extentZ;
 Vec_2fbcd0 axisX,axisY,axisZ;
 hulk_freg projection(const Vec_2fbcd0* v);
};
struct Vec_2fbdc0 { float x,y,z; };
struct Shape_2fbdc0 {
 char pad[0x38]; int aligned; char pad2[0xc]; float extentX,extentY,extentZ; Vec_2fbdc0 axisX,axisY,axisZ;
 hulk_freg FUN_002fbdc0(const Vec_2fbdc0* v, int excluded);
};
class Part_2fbed0 {
  public:
    void Init_0030eaa0();
};
class CollisionOBB_2fbed0 {
  public:
    virtual void v();
    char pad[0x38];
    Part_2fbed0 p1;
    char pad2[0x3f];
    Part_2fbed0 p2;
    void Base_003060a0();
    void Build_002fba80(int, int, int, int, int);
    CollisionOBB_2fbed0* Target(hulk_intptr, hulk_intptr, hulk_intptr, hulk_intptr, hulk_intptr);
};


// 0x002fb600 physics::CollisionOBB::vfunc_6 (6 B): matches/0x002fb600.cpp
// sym: ?FUN_002fb600@fn_f34550b1@@YAHXZ
// Same code shape as 0x0008c580 (propagated; names are from that function)
int FUN_002fb600() {
    return 5;
}


// 0x002fb610 physics::CollisionOBB::vfunc_4 (4 B): matches/0x002fb610.cpp
// sym: ?FUN@fn_f34550b1@@YIPAHPAXH@Z
// Same code shape as 0x001c39c0 (propagated; names are from that function)
int* __fastcall FUN(void* p, int) {
    return (int*)((char*)p + 0x3c);
}

} // namespace fn_f34550b1

// 0x002fb620 physics::CollisionOBB::vfunc_3 (4 B): matches/0x002fb620.cpp [wrapped: same definition as 0x002fb610 in this TU]
// sym: ?FUN@fn_002fb620@@YIPAHPAXH@Z
namespace fn_002fb620 {
// Same code shape as 0x001c39c0 (propagated; names are from that function)
int* __fastcall FUN(void* p, int) {
    return (int*)((char*)p + 0x3c);
}
} // namespace fn_002fb620


// 0x002fb630 physics::CollisionOBB::vfunc_15 (4 B): matches/0x002fb630.cpp [wrapped: same definition as 0x002fb610 in this TU]
// sym: ?FUN@fn_002fb630@@YIPAHPAXH@Z
namespace fn_002fb630 {
// Same code shape as 0x001c39c0 (propagated; names are from that function)
int* __fastcall FUN(void* p, int) {
    return (int*)((char*)p + 0x3c);
}
} // namespace fn_002fb630


// 0x002fb640 physics::CollisionOBB::vfunc_14 (275 B): matches/0x002fb640.cpp [wrapped: conflict: physics::CollisionOBB; physics::CollisionVolume]
// sym: ?vfunc_14@CollisionOBB@physics@fn_002fb640@@UAEXPAUCollisionVolume@23@@Z
namespace fn_002fb640 {
struct Vec3_2fb640 {
    unsigned int x, y, z;
};
namespace physics {
struct CollisionVolume {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_2fb640* vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(CollisionVolume*);
    char pad04[0x34];
    unsigned int flags;
    char pad3c[12];
    unsigned int scaleX, scaleY, scaleZ;
    Vec3_2fb640 axisX, axisY, axisZ;
    char pad78[16];
    unsigned int worldScaleX, worldScaleY, worldScaleZ;
    Vec3_2fb640 worldAxisX, worldAxisY, worldAxisZ;
};
struct CollisionOBB : CollisionVolume {
    void vfunc_14(CollisionVolume* destination);
};
void CollisionOBB::vfunc_14(CollisionVolume* destination) {
    CollisionVolume::vfunc_14(destination);
    Vec3_2fb640* sourceVector = vfunc_4();
    Vec3_2fb640* targetVector = destination->vfunc_4();
    targetVector->x = sourceVector->x;
    targetVector->y = sourceVector->y;
    targetVector->z = sourceVector->z;
    destination->axisX.x = axisX.x;
    destination->axisX.y = axisX.y;
    destination->axisX.z = axisX.z;
    destination->worldAxisX.x = worldAxisX.x;
    destination->worldAxisX.y = worldAxisX.y;
    destination->worldAxisX.z = worldAxisX.z;
    destination->scaleX = scaleX;
    destination->worldScaleX = worldScaleX;
    destination->axisY.x = axisY.x;
    destination->axisY.y = axisY.y;
    destination->axisY.z = axisY.z;
    destination->worldAxisY.x = worldAxisY.x;
    destination->worldAxisY.y = worldAxisY.y;
    destination->worldAxisY.z = worldAxisY.z;
    destination->scaleY = scaleY;
    destination->worldScaleY = worldScaleY;
    destination->axisZ.x = axisZ.x;
    destination->axisZ.y = axisZ.y;
    destination->axisZ.z = axisZ.z;
    destination->worldAxisZ.x = worldAxisZ.x;
    destination->worldAxisZ.y = worldAxisZ.y;
    destination->worldAxisZ.z = worldAxisZ.z;
    destination->scaleZ = scaleZ;
    destination->worldScaleZ = worldScaleZ;
    destination->flags = flags;
}
} // namespace physics
} // namespace fn_002fb640

namespace fn_f34550b1 {

// 0x002fb760 physics::CollisionOBB::vfunc_7 (63 B): matches/0x002fb760.cpp
// sym: ?vfunc_7@CollisionOBB@fn_f34550b1@@UAEXM@Z
void CollisionOBB::vfunc_7(float p) {
    x = p * sx;
    y = p * sy;
    z = p * sz;
    _ReadWriteBarrier();
    this->v9();
    CollisionVolume::vfunc_7(p);
}

} // namespace fn_f34550b1

// 0x002fb7a0 physics::CollisionOBB::vfunc_13 (107 B): matches/0x002fb7a0.cpp
// sym: ?vfunc_13@CollisionOBB@physics@@UAEXXZ
void physics::CollisionOBB::vfunc_13() {
    (*(char *)&this->f_19) = 1;
    Mat_2fb7a0 m = *(*(Mid_2fb7a0 * *)&this->f_10)->Get(this->f_08);
    ((owners::M_22c3b0 *)&m)->FUN_0022c3b0((float *)((*(char (*)[12])&this->f_94)), (float *)((*(char (*)[12])&this->f_54)));
    ((owners::M_22c3b0 *)&m)->FUN_0022c3b0((float *)((*(char (*)[12])&this->f_a0)), (float *)((*(char (*)[12])&this->f_60)));
    ((owners::M_22c3b0 *)&m)->FUN_0022c3b0((float *)((*(char (*)[12])&this->f_ac)), (float *)((*(char (*)[12])&this->f_6c)));
}


// 0x002fb810 physics::CollisionOBB::vfunc_11 (72 B): matches/0x002fb810.cpp
// sym: ?vfunc_11@CollisionOBB@physics@@UAEXPAX@Z
void physics::CollisionOBB::vfunc_11(void* __p0) { void * arg = (void *)__p0;

    Obj_2fb810* o = (Obj_2fb810*)arg;
    ((owners::M_22c3b0 *)o)->FUN_0022c3b0((float *)((char*)this + 0x54), (float *)((char*)this + 0x54));
    ((owners::M_22c3b0 *)o)->FUN_0022c3b0((float *)((char*)this + 0x60), (float *)((char*)this + 0x60));
    ((owners::M_22c3b0 *)o)->FUN_0022c3b0((float *)((char*)this + 0x6c), (float *)((char*)this + 0x6c));
    ((owners::Mat_22c2b0 *)o)->FUN_0022c2b0((float *)(hulk_uintptr)(int)(this->vfunc_4()), (float *)(hulk_uintptr)(int)(this->vfunc_4()));
}

namespace fn_f34550b1 {

// 0x002fb860 FUN_002fb860 (211 B): matches/0x002fb860.cpp
// sym: ?FUN_002fb860@Obj_2fb860@fn_f34550b1@@QAEXPAUVec_2fb860@2@H@Z
void Obj_2fb860::FUN_002fb860(Vec_2fb860* out, int index) {
    hulk_freg sign = index > 3 ? -1.0f : 1.0f;
    hulk_freg x = sign * sx;
    hulk_freg y = sign * sy;
    hulk_freg z = sign * sz;
    if (index % 4 > 1)
        y = y * -1.0f;
    if (index % 2 == 1)
        z = z * -1.0f;
    if (!mode) {
        out->x = (z * c.x + y * b.x) + x * a.x;
        out->y = (z * c.y + y * b.y) + x * a.y;
        out->z = (z * c.z + y * b.z) + x * a.z;
    } else {
        out->x = x * a.x;
        out->y = y * b.y;
        out->z = z * c.z;
    }
}

// 0x002fb940 thunk_FUN_002fb860 (5 B): not yet verified

// 0x002fb950 FUN_002fb950 (55 B): matches/0x002fb950.cpp
// sym: ?sum@C_2fb950@fn_f34550b1@@QAEXPAUVec_2fb950@2@I@Z
void C_2fb950::sum(Vec_2fb950* p, u32_2fb950 a) {
    helper_002fb860(p, a);
    Vec_2fb950* q = get();
    p->x += q->x;
    p->y += q->y;
    p->z += q->z;
}


// 0x002fb990 FUN_002fb990 (114 B): equivalent/0x002fb990.cpp
// sym: ?FUN_002fb990@Basis_2fb990@fn_f34550b1@@QAEXPAUV3_2fb990@2@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fb990 @ 0x002fb990
// Blends two of the three axes, weighted by w[], into out.
void Basis_2fb990::FUN_002fb990(V3_2fb990* out, int a, int negate)
{
    int i;
    int j;
    if (a >= 2) {
        i = 0;
        j = 1;
    } else {
        i = a + 1;
        if (i < 2)
            j = i + 1;
        else
            j = 0;
    }
    float s = w[i];
    if (negate != 0)
        s = -s;
    out->x = s * axis[i].x;
    out->y = s * axis[i].y;
    out->z = s * axis[i].z;
    float t = w[j];
    out->x = t * axis[j].x + out->x;
    out->y = t * axis[j].y + out->y;
    out->z = t * axis[j].z + out->z;
}

} // namespace fn_f34550b1

// 0x002fba10 physics::CollisionOBB::vfunc_5 (3 B): matches/0x002fba10.cpp
// sym: ?vfunc_5@CollisionOBB@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::CollisionOBB::vfunc_5(int a, int b) {}


// 0x002fba40 physics::CollisionOBB::vfunc_2 (54 B): matches/0x002fba40.cpp [wrapped: conflict: physics::CollisionOBB; physics::CollisionVolume]
// sym: ?vfunc_2@CollisionOBB@physics@fn_002fba40@@UAEPAV123@E@Z
namespace fn_002fba40 {
extern "C" char DAT_004317dc[];
typedef unsigned char byte_2fba40;
class H1 {
  public:
    void Fnf_0030ea00();
};
class H2_2fba40 {
  public:
    void Fnf_0030ea00();
};
class CollisionOBB_2fba40 {
  public:
    void Fnf_00306ac0();
};
namespace physics {
class CollisionVolume {
  public:
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
    virtual void n();
    virtual void o();
    virtual void p();
};
class CollisionOBB : public CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual CollisionOBB* vfunc_2(byte_2fba40);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    char pad[0x78];
};
} // namespace physics
void cleanup_0008d330(physics::CollisionOBB*);
physics::CollisionOBB* physics::CollisionOBB::vfunc_2(byte_2fba40 flag) {
    CollisionOBB* self = this;
    *(hulk_ulongptr*)self = ((hulk_intptr)DAT_004317dc);
    ((H1*)((char*)self + 0x7c))->Fnf_0030ea00();
    ((H2_2fba40*)((char*)self + 0x3c))->Fnf_0030ea00();
    ((CollisionOBB_2fba40*)self)->Fnf_00306ac0();
    if (flag & 1)
        cleanup_0008d330(self);
    return self;
}
} // namespace fn_002fba40

namespace fn_f34550b1 {

// 0x002fba80 FUN_002fba80 (293 B): equivalent/0x002fba80.cpp
// sym: ?FUN_002fba80@CollisionOBB_2fba80@fn_f34550b1@@QAEXPBUBits3@2@PBUVec3_2fba80@2@000@Z
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 0/0)
// FUN_002fba80 @ 0x002fba80
void CollisionOBB_2fba80::FUN_002fba80(const Bits3* p,const Vec3_2fba80* s,const Bits3* x,const Bits3* y,const Bits3* z) {
 position.x=p->x; position.y=p->y; position.z=p->z;
 savedPosition.x=p->x; savedPosition.y=p->y; savedPosition.z=p->z;
 scale.x=savedScale.x=s->x; scale.y=savedScale.y=s->y; scale.z=savedScale.z=s->z;
 radius=(float)sqrt((double)s->y*s->y+(double)s->z*s->z+(double)s->x*s->x);
 savedX.x=x->x; savedX.y=x->y; savedX.z=x->z;
 savedY.x=y->x; savedY.y=y->y; savedY.z=y->z;
 savedZ.x=z->x; savedZ.y=z->y; savedZ.z=z->z;
 axisX.x=savedX.x; axisX.y=savedX.y; axisX.z=savedX.z;
 axisY.x=savedY.x; axisY.y=savedY.y; axisY.z=savedY.z;
 axisZ.x=savedZ.x; axisZ.y=savedZ.y; axisZ.z=savedZ.z;
 flags=0;
}

} // namespace fn_f34550b1

// 0x002fbbb0 physics::CollisionOBB::vfunc_8 (240 B): equivalent/0x002fbbb0.cpp [wrapped: conflict: physics::CollisionOBB]
// sym: ?vfunc_8@CollisionOBB@physics@fn_002fbbb0@@QAEXXZ
namespace fn_002fbbb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::CollisionOBB::vfunc_8 @ 0x002fbbb0
namespace physics {
struct CollisionOBB {
 char pad0[0x28];
 float bounds[3];
 char pad34[4];
 int axisAligned;
 char pad3c[12];
 float halfSize[3];
 float axes[3][3];
 void vfunc_8();
};
}
void physics::CollisionOBB::vfunc_8() {
 if (axisAligned) {
  bounds[0]=halfSize[0]; bounds[1]=halfSize[1]; bounds[2]=halfSize[2];
 } else {
  for (int i=0;i<3;++i) {
   union Bits { float f; unsigned int u; } a,b,c;
   a.f=axes[0][i]; a.u &= 0x7fffffff;
   b.f=axes[1][i]; b.u &= 0x7fffffff;
   c.f=axes[2][i]; c.u &= 0x7fffffff;
   bounds[i]=(a.f*halfSize[0]+c.f*halfSize[2])+b.f*halfSize[1];
  }
 }
}
} // namespace fn_002fbbb0


// 0x002fbca0 physics::CollisionOBB::vfunc_9 (41 B): equivalent/0x002fbca0.cpp [wrapped: conflict: physics::CollisionOBB; physics::CollisionVolume]
// sym: ?vfunc_9@CollisionOBB@physics@fn_002fbca0@@UAEXXZ
namespace fn_002fbca0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// physics::CollisionOBB::vfunc_9 @ 0x002fbca0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

namespace physics {
struct CollisionVolume {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
};
struct CollisionOBB : CollisionVolume {
    char padding[0x30];
    float radius;
    char padding2[0x10];
    float x;
    float y;
    float z;
    virtual void vfunc_9();
};
void CollisionOBB::vfunc_9() {
    radius = (float)sqrt(y*y + z*z + x*x);
    CollisionVolume::vfunc_9();
}
}
} // namespace fn_002fbca0

namespace fn_f34550b1 {

// 0x002fbcd0 FUN_002fbcd0 (232 B): equivalent/0x002fbcd0.cpp
// sym: ?projection@Shape_2fbcd0@fn_f34550b1@@QAEMPBUVec_2fbcd0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// FUN_002fbcd0 @ 0x002fbcd0
hulk_freg Shape_2fbcd0::projection(const Vec_2fbcd0* v) {
 union Bits { float f; unsigned int u; } x,y,z;
 if (!axisAligned) {
  x.f = (axisX.z*v->z + axisX.y*v->y) + axisX.x*v->x;
  y.f = (axisY.z*v->z + axisY.y*v->y) + v->x*axisY.x;
  z.f = (axisZ.z*v->z + axisZ.y*v->y) + axisZ.x*v->x;
 } else {
  x.f=v->x; y.f=v->y; z.f=v->z;
 }
 x.u &= 0x7fffffff; y.u &= 0x7fffffff; z.u &= 0x7fffffff;
 return (z.f*extentZ + y.f*extentY) + x.f*extentX;
}


// 0x002fbdc0 FUN_002fbdc0 (227 B): equivalent/0x002fbdc0.cpp
// sym: ?FUN_002fbdc0@Shape_2fbdc0@fn_f34550b1@@QAEMPBUVec_2fbdc0@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// FUN_002fbdc0 @ 0x002fbdc0
hulk_freg Shape_2fbdc0::FUN_002fbdc0(const Vec_2fbdc0* v, int excluded) {
 union Bits { float f; unsigned int u; } b;
 double sum=0.0f;
 if (!aligned) {
  if(excluded!=0) { b.f=(axisX.z*v->z+axisX.y*v->y)+axisX.x*v->x; b.u &= 0x7fffffff; sum=(double)b.f*extentX; }
  if(excluded!=1) { b.f=(axisY.z*v->z+axisY.y*v->y)+axisY.x*v->x; b.u &= 0x7fffffff; sum+=(double)b.f*extentY; }
  if(excluded!=2) { b.f=(axisZ.z*v->z+axisZ.y*v->y)+axisZ.x*v->x; b.u &= 0x7fffffff; sum+=(double)b.f*extentZ; }
 } else {
  if(excluded!=0) { b.f=v->x; b.u &= 0x7fffffff; sum=(double)b.f*extentX; }
  if(excluded!=1) { b.f=v->y; b.u &= 0x7fffffff; sum+=(double)b.f*extentY; }
  if(excluded!=2) { b.f=v->z; b.u &= 0x7fffffff; sum+=(double)b.f*extentZ; }
 }
 return (hulk_freg)sum;
}


// 0x002fbed0 FUN_002fbed0 (68 B): matches/0x002fbed0.cpp
// sym: ?Target@CollisionOBB_2fbed0@fn_f34550b1@@QAEPAV12@HHHHH@Z
CollisionOBB_2fbed0* CollisionOBB_2fbed0::Target(hulk_intptr a, hulk_intptr b, hulk_intptr c, hulk_intptr d, hulk_intptr e) {
    Base_003060a0();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004317dc);
    p1.Init_0030eaa0();
    p2.Init_0030eaa0();
    Build_002fba80(a, b, c, d, e);
    return this;
}

} // namespace fn_f34550b1
