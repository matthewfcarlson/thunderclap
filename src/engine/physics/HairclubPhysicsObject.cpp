// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00308dd0..0x003097b0 (kind game, layer engine, confidence high), dominant class physics::HairclubPhysicsObject
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fa60db69 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fa60db69 {} using namespace fn_fa60db69;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fa60db69 {
struct SymMatrix_nv_308de0 {
    void Call_002fca90();
};
struct Entry_308e40 {
 char base[0x1c];
 unsigned int x,y,z;
 unsigned int a,b;
 unsigned char flag;
 char padding[3];
 void FUN_002fd080();
};
void __cdecl FUN_00308de0();
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
void __stdcall FUN_00011520(void*,unsigned int,int,void (__cdecl*)());
struct Object {
 char pad[0x1f8];
 Entry_308e40* entries;
 int count;
 void FUN_002f75d0(Object*,int);
 void FUN_00308e40(Object* dest,int arg);
};
class PhysicsObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7();
};
struct Owner_308f60 {
    char pad[0xc];
    float scale;
};
struct Elem_308f60 {
    char pad[0x28];
    float a;
    float b;
    char pad2[4];
};
class HairclubPhysicsObject : public PhysicsObject {
  public:
    char pad18[0x18 - sizeof(PhysicsObject)];
    Owner_308f60* p18;
    char pad1f8[0x1f8 - 0x1c];
    Elem_308f60* arr;
    int count;
    virtual void vfunc_7();
};
struct V3_308fe0 {
    float x, y, z;
    void Scale(float s) { x = s * x; y = s * y; z = s * z; }
    void Sub(const V3_308fe0 &a, const V3_308fe0 &b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
};
struct Matrix4_308fe0 {
    float m[16];
};
struct SymMatrix {
    int vptr;
    float m[6];
    void FUN_002fca90();
    void FUN_002fcaa0();
    void FUN_002fcd60(const Matrix4_308fe0 *rot);
};
struct Part_308fe0 {
    SymMatrix inertia;
    V3_308fe0 pos;
    float mass;
    float massBits;
    unsigned char active;
    char pad31[3];
};
class Body_308fe0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const Matrix4_308fe0 *GetRotation(int i);
    char pad04[0xc];
    Matrix4_308fe0 mat;
};
extern "C" void __cdecl FUN_00305b00(SymMatrix *out, const V3_308fe0 *p, float mass);
class Hairclub {
public:
    char pad00[0x10];
    Body_308fe0 *body;
    char pad14[0x2c];
    float f40;
    float f44;
    char pad48[0x10];
    Matrix4_308fe0 mat;
    V3_308fe0 center;
    unsigned char flagA4;
    char padA5[3];
    V3_308fe0 va8;
    V3_308fe0 vb4;
    char padC0[0x1c];
    SymMatrix symDC;
    SymMatrix symF8;
    SymMatrix sym114;
    char pad130[0x1f8 - 0x130];
    Part_308fe0 *parts;
    int count;
    void FUN_00308fe0();
};
struct Frame_308fe0 {
    V3_308fe0 a;
    SymMatrix s1;
    V3_308fe0 b;
    SymMatrix s2;
    Matrix4_308fe0 mt;
};
struct Controller_309410 {
    void FUN_002ef8b0(int mode);
};
struct Part_309410 {
    char pad0[0x28];
    float y;
    float x;
    unsigned char active;
    char pad31[3];
};
class HairclubPhysicsObject_309410 {
public:
    void FUN_00308fe0();
    void FUN_00309410();

    char pad0[0x10];
    Controller_309410 *controller;
    char pad14[0x3c - 0x14];
    float sumX;
    float sumY;
    float invSumY;
    char pad48[0x1f8 - 0x48];
    Part_309410 *parts;
    int partCount;
};
typedef unsigned int u32_3094a0;
extern void* alloc_00263ea0(unsigned int);
struct Obj_3094a0 {
    void init_002f5480();
};
struct HairclubPhysicsObject_nv_3094a0 {
    void build_00308e40(void*, unsigned int);
};
struct Strand {
 char pad[0x28];
 float weight;
 char extra[4];
 unsigned char active;
 char tail[3];
};
} // namespace fn_fa60db69
namespace physics {
struct HairclubPhysicsObject_nv_309680 {
    void FUN_00309410();
};
}

