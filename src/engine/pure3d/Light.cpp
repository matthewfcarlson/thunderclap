// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a0720..0x002a0b00 (kind game, layer engine, confidence high), dominant class pure3d::Light
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fc62e156 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fc62e156 {} using namespace fn_fc62e156;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace pure3d {
class Entity_2a0740 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_fc62e156 {
class LoadObject_2a0750 {
  public:
    virtual void v0();
    virtual void v1();
};
struct Manager_2a0770 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38(int, int);
};
extern Manager_2a0770* gManager_2a0770;
class C_2a07a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int);
    int x[4];
    int m;
    void target(int);
};
class C_2a0820 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int);
    char pad[0x11 - 4];
    unsigned char field;
    void target(unsigned char);
};
extern void* Entity_2a0ad0_vftable[];
class Entity_2a0ad0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class Light_2a0ad0 : public Entity_2a0ad0 {
  public:
    Light_2a0ad0* vfunc_5(signed char flags);
};


// 0x002a0720 FUN_002a0720 (11 B): matches/0x002a0720.cpp
// sym: @FUN_002a0720@4
// Same code shape as 0x00060920 (propagated; names are from that function)
extern "C" void __fastcall FUN_002a0720(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_0027afd0(self);
}

} // namespace fn_fc62e156

// 0x002a0730 pure3d::Light::vfunc_3 (3 B): matches/0x002a0730.cpp
// sym: ?vfunc_3@Light@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::Light::vfunc_3() {
    return (bool)(0);
}


// 0x002a0740 pure3d::Light::vfunc_4 (3 B): matches/0x002a0740.cpp
// sym: ?vfunc_4@Light@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::Light::vfunc_4() {
    return (void*)(this);
}


// 0x002a0750 pure3d::Light::vfunc_5 (24 B): matches/0x002a0750.cpp
// sym: ?vfunc_5@Light@pure3d@@UAEXH@Z
 // namespace pure3d
void pure3d::Light::vfunc_5(int x) {
    this->f_10 = 1;
    this->f_24 = x;
    vfunc_9(1);
}


// 0x002a0770 pure3d::Light::vfunc_6 (41 B): matches/0x002a0770.cpp
// sym: ?vfunc_6@Light@pure3d@@UAEXXZ
void pure3d::Light::vfunc_6() {
    if (this->f_24 != -1) {
        gManager_2a0770->f38(this->f_24, 0);
        this->f_10 = 0;
        this->f_24 = -1;
    }
}

namespace fn_fc62e156 {

// 0x002a07a0 FUN_002a07a0 (20 B): matches/0x002a07a0.cpp
// sym: ?target@C_2a07a0@fn_fc62e156@@QAEXH@Z
void C_2a07a0::target(int a) {
    m = a;
    f9(0);
}

} // namespace fn_fc62e156

// 0x002a07c0 pure3d::Light::vfunc_8 (25 B): matches/0x002a07c0.cpp
// sym: ?vfunc_8@Light@pure3d@@UAEXPAX@Z
void pure3d::Light::vfunc_8(void* __p0) { int * p = (int *)__p0;

    vfunc_7(p[0], p[1], p[2]);
}


// 0x002a07e0 pure3d::Light::vfunc_7 (24 B): matches/0x002a07e0.cpp
// sym: ?vfunc_7@Light@pure3d@@UAEXHHH@Z
void pure3d::Light::vfunc_7(int x, int y, int z) {
    this->f_18 = x;
    this->f_1c = y;
    this->f_20 = z;
}


// 0x002a0800 FUN_002a0800 (30 B): matches/0x002a0800.cpp
// sym: ?FUN_002a0800@Obj_2a0800@owners@@QAEXPAH00@Z
void owners::Obj_2a0800::FUN_002a0800(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}

namespace fn_fc62e156 {

// 0x002a0820 FUN_002a0820 (20 B): matches/0x002a0820.cpp
// sym: ?target@C_2a0820@fn_fc62e156@@QAEXE@Z
void C_2a0820::target(unsigned char x) {
    field = x;
    f9(0);
}

} // namespace fn_fc62e156

// 0x002a0840 FUN_002a0840 (10 B): matches/0x002a0840.cpp
// sym: ?FUN_002a0840@Obj_2a0840@owners@@QAEXH@Z
void owners::Obj_2a0840::FUN_002a0840(int v) {
    m2c = v;
}


// 0x002a0850 FUN_002a0850 (4 B): matches/0x002a0850.cpp
// sym: ?FUN_002a0850@C_2a0850@owners@@QAEIXZ
// Same code shape as 0x000862b0 (propagated; names are from that function)
unsigned int owners::C_2a0850::FUN_002a0850() {
    return *(unsigned int*)((char*)this + 0x2c);
}

namespace fn_fc62e156 {

// 0x002a0870 FUN_002a0870 (4 B): matches/0x002a0870.cpp
// sym: ?FUN@fn_fc62e156@@YIPAHPAXH@Z
// Same code shape as 0x001c39c0 (propagated; names are from that function)
int* __fastcall FUN(void* p, int) {
    return (int*)((char*)p + 0x3c);
}

} // namespace fn_fc62e156

// 0x002a08c0 FUN_002a08c0 (21 B): matches/0x002a08c0.cpp
// sym: ?FUN_002a08c0@Obj_2a08c0@owners@@QAEXM@Z
void owners::Obj_2a08c0::FUN_002a08c0(float x) {
    s = (float)sin(x);
    c = (float)cos(x);
}


// 0x002a08f0 FUN_002a08f0 (10 B): matches/0x002a08f0.cpp
// sym: ?FUN_002a08f0@Obj_2a08f0@owners@@QAEXH@Z
void owners::Obj_2a08f0::FUN_002a08f0(int v) {
    field = v;
}


// 0x002a0a70 FUN_002a0a70 (89 B): equivalent/0x002a0a70.cpp [wrapped: conflict: pure3d::Light]
// sym: ??0Light@pure3d@fn_002a0a70@@QAE@XZ
namespace fn_002a0a70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002a0a70 @ 0x002a0a70
namespace pure3d {
struct Light;
struct Base {
    Base(Light* owner);
};
struct Light : Base {
    virtual void virtualFunction();
    void FUN_0027b070();
    char padding[12];
    unsigned char enabled;
    unsigned char visible;
    unsigned char flag2;
    unsigned char flag3;
    unsigned int color;
    unsigned int value18;
    unsigned int value1c;
    float intensity;
    unsigned int invalid24;
    unsigned int unknown28;
    unsigned int values[8];
    float scale;
    unsigned int value50;
    unsigned int invalid54;
    Light();
};
inline Base::Base(Light* owner) { owner->FUN_0027b070(); }
Light::Light() : Base(this) {
    enabled = 0;
    flag2 = 0;
    flag3 = 0;
    visible = 1;
    color = 0xffffffff;
    value18 = 0;
    value1c = 0;
    intensity = 1.0f;
    invalid24 = 0xffffffff;
    for (int i = 0; i < 8; ++i) values[i] = 0;
    scale = 1.0f;
    value50 = 0;
    invalid54 = 0xffffffff;
}
}
} // namespace fn_002a0a70

namespace fn_fc62e156 {

// 0x002a0ad0 pure3d::Light::vfunc_2 (36 B): matches/0x002a0ad0.cpp
// sym: ?vfunc_5@Light_2a0ad0@fn_fc62e156@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Light_2a0ad0* Light_2a0ad0::vfunc_5(signed char flags) {
    *(void***)this = Entity_2a0ad0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fc62e156
