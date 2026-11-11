// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a1230..0x002a1310 (kind game, layer engine, confidence medium), dominant class pure3d::AmbientLight
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f43aa70d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f43aa70d {} using namespace fn_f43aa70d;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f43aa70d {
class AmbientLight {
  public:
    virtual void v0();
    char pad[0x50];
    int field;
    void Init_002a0a70();
    AmbientLight* Build();
};
extern void* hulk_at_0042d6c8;
class Dispatch_2a1280 {
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
    virtual void f35(int);
};
extern Dispatch_2a1280* hulk_at_0052c2a8;
extern void* Light_2a12a0_vftable[];
class Light_2a12a0 {
  public:
    void Destroy_002a0720(); // FUN_00236d60, __thiscall, this in ecx
};
class AmbientLight_2a12a0 : public Light_2a12a0 {
  public:
    AmbientLight_2a12a0* vfunc_5(signed char flags);
};


// 0x002a1230 FUN_002a1230 (25 B): matches/0x002a1230.cpp
// sym: ?Build@AmbientLight@fn_f43aa70d@@QAEPAV12@XZ
AmbientLight* AmbientLight::Build() {
    Init_002a0a70();
    *(void**)this = &hulk_at_0042d6c8;
    field = 0;
    return this;
}

} // namespace fn_f43aa70d

// 0x002a1280 pure3d::AmbientLight::vfunc_9 (23 B): matches/0x002a1280.cpp
// sym: ?vfunc_9@AmbientLight@pure3d@@UAEXH@Z
void pure3d::AmbientLight::vfunc_9(int x) {
    return hulk_at_0052c2a8->f35(this->f_14);
}

namespace fn_f43aa70d {

// 0x002a12a0 pure3d::AmbientLight::vfunc_2 (36 B): matches/0x002a12a0.cpp
// sym: ?vfunc_5@AmbientLight_2a12a0@fn_f43aa70d@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
AmbientLight_2a12a0* AmbientLight_2a12a0::vfunc_5(signed char flags) {
    *(void***)this = Light_2a12a0_vftable;
    Destroy_002a0720();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f43aa70d
