// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023d220..0x0023d420 (kind game, layer engine, confidence high), dominant class fight::FalseCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1fd5fb3 {
#define TREE_TU_END }
namespace fn_f1fd5fb3 {} using namespace fn_f1fd5fb3;
namespace fn_f1fd5fb3 { extern "C" char DAT_00428ad0[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f1fd5fb3 {
class ConditionFactoryCasterTemplate_23d220 {
  public:
    virtual bool Cast_0023d030(void*);
};
class Obj {
  public:
    void Apply_00236760(void*);
};
extern "C" void* Get(void*, ConditionFactoryCasterTemplate_23d220*);
class ConditionFactoryCasterTemplate_23d250 {
  public:
    virtual bool Cast_0023d070(void*);
};
class Handler {
  public:
    void Set_00236760(void*);
};
extern "C" void* __cdecl FUN_002343e0(void*, ConditionFactoryCasterTemplate_23d250*);
} // namespace fn_f1fd5fb3
namespace fight {
class Condition_23d2e0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
}
namespace fight {
class Param_23d2e0 {
  public:
    virtual void pvfunc_0();
    virtual void pvfunc_1();
};
}
namespace fn_f1fd5fb3 {
extern void* hulk_at_00428ad0[];
class Condition_23d2f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class FalseCondition_23d2f0 : public Condition_23d2f0 {
  public:
    FalseCondition_23d2f0* vfunc_5(signed char flags);
};
extern "C" void __cdecl FUN_0008d330(void* p);
extern int hulk_at_00491ca8;
extern "C" char DAT_00428afc[];
class Sub_23d360 {
  public:
};
class Obj_23d360 {
  public:
    void Init_002343b0();
    char pad[8];
    Sub_23d360 sub;
};
extern void* __cdecl alloc_00263ea0(unsigned int);
class FactoryBase {
  public:
    virtual void V0();
    virtual void* V1(void*);
};
class Caster_23d360 : public FactoryBase {
  public:
    char pad[4];
};
struct CIsGrappledCondition_23d3a0 {
    virtual ~CIsGrappledCondition_23d3a0();
    void init_00234590(int);
};
extern void* condition_vftable_23d3a0;
extern void* hulk_at_00428afc[];
class ConditionFactory_23d3d0 {
  public:
    void Destroy_002343d0(); // FUN_00236d60, __thiscall, this in ecx
};
class ConditionFactoryTemplate_23d3d0 : public ConditionFactory_23d3d0 {
  public:
    ConditionFactoryTemplate_23d3d0* vfunc_5(signed char flags);
};


// 0x0023d220 FUN_0023d220 (38 B): matches/0x0023d220.cpp
// sym: _FUN_0023d220
extern "C" void FUN_0023d220(Obj* obj, void* x) {
    ConditionFactoryCasterTemplate_23d220 caster;
    void* p = Get(x, &caster);
    obj->Apply_00236760(p);
}


// 0x0023d250 FUN_0023d250 (38 B): matches/0x0023d250.cpp
// sym: _FUN_0023d250
extern "C" void __cdecl FUN_0023d250(Handler* h, void* p) {
    ConditionFactoryCasterTemplate_23d250 caster;
    void* v = FUN_002343e0(p, &caster);
    h->Set_00236760(v);
}

} // namespace fn_f1fd5fb3

// 0x0023d2a0 fight::FalseCondition::vfunc_0 (5 B): matches/0x0023d2a0.cpp [wrapped: conflict: fight::Condition; fight::Param]
// sym: ?vfunc_0@FalseCondition_23d2a0@fn_0023d2a0@@UAEHH@Z
namespace fn_0023d2a0 {
// Same code shape as 0x00049c80 (propagated; names are from that function)
class Condition_23d2a0 {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class FalseCondition_23d2a0 : public Condition_23d2a0, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int FalseCondition_23d2a0::vfunc_0(int) {
    return 0;
}
} // namespace fn_0023d2a0


// 0x0023d2e0 fight::FalseCondition::vfunc_6 (5 B): matches/0x0023d2e0.cpp
// sym: ?vfunc_6@FalseCondition@fight@@UAE_NPAX00@Z
 // namespace fight
bool fight::FalseCondition::vfunc_6(void* __p0, void* __p1, void* __p2) {
    return false;
}

namespace fn_f1fd5fb3 {

// 0x0023d2f0 fight::FalseCondition::vfunc_5 (36 B): matches/0x0023d2f0.cpp
// sym: ?vfunc_5@FalseCondition_23d2f0@fn_f1fd5fb3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
FalseCondition_23d2f0* FalseCondition_23d2f0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00428ad0;
    Destroy_002345b0();
    if (flags & 1) {
        FUN_0008d330(this);
    }
    return this;
}

} // namespace fn_f1fd5fb3

// 0x0023d330 fight::ConditionFactoryCasterTemplate<fight::FalseCondition>::vfunc_0 (36 B): matches/0x0023d330.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VFalseCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::FalseCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023d360 fight::ConditionFactoryCasterTemplate<fight::FalseCondition>::vfunc_1 (55 B): matches/0x0023d360.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VFalseCondition@fight@@@fight@@UAEPAXPAX@Z
template <> void* fight::ConditionFactoryCasterTemplate<fight::FalseCondition>::vfunc_1(void* __p0) { void * a = (void *)__p0;

    Obj_23d360* p = (Obj_23d360*)alloc_00263ea0(16);
    if (p) {
        p->Init_002343b0();
        *((void**)p) = (void*)((hulk_intptr)DAT_00428afc);
        ((owners::Target_27b040 *)&(p->sub))->FUN_0027b040((hulk_uintptr)a);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0023d3a0 fight::ConditionFactoryTemplate<fight::FalseCondition>::vfunc_5 (40 B): matches/0x0023d3a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VFalseCondition@fight@@@fight@@UAEPAXXZ
// Same code shape as 0x00052580 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<fight::FalseCondition>::vfunc_5() {
    CIsGrappledCondition_23d3a0* p = (CIsGrappledCondition_23d3a0*)operator new(0x0c);
    if (p) {
        p->init_00234590(0);
        *(void**)p = ((void**)DAT_00428ad0);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1fd5fb3 {

// 0x0023d3d0 fight::ConditionFactoryTemplate<fight::FalseCondition>::vfunc_2 (36 B): matches/0x0023d3d0.cpp
// sym: ?vfunc_5@ConditionFactoryTemplate_23d3d0@fn_f1fd5fb3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ConditionFactoryTemplate_23d3d0* ConditionFactoryTemplate_23d3d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00428afc;
    Destroy_002343d0();
    if (flags & 1) {
        FUN_00263f30(this);
    }
    return this;
}

} // namespace fn_f1fd5fb3
