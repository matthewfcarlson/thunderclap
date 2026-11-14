// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e0e0..0x0016e190 (kind game, layer game, confidence high), dominant class hulkfight::motion::RageModeStateCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff0ee82a {
#define TREE_TU_END }
namespace fn_ff0ee82a {} using namespace fn_ff0ee82a;
namespace fn_ff0ee82a {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff0ee82a {
class TrackFactoryTemplate_16e0e0 {
  public:
    TrackFactoryTemplate_16e0e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016bc20();
} // namespace fn_ff0ee82a
void* __cdecl operator new(size_t);
namespace fight {
class ConditionFactory_16e120 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
}
namespace hulkfight { namespace motion {
class BaseCondition {
  public:
    BaseCondition(int);
    virtual void f0();
    virtual bool f1_00234270(void*);
    virtual bool f2_002342b0(int);
    char pad[8];
    int a;
    int b;
};
} }
namespace hulkfight { namespace motion {
class RageModeStateCondition_16e120 : public BaseCondition {
  public:
    RageModeStateCondition_16e120(int x) : BaseCondition(x) {
        a = 0;
        b = 0;
    }
    virtual void f0();
};
} }
namespace fn_ff0ee82a {
extern int hulk_at_00417744;
struct ConditionFactoryTemplate_16e160 {
    void* m_vptr;
    void base1_dtor_00166550();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff0ee82a

// 0x0016e0e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_1 (60 B): matches/0x0016e0e0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VRageModeStateCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e0e0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_16e0e0* t = new (mem) TrackFactoryTemplate_16e0e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016bc20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e120 fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_5 (54 B): matches/0x0016e120.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VRageModeStateCondition@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::RageModeStateCondition_16e120(0));
}

namespace fn_ff0ee82a {

// 0x0016e160 fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_2 (43 B): matches/0x0016e160.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e160@fn_ff0ee82a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e160::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417744;
    base1_dtor_00166550();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_ff0ee82a
