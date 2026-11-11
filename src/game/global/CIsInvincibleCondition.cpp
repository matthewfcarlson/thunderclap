// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052680..0x00052720 (kind game, layer game, confidence high), dominant class CIsInvincibleCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbd5c058 {
#define TREE_TU_END }
namespace fn_fbd5c058 {} using namespace fn_fbd5c058;
#include "game/global.h"

// ---- declarations shared by the functions below
void* operator new(size_t) HULK_NEW_THROW;
namespace fight {
class Arg;
}
namespace fight {
class Part {
  public:
    Part(Arg*) throw();
    char data[8];
};
}
namespace fight {
class BaseCond {
  public:
    BaseCond() throw();
    virtual void f();
    char pad[4];
};
}
namespace fight {
class CIsInvincibleCondition_52680 : public BaseCond {
  public:
    CIsInvincibleCondition_52680(Arg* a) throw() : BaseCond(), part(a) {}
    virtual void f();
    Part part;
};
}
namespace fight {
class ConditionFactoryCaster_52680 {
  public:
    virtual void vfunc_0();
    virtual CIsInvincibleCondition_52680* vfunc_1(Arg*);
};
}
namespace fn_fbd5c058 {
struct CIsGrappledCondition_526c0 {
    virtual ~CIsGrappledCondition_526c0();
    void init_00234590(int);
};
} // namespace fn_fbd5c058
void* operator new(size_t);
namespace fn_fbd5c058 {
extern void* hulk_at_003f7298;
extern void* hulk_at_003f8660[];
class ConditionFactory_526f0 {
  public:
    void Destroy_002343d0(); // FUN_00236d60, __thiscall, this in ecx
};
class ConditionFactoryTemplate_0526f0 : public ConditionFactory_526f0 {
  public:
    ConditionFactoryTemplate_0526f0* vfunc_5(signed char flags);
};

} // namespace fn_fbd5c058

// 0x00052680 fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition>::vfunc_1 (55 B): matches/0x00052680.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCIsInvincibleCondition@@@fight@@UAEPAXPAX@Z
 // namespace fight
template <> void* fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition>::vfunc_1(void* __p0) { Arg * a = (Arg *)__p0;

    return (void*)(new CIsInvincibleCondition_52680(a));
}


// 0x000526c0 fight::ConditionFactoryTemplate<CIsInvincibleCondition>::vfunc_5 (40 B): matches/0x000526c0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCIsInvincibleCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x00052580 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CIsInvincibleCondition>::vfunc_5() {
    CIsGrappledCondition_526c0* p = (CIsGrappledCondition_526c0*)operator new(0x0c);
    if (p) {
        p->init_00234590(0);
        *(void**)p = &hulk_at_003f7298;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fbd5c058 {

// 0x000526f0 fight::ConditionFactoryTemplate<CIsInvincibleCondition>::vfunc_2 (36 B): matches/0x000526f0.cpp
// sym: ?vfunc_5@ConditionFactoryTemplate_0526f0@fn_fbd5c058@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ConditionFactoryTemplate_0526f0* ConditionFactoryTemplate_0526f0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f8660;
    Destroy_002343d0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fbd5c058
