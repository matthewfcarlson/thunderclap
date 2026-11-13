// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114560..0x00114620 (kind game, layer game, confidence high), dominant class hulkfight::ai::PropsToSuckCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f60a7f8c {
#define TREE_TU_END }
namespace fn_f60a7f8c {} using namespace fn_f60a7f8c;
namespace fn_f60a7f8c {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f60a7f8c {
class TrackFactoryTemplate_114560 {
  public:
    TrackFactoryTemplate_114560() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001123a0();
struct PropsToSuckCondition {
    void InitBase_00234590(int flag);
    char pad[0xc];
    int m_c;
    float m_f;
    unsigned char m_b;
    int m_i;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0040db04;
extern int hulk_at_0040e914;
struct ConditionFactoryTemplate_1145f0 {
    void* m_vptr;
    void base1_dtor_0010cec0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f60a7f8c

// 0x00114560 fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_1 (60 B): matches/0x00114560.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114560));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_114560* t = new (mem) TrackFactoryTemplate_114560();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001123a0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f60a7f8c {

// 0x001145a0 fight::ConditionFactoryTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_5 (65 B): matches/0x001145a0.cpp
// sym: ?Factory_vfunc_5@fn_f60a7f8c@@YAPAXPAX@Z
void* __cdecl Factory_vfunc_5(void* self) {
    PropsToSuckCondition* p = (PropsToSuckCondition*)FUN_0008d690((int)sizeof(PropsToSuckCondition));
    if (p != 0) {
        p->InitBase_00234590(0);
        *(void**)p = (void*)&hulk_at_0040db04;
        p->m_c = 0;
        p->m_f = 10.0f;
        p->m_b = 0;
        p->m_i = -1;
        return p;
    }
    return 0;
}


// 0x001145f0 fight::ConditionFactoryTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_2 (43 B): matches/0x001145f0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1145f0@fn_f60a7f8c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1145f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e914;
    base1_dtor_0010cec0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f60a7f8c
