// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023cf00..0x0023d220 (kind game, layer engine, confidence high), dominant class fight::OrCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f787eff2 {
#define TREE_TU_END }
namespace fn_f787eff2 {} using namespace fn_f787eff2;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f787eff2 {
extern void* Condition_23cfc0_vftable[];
class Condition_23cfc0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class NotCondition_23cfc0 : public Condition_23cfc0 {
  public:
    NotCondition_23cfc0* vfunc_5(signed char flags);
};
extern "C" void __cdecl FUN_0008d330(void* p);
extern void* Condition_23cff0_vftable[];
class Condition_23cff0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class OrCondition_23cff0 : public Condition_23cff0 {
  public:
    OrCondition_23cff0* vfunc_5(signed char flags);
};
extern int gTypeA_23d030;
extern int gTypeA_23d070;
extern "C" char DAT_00428a24[];
typedef unsigned int u32_23d0e0;
struct NotCondition_23d0e0 {
    virtual void a();
    virtual void b();
    virtual void c();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_23d0e0 {
    void f(int);
};
extern void* ConditionFactory_23d110_vftable[];
class ConditionFactory_23d110 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class ConditionFactoryTemplate_23d110 : public ConditionFactory_23d110 {
  public:
    ConditionFactoryTemplate_23d110* vfunc_5(signed char flags);
};
extern "C" char DAT_00428a98[];
class ConditionFactoryCaster_23d140 {
  public:
    virtual void A();
    virtual void B();
};
class Helper_23d140 {
  public:
    void Init();
};
extern "C" void* __cdecl alloc(hulk_uintptr);
extern "C" char DAT_00428a44[];
typedef unsigned int u32_23d180;
struct Init_23d180 {
    void init(int);
};
extern void* ConditionFactory_23d1b0_vftable[];
class ConditionFactory_23d1b0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class ConditionFactoryTemplate_23d1b0 : public ConditionFactory_23d1b0 {
  public:
    ConditionFactoryTemplate_23d1b0* vfunc_5(signed char flags);
};

} // namespace fn_f787eff2

// 0x0023cf00 fight::NotCondition::vfunc_0 (5 B): matches/0x0023cf00.cpp [wrapped: conflict: fight::Condition; fight::Param]
// sym: ?vfunc_0@NotCondition_23cf00@fn_0023cf00@@UAEHH@Z
namespace fn_0023cf00 {
// Same code shape as 0x00049c80 (propagated; names are from that function)
class Condition_23cf00 {
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
class NotCondition_23cf00 : public Condition_23cf00, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int NotCondition_23cf00::vfunc_0(int) {
    return 0;
}
} // namespace fn_0023cf00


// 0x0023cf60 fight::OrCondition::vfunc_0 (5 B): matches/0x0023cf60.cpp [wrapped: conflict: fight::Condition; fight::Param]
// sym: ?vfunc_0@OrCondition_23cf60@fn_0023cf60@@UAEHH@Z
namespace fn_0023cf60 {
// Same code shape as 0x00049c80 (propagated; names are from that function)
class Condition_23cf60 {
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
class OrCondition_23cf60 : public Condition_23cf60, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int OrCondition_23cf60::vfunc_0(int) {
    return 0;
}
} // namespace fn_0023cf60


// 0x0023cfa0 fight::OrCondition::vfunc_6 (5 B): matches/0x0023cfa0.cpp
// sym: ?vfunc_6@OrCondition@fight@@UAE_NPAX00@Z
// Same code shape as 0x0012fb00 (propagated; names are from that function)
bool fight::OrCondition::vfunc_6(void* __p0, void* __p1, void* __p2) {
    return true;
}


// 0x0023cfb0 fight::NotCondition::vfunc_6 (5 B): matches/0x0023cfb0.cpp
// sym: ?vfunc_6@NotCondition@fight@@UAE_NPAX00@Z
// Same code shape as 0x0012fb00 (propagated; names are from that function)
bool fight::NotCondition::vfunc_6(void* __p0, void* __p1, void* __p2) {
    return true;
}

namespace fn_f787eff2 {

// 0x0023cfc0 fight::NotCondition::vfunc_5 (36 B): matches/0x0023cfc0.cpp
// sym: ?vfunc_5@NotCondition_23cfc0@fn_f787eff2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
NotCondition_23cfc0* NotCondition_23cfc0::vfunc_5(signed char flags) {
    *(void***)this = Condition_23cfc0_vftable;
    Destroy();
    if (flags & 1) {
        FUN_0008d330(this);
    }
    return this;
}


// 0x0023cff0 fight::OrCondition::vfunc_5 (36 B): matches/0x0023cff0.cpp
// sym: ?vfunc_5@OrCondition_23cff0@fn_f787eff2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
OrCondition_23cff0* OrCondition_23cff0::vfunc_5(signed char flags) {
    *(void***)this = Condition_23cff0_vftable;
    Destroy();
    if (flags & 1) {
        FUN_0008d330(this);
    }
    return this;
}

} // namespace fn_f787eff2

// 0x0023d030 fight::ConditionFactoryCasterTemplate<fight::NotCondition>::vfunc_0 (36 B): matches/0x0023d030.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VNotCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::NotCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_23d030, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023d070 fight::ConditionFactoryCasterTemplate<fight::OrCondition>::vfunc_0 (36 B): matches/0x0023d070.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VOrCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::OrCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_23d070, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023d0a0 fight::ConditionFactoryCasterTemplate<fight::NotCondition>::vfunc_1 (55 B): matches/0x0023d0a0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?V1@ConditionFactoryCasterTemplate@fn_0023d0a0@@UAEPAV12@H@Z
namespace fn_0023d0a0 {
extern "C" char DAT_00428a7c[];
class ConditionFactoryCaster {
  public:
    virtual void V0();
    virtual void V1();
};
class BaseAllocated {
  public:
    void Init();
};
class Elem_23d0a0 {
  public:
};
extern "C++" __declspec(nothrow) void* __cdecl alloc(hulk_uintptr);
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual void V0();
    virtual ConditionFactoryCasterTemplate* V1(int);
};
void ConditionFactoryCasterTemplate::V0() {}
ConditionFactoryCasterTemplate* ConditionFactoryCasterTemplate::V1(int x) {
    BaseAllocated* p = (BaseAllocated*)alloc(0x10);
    if (p) {
        p->Init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00428a7c);
        ((owners::Target_27b040 *)(((Elem_23d0a0*)((char*)p + 8))))->FUN_0027b040((hulk_uintptr)x);
        return (ConditionFactoryCasterTemplate*)p;
    }
    return 0;
}
} // namespace fn_0023d0a0


// 0x0023d0e0 fight::ConditionFactoryTemplate<fight::NotCondition>::vfunc_5 (40 B): matches/0x0023d0e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VNotCondition@fight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<fight::NotCondition>::vfunc_5() {
    NotCondition_23d0e0* p = (NotCondition_23d0e0*)FUN_0008d690(0xc);
    if (p) {
        ((Helper_23d0e0*)p)->f(2);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00428a24);
        return (void*)(p);
    }
    return (void*)((NotCondition_23d0e0*)0);
}