namespace fn_fa60db69 {

// 0x00308dd0 physics::HairclubPhysicsObject::vfunc_30 (1 B): matches/0x00308dd0.cpp
// sym: ?FUN_00308dd0@fn_fa60db69@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00308dd0() {}

} // namespace fn_fa60db69

// 0x00308de0 FUN_00308de0 (12 B): matches/0x00308de0.cpp
// sym: ?FUN_00308de0@SymMatrix@physics@@QAEPAV12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
physics::SymMatrix* physics::SymMatrix::FUN_00308de0() {
    ((SymMatrix_nv_308de0*)this)->Call_002fca90();
    return (SymMatrix*)(this);
}


// 0x00308e00 FUN_00308e00 (9 B): matches/0x00308e00.cpp
// sym: ?FUN_00308e00@C_308e00@owners@@QAEXXZ
void owners::C_308e00::FUN_00308e00() {
    b = 0;
    a = 0;
}


// 0x00308e10 FUN_00308e10 (40 B): matches/0x00308e10.cpp
// sym: ?FUN_00308e10@C_308e10@owners@@QAE_NHE@Z
bool owners::C_308e10::FUN_00308e10(int index, unsigned char value) {
    bool result = false;
    if (index >= 0 && index < count) {
        items[index * 0x34 + 0x30] = value;
        result = true;
    }
    return result;
}

