// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022a8e0..0x0022a980 (kind game, layer engine, confidence high), dominant class choreo2::Driver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/choreo2.h"
#include "gen/choreo2.h"
#define TREE_TU_BEGIN namespace fn_f92753c8 {
#define TREE_TU_END }
namespace fn_f92753c8 {} using namespace fn_f92753c8;
namespace fn_f92753c8 { extern "C" char DAT_004274d8[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f92753c8 {
struct Driver_nv_22a8e0 {
    void Init_0027b070();
};
extern int hulk_at_004274d8;
class Driver_22a8e0 {
  public:
    int* mVtable;
};
extern int vtable_22a910;
extern "C" void __fastcall FUN_0027afd0(void*);
struct Driver {
    int* vptr;
};
extern void* g_vftable_22a950[];
} // namespace fn_f92753c8
void operator delete(void*);
namespace fn_f92753c8 {
class Entity_22a950 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class Driver_22a950 : public Entity_22a950 {
  public:
    Driver_22a950* f2(unsigned char flags);
};


// 0x0022a8e0 FUN_0022a8e0 (44 B): matches/0x0022a8e0.cpp
// sym: @FUN_0022a8e0@4
// data: gCount_22a8e0 = DAT_004e5abc
extern "C" Driver_22a8e0* __fastcall FUN_0022a8e0(Driver_22a8e0* self) {
    ((Driver_nv_22a8e0*)(((choreo2::Driver*)(self))))->Init_0027b070();
    self->mVtable = &hulk_at_004274d8;
    ++(*(int*)&DAT_004e5abc);
    if ((*(int*)&DAT_004e5abc) <= (*(int*)&DAT_004e5ac0))
        return self;
    (*(int*)&DAT_004e5ac0) = (*(int*)&DAT_004e5abc);
    return self;
}


// 0x0022a910 FUN_0022a910 (17 B): matches/0x0022a910.cpp
// sym: ?target@fn_f92753c8@@YIXPAUDriver@1@@Z
// data: g_count_22a910 = DAT_004e5abc
void __fastcall target(Driver* self) {
    self->vptr = &vtable_22a910;
    --(*(int*)&DAT_004e5abc);
    FUN_0027afd0((void*)(self));
}

} // namespace fn_f92753c8

// 0x0022a930 choreo2::Driver::vfunc_6 (5 B): matches/0x0022a930.cpp
// sym: ?vfunc_6@Driver@choreo2@@UAEXXZ
void choreo2::Driver::vfunc_6() {
    vfunc_5();
}


// 0x0022a940 choreo2::Driver::vfunc_12 (5 B): matches/0x0022a940.cpp
// sym: ?vfunc_12@Driver@choreo2@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool choreo2::Driver::vfunc_12(hulk_intptr , hulk_intptr ) {
    return false;
}

namespace fn_f92753c8 {

// 0x0022a950 choreo2::Driver::vfunc_2 (44 B): matches/0x0022a950.cpp
// sym: ?f2@Driver_22a950@fn_f92753c8@@QAEPAV12@E@Z
// data: g_count_22a950 = DAT_004e5abc
Driver_22a950* Driver_22a950::f2(unsigned char flags) {
    vptr = ((void**)DAT_004274d8);
    _ReadWriteBarrier();
    (*(int*)&DAT_004e5abc)--;
    Fin_0027afd0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f92753c8
