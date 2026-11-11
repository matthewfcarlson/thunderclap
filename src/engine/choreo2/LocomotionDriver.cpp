// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022a980..0x0022aa50 (kind game, layer engine, confidence medium), dominant class choreo2::LocomotionDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/choreo2.h"
#include "gen/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f877d14e {
#define TREE_TU_END }
namespace fn_f877d14e {} using namespace fn_f877d14e;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f877d14e {
struct PartitionDriver_22a980 {
    void Init_002223f0(int);
};
struct LocomotionDriver : PartitionDriver_22a980 {
    hulk_intptr vptr;
    char pad[0x1b];
    int a;
    int b;
    LocomotionDriver* Init(int);
};
extern int hulk_at_00427534;
struct LocomotionDriver_nv_22a9c0 {
    void cleanup_002222d0();
};
struct Driver_22a9c0 {
    int* vptr;
};


// 0x0022a980 FUN_0022a980 (59 B): matches/0x0022a980.cpp
// sym: ?Init@LocomotionDriver@fn_f877d14e@@QAEPAU12@H@Z
// data: gCount_22a980 = DAT_004e5ac4, gHigh_22a980 = DAT_004e5ac8
LocomotionDriver* LocomotionDriver::Init(int x) {
    PartitionDriver_22a980::Init_002223f0(x);
    a = 0;
    b = 0;
    vptr = ((hulk_intptr)DAT_00427534);
    int n = ++(*(int*)&DAT_004e5ac4);
    if (n > (*(int*)&DAT_004e5ac8))
        (*(int*)&DAT_004e5ac8) = n;
    return this;
}


// 0x0022a9c0 FUN_0022a9c0 (17 B): matches/0x0022a9c0.cpp
// sym: @FUN_0022a9c0@4
// Same code shape as 0x0022a910 (propagated; names are from that function)
// data: g_count_22a9c0 = DAT_004e5ac4
extern "C" void __fastcall FUN_0022a9c0(Driver_22a9c0* self) {
    self->vptr = &hulk_at_00427534;
    --(*(int*)&DAT_004e5ac4);
    ((LocomotionDriver_nv_22a9c0*)(((choreo2::LocomotionDriver*)(((choreo2::LocomotionDriver*)(self))))))->cleanup_002222d0();
}

} // namespace fn_f877d14e

// 0x0022a9e0 FUN_0022a9e0 (33 B): matches/0x0022a9e0.cpp
// sym: ?FUN_0022a9e0@Thing_22a9e0@owners@@QAEPAU12@PAU12@@Z
owners::Thing_22a9e0* owners::Thing_22a9e0::FUN_0022a9e0(owners::Thing_22a9e0* other) {
    FUN_00222460(other);
    a = other->a;
    b = other->b;
    return this;
}


// 0x0022aa10 choreo2::LocomotionDriver::vfunc_13 (3 B): matches/0x0022aa10.cpp
// sym: ?vfunc_13@LocomotionDriver@choreo2@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char choreo2::LocomotionDriver::vfunc_13() {
    return 0;
}


// 0x0022aa20 choreo2::LocomotionDriver::vfunc_2 (44 B): matches/0x0022aa20.cpp [wrapped: conflict: LocomotionDriver]
// sym: ?vfunc_2@LocomotionDriver@fn_0022aa20@@UAEPAV12@H@Z
namespace fn_0022aa20 {
// data: g_count_22aa20 = DAT_004e5ac4

extern "C" char DAT_00427534[];
class LocomotionDriver_22aa20 {
  public:
    void Fn_002222d0();
};
class LocomotionDriver {
  public:
    virtual void f0();
    virtual void f1();
    virtual LocomotionDriver* vfunc_2(int);
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
};
extern void __cdecl thunk_FUN_00267090(LocomotionDriver*);
LocomotionDriver* LocomotionDriver::vfunc_2(int flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_00427534);
    (*(int*)&DAT_004e5ac4)--;
    ((LocomotionDriver_22aa20*)this)->Fn_002222d0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0022aa20