namespace fn_fa60db69 {

// 0x00308e40 FUN_00308e40 (269 B): equivalent/0x00308e40.cpp
// sym: ?FUN_00308e40@Object@fn_fa60db69@@QAEXPAU12@H@Z @748c36579f14 @w7856e3417f6e
// STATUS: equivalent (tools/equiv.py level 3: 609 inputs, branch coverage 8/8)
// FUN_00308e40 @ 0x00308e40
void Object::FUN_00308e40(Object* dest,int arg) {
 FUN_002f75d0(dest,arg);
 dest->count=count;
 if(count>0) {
  int n=count;
  unsigned int* allocation=(unsigned int*)FUN_0008d6d0((unsigned int)n*0x34+4);
  Entry_308e40* p=0;
  if(allocation) {
   p=(Entry_308e40*)(allocation+1);
   *allocation=n;
   FUN_00011520(p,0x34,n,FUN_00308de0);
  }
  dest->entries=p;
 }
 for(int i=0;i<count;++i) {
  dest->entries[i].FUN_002fd080();
  ((owners::V_2fcaf0 *)&(dest->entries[i]))->FUN_002fcaf0((owners::V_2fcaf0 *)(Entry_308e40 *)(&entries[i]));
  Entry_308e40* src=&entries[i];
  Entry_308e40* dst=&dest->entries[i];
  dst->x=src->x;
  dst->y=src->y;
  dst->z=src->z;
  dest->entries[i].a=entries[i].a;
  dest->entries[i].b=entries[i].b;
  dest->entries[i].flag=entries[i].flag;
 }
}

// 0x00308f50 physics::HairclubPhysicsObject::vfunc_5 (5 B): not yet verified

// 0x00308f60 physics::HairclubPhysicsObject::vfunc_7 (117 B): matches/0x00308f60.cpp
// sym: ?vfunc_7@HairclubPhysicsObject@fn_fa60db69@@UAEXXZ
void HairclubPhysicsObject::vfunc_7() {
    PhysicsObject::vfunc_7();
    for (int i = 0; i < count; i++) {
        float old = arr[i].a;
        arr[i].a = p18->scale * arr[i].b;
        if (old > 0.0f)
            ((owners::X_2fcb80 *)&(arr[i]))->FUN_002fcb80(arr[i].a / old);
    }
}


// 0x00308fe0 FUN_00308fe0 (864 B): equivalent/0x00308fe0.cpp
// sym: ?FUN_00308fe0@Hairclub@fn_fa60db69@@QAEXXZ @c65dfd66d8c3 @w73cbf0a6db82
// STATUS: equivalent (tools/equiv.py level 3: 440 inputs, branch coverage 18/18)
// FUN_00308fe0 @ 0x00308fe0
void Hairclub::FUN_00308fe0()
{
    if (!(f40 > 0.0f))
        return;

    Frame_308fe0 fr;
    center.z = 0;
    center.y = 0;
    center.x = 0;
    for (int i = 0; i < count; i++) {
        if (parts[i].mass > 0.0f && parts[i].active) {
            ((owners::Mat_22c2b0 *)&(body->mat))->FUN_0022c2b0((float *)(const V3_308fe0 *)(&parts[i].pos), (float *)(V3_308fe0 *)(&fr.a));
            float m = parts[i].mass;
            center.x = fr.a.x * m + center.x;
            center.y = fr.a.y * m + center.y;
            center.z = fr.a.z * m + center.z;
        }
    }

    center.Scale(f44);
    fr.b.Sub(center, *(const V3_308fe0 *)&body->mat.m[12]);
    fr.mt = mat;
    ((owners::M_22c0b0 *)&(fr.mt))->FUN_0022c0b0();
    ((owners::M_22c3b0 *)&(fr.mt))->FUN_0022c3b0((float *)(const V3_308fe0 *)(&fr.b), (float *)(V3_308fe0 *)(&va8));
    flagA4 = 0;

    fr.s2.FUN_002fca90();
    fr.s1.FUN_002fca90();
    ((owners::C_2fd0a0 *)&symF8)->FUN_002fd0a0();
    for (int i = 0; i < count; i++) {
        if (parts[i].mass > 0.0f && parts[i].active) {
            ((owners::Mat_22c2b0 *)&(body->mat))->FUN_0022c2b0((float *)(const V3_308fe0 *)(&parts[i].pos), (float *)(V3_308fe0 *)(&fr.a));
            fr.a.x = fr.a.x - center.x;
            fr.a.y = fr.a.y - center.y;
            fr.a.z = fr.a.z - center.z;
            FUN_00305b00(&fr.s2, &fr.a, parts[i].mass);
            fr.s1.m[0] = parts[i].inertia.m[0];
            fr.s1.m[1] = parts[i].inertia.m[1];
            fr.s1.m[2] = parts[i].inertia.m[2];
            fr.s1.m[3] = parts[i].inertia.m[3];
            fr.s1.m[4] = parts[i].inertia.m[4];
            fr.s1.m[5] = parts[i].inertia.m[5];
            fr.s1.FUN_002fcd60(body->GetRotation(i));
            ((owners::V_2fcaf0 *)&(fr.s2))->FUN_002fcaf0((owners::V_2fcaf0 *)(const SymMatrix *)(&fr.s1));
            ((owners::V_2fcaf0 *)&symF8)->FUN_002fcaf0((owners::V_2fcaf0 *)(const SymMatrix *)(&fr.s2));
        }
    }

    symDC.m[0] = symF8.m[0];
    symDC.m[1] = symF8.m[1];
    symDC.m[2] = symF8.m[2];
    symDC.m[3] = symF8.m[3];
    symDC.m[4] = symF8.m[4];
    symDC.m[5] = symF8.m[5];
    fr.mt = mat;
    ((owners::M_22c0b0 *)&(fr.mt))->FUN_0022c0b0();
    symDC.FUN_002fcd60(&fr.mt);
    ((owners::Sym3_2fd0c0 *)&sym114)->FUN_002fd0c0((const owners::Sym3_2fd0c0 *)(const SymMatrix *)(&symF8));
    ((owners::M_22c3b0 *)&mat)->FUN_0022c3b0((float *)(const V3_308fe0 *)(&vb4), (float *)(V3_308fe0 *)(&fr.a));
    center.x = fr.a.x + center.x;
    center.y = fr.a.y + center.y;
    center.z = fr.a.z + center.z;
    fr.s1.FUN_002fcaa0();
    fr.s2.FUN_002fcaa0();
}

} // namespace fn_fa60db69

// 0x003093b0 FUN_003093b0 (81 B): matches/0x003093b0.cpp [wrapped: conflict: HairclubPhysicsObject]
// sym: ?Destroy@HairclubPhysicsObject@fn_003093b0@@QAEXXZ
namespace fn_003093b0 {
extern "C" char DAT_00431d1c[];
struct SymMatrix_3093b0 {
    char pad[0x34];
    void Destroy_002fcaa0();
};
extern void __cdecl FreeArray_0008d340(void*);
struct HairclubPhysicsObject {
    void* vptr;
    char pad[0x1f4];
    SymMatrix_3093b0* items;
    void BaseDestroy_002f5640();
    void Destroy();
};
void HairclubPhysicsObject::Destroy() {
    SymMatrix_3093b0* p = items;
    vptr = (void*)((hulk_intptr)DAT_00431d1c);
    if (p) {
        int n = *((int*)p - 1);
        SymMatrix_3093b0* q = p + n;
        while (--n >= 0) {
            q--;
            q->Destroy_002fcaa0();
        }
        FreeArray_0008d340((char*)p - 4);
    }
    BaseDestroy_002f5640();
}
} // namespace fn_003093b0