namespace fn_f787eff2 {

// 0x0023d110 fight::ConditionFactoryTemplate<fight::NotCondition>::vfunc_2 (36 B): matches/0x0023d110.cpp
// sym: ?vfunc_5@ConditionFactoryTemplate_23d110@fn_f787eff2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ConditionFactoryTemplate_23d110* ConditionFactoryTemplate_23d110::vfunc_5(signed char flags) {
    *(void***)this = ConditionFactory_23d110_vftable;
    Destroy();
    if (flags & 1) {
        FUN_00263f30(this);
    }
    return this;
}

} // namespace fn_f787eff2

// 0x0023d140 fight::ConditionFactoryCasterTemplate<fight::OrCondition>::vfunc_1 (55 B): matches/0x0023d140.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VOrCondition@fight@@@fight@@UAEPAXPAX@Z
template <> void* fight::ConditionFactoryCasterTemplate<fight::OrCondition>::vfunc_1(void* __p0) { void * p = (void *)__p0;

    void* q = alloc(0x10);
    if (q) {
        ((Helper_23d140*)q)->Init();
        *(hulk_uintptr*)q = ((hulk_intptr)DAT_00428a98);
        ((owners::Target_27b040 *)(((Helper_23d140*)((char*)q + 8))))->FUN_0027b040((hulk_uintptr)p);
        return (void*)(q);
    }
    return (void*)(0);
}


// 0x0023d180 fight::ConditionFactoryTemplate<fight::OrCondition>::vfunc_5 (40 B): matches/0x0023d180.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VOrCondition@fight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<fight::OrCondition>::vfunc_5() {
    Init_23d180* p = (Init_23d180*)FUN_0008d690(12);
    if (p) {
        p->init(1);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00428a44);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f787eff2 {

// 0x0023d1b0 fight::ConditionFactoryTemplate<fight::OrCondition>::vfunc_2 (36 B): matches/0x0023d1b0.cpp
// sym: ?vfunc_5@ConditionFactoryTemplate_23d1b0@fn_f787eff2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ConditionFactoryTemplate_23d1b0* ConditionFactoryTemplate_23d1b0::vfunc_5(signed char flags) {
    *(void***)this = ConditionFactory_23d1b0_vftable;
    Destroy();
    if (flags & 1) {
        FUN_00263f30(this);
    }
    return this;
}

} // namespace fn_f787eff2