namespace fn_fa60db69 {

// 0x00309410 FUN_00309410 (123 B): matches/0x00309410.cpp
// sym: ?FUN_00309410@HairclubPhysicsObject_309410@fn_fa60db69@@QAEXXZ
// FUN_00309410 @ 0x00309410
void HairclubPhysicsObject_309410::FUN_00309410() {
    sumX = 0;
    sumY = 0;
    for (int i = 0; i < partCount; i++) {
        Part_309410 *p = &parts[i];
        if (p->active) {
            sumX = p->x + sumX;
            sumY = p->y + sumY;
        }
    }
    if (sumY > 0.0f) {
        invSumY = 1.0f / sumY;
    } else {
        controller->FUN_002ef8b0(0);
    }
    FUN_00308fe0();
}

// 0x00309490 thunk_FUN_00309410 (5 B): not yet verified
} // namespace fn_fa60db69

// 0x003094a0 physics::HairclubPhysicsObject::vfunc_28 (83 B): matches/0x003094a0.cpp
// sym: ?vfunc_28@HairclubPhysicsObject@physics@@UAEPAXI@Z
void* physics::HairclubPhysicsObject::vfunc_28(unsigned int arg) {
    void* q = alloc_00263ea0(0x200);
    void* p;
    if (q) {
        p = q;
        ((Obj_3094a0*)p)->init_002f5480();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00431d1c);
        *(u32_3094a0*)((char*)p + 0x1f8) = 0;
        *(u32_3094a0*)((char*)p + 0x24) = 2;
    } else
        p = 0;
    ((HairclubPhysicsObject_nv_3094a0*)this)->build_00308e40(p, arg);
    *(u32_3094a0*)((char*)p + 0x24) = *(u32_3094a0*)((char*)this + 0x24);
    return (void*)(p);
}


// 0x00309500 physics::HairclubPhysicsObject::vfunc_2 (30 B): matches/0x00309500.cpp
// sym: ??_GHairclubPhysicsObject@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::HairclubPhysicsObject::~HairclubPhysicsObject() {}


// 0x00309520 FUN_00309520 (337 B): equivalent/0x00309520.cpp [wrapped: conflict: physics::HairclubPhysicsObject; physics::PhysicsObject]
// sym: ??0HairclubPhysicsObject@physics@fn_00309520@@QAE@HPAPAUSource_309520@2@H@Z @59971542d476 @we383658705d7
namespace fn_00309520 {
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 16/16)
// FUN_00309520 @ 0x00309520
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

struct Vec3_309520 {
    float x, y, z;
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90();
    void FUN_002fd080();
    void FUN_002fcaf0(const SymMatrix *src);
};

struct Part_309520 {
    SymMatrix inertia;
    Vec3_309520 pos;
    float mass;
    float massBits;
    unsigned char active;
    char pad31[3];
};

struct Source_309520 {
    char pad0[0x34];
    float mass;
    char pad38[0x48 - 0x38];
    SymMatrix inertia;
    char pad64[0x80 - 0x64];
    Vec3_309520 pos;
};

struct Settings_309520 {
    char pad0[0xc];
    float massScale;
};

namespace physics {

class __declspec(novtable) PhysicsObject {
public:
    virtual void vfunc_0_00038290();
    virtual void vfunc_1_000382a0();
    virtual void vfunc_2();
    virtual void vfunc_3_0027afe0();
    virtual void vfunc_4_0027aff0();
    virtual void vfunc_5();
    virtual void vfunc_6_002f56b0(char);
    virtual void vfunc_7_00308f60();
    virtual void vfunc_8_002f5860();
    virtual void vfunc_9_002f55b0(int);
    virtual void vfunc_10_002f55e0();
    virtual void vfunc_11_002f55d0();
    virtual bool vfunc_12_002f58e0(int);
    virtual void vfunc_13_002f59f0();
    virtual void vfunc_14_002f60d0();
    virtual void vfunc_15_002f6150();
    virtual void vfunc_16();
    virtual void vfunc_17_002f55f0(int, int, int, int, int);
    virtual bool vfunc_18_002f5c70(hulk_intptr, hulk_intptr, int, int, int, int);
    virtual void vfunc_19_002f5db0(int, int, int);
    virtual void vfunc_20_002f5ec0(void*, void*, int, int, int);
    virtual void vfunc_21_002f5630();
    virtual void vfunc_22_002fe6e0(int, int, int, int, int, int);
    virtual void vfunc_23_002f5580(int, int);
    virtual bool vfunc_24_002f5590(hulk_intptr, hulk_intptr, int);
    virtual bool vfunc_25_002f5d20(void*, int, int);
    virtual char vfunc_26_002f5600(int);
    virtual void vfunc_27_002f5360(int);
    virtual void* vfunc_28_003094a0(int);
    virtual void vfunc_29_002f55a0(int);
    virtual void vfunc_30();
    virtual void vfunc_31_002f5f60();
    virtual void vfunc_32_002f5ac0(hulk_intptr, hulk_intptr);
    virtual void vfunc_33_002f5b90(hulk_intptr);
    virtual bool vfunc_34_002f5610(void*);
    virtual void vfunc_35_00309680(float);
    virtual void vfunc_36_002f5620();
    virtual void vfunc_37_002f5c40();
    virtual void vfunc_38_002f6af0(float);
    virtual void vfunc_39_002f5be0();
    char pad04[0xc];
    int hook;
    char pad14[4];
    Settings_309520 *settings;
    char pad1c[8];
    int mode;
    char pad28[0x10];
    float totalMass;
    char pad3c[0x1f8 - 0x3c];
    void FUN_002f65f0(int a);
    PhysicsObject(int a) throw() { FUN_002f65f0(a); }
};

class HairclubPhysicsObject : public PhysicsObject {
public:
    Part_309520 *parts;
    int count;
    void FUN_00309410();
    HairclubPhysicsObject(hulk_intptr a, Source_309520 **sources, int n) throw();
};

HairclubPhysicsObject::HairclubPhysicsObject(hulk_intptr a, Source_309520 **sources, int n) throw() : PhysicsObject(a)
{
    parts = 0;
    count = n;
    mode = 2;
    Part_309520 *arr = 0;
    int *mem = (int *)FUN_0008d6d0(n * sizeof(Part_309520) + 4);
    if (mem) {
        *mem = n;
        arr = (Part_309520 *)(mem + 1);
        for (int i = 0; i < n; i++)
            arr[i].inertia.FUN_002fca90();
    }
    parts = arr;
    for (int i = 0; i < count; i++) {
        parts[i].inertia.FUN_002fd080();
        parts[i].inertia.FUN_002fcaf0(&sources[i]->inertia);
        parts[i].pos = sources[i]->pos;
        parts[i].mass = sources[i]->mass * settings->massScale;
        parts[i].massBits = sources[i]->mass;
        parts[i].active = 1;
    }
    for (int i = 0; i < count; i++)
        totalMass = parts[i].massBits + totalMass;
    if (hook != 0)
        FUN_00309410();
}

}
} // namespace fn_00309520


// 0x00309680 physics::HairclubPhysicsObject::vfunc_35 (256 B): equivalent/0x00309680.cpp
// sym: ?vfunc_35@HairclubPhysicsObject@physics@@UAEXM@Z @16e85325c30d @wcf338c19200a
// STATUS: equivalent (tools/equiv.py level 3: 61 inputs, branch coverage 25/26, incomplete)
// physics::HairclubPhysicsObject::vfunc_35 @ 0x00309680
void physics::HairclubPhysicsObject::vfunc_35(float value) {
 double total = 0.0f;
 int n = this->f_1fc;
 for (int i=0;i<n;++i) {
  if ((*(Strand * *)&this->f_1f8)[i].active) total += (*(Strand * *)&this->f_1f8)[i].weight;
 }
 if (total > 0.0f) {
  value = (float)(value / total);
  if(n > 0) {
   for(int i=0;i<this->f_1fc;++i) {
    Strand* s = &(*(Strand * *)&this->f_1f8)[i];
    if(s->active) {
     s->weight = s->weight * value;
     ((owners::X_2fcb80 *)s)->FUN_002fcb80(value);
    }
   }
  }
 }
 ((HairclubPhysicsObject_nv_309680*)this)->FUN_00309410();
}

