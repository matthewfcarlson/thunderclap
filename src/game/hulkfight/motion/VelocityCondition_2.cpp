// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d4b0..0x0016d560 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9fa62c7 {
#define TREE_TU_END }
namespace fn_f9fa62c7 {} using namespace fn_f9fa62c7;
namespace fn_f9fa62c7 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9fa62c7 {
class TrackFactoryTemplate_16d4b0 {
  public:
    TrackFactoryTemplate_16d4b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b000();
extern "C" char DAT_004166b8[];
extern "C" void* alloc(hulk_uintptr);
class Condition {
  public:
    void init_00234590(int);
};
class Template_16d4f0 {
  public:
    char pad[0x14];
};
extern int hulk_at_0041754c;
struct ConditionFactoryTemplate_16d530 {
    void* m_vptr;
    void base1_dtor_00165b70();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f9fa62c7

// 0x0016d4b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityCondition>::vfunc_1 (60 B): matches/0x0016d4b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d4b0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_16d4b0* t = new (mem) TrackFactoryTemplate_16d4b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b000();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f9fa62c7 {

// 0x0016d4f0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityCondition>::vfunc_5 (54 B): matches/0x0016d4f0.cpp
// sym: ?target@fn_f9fa62c7@@YAPAXPAVTemplate_16d4f0@1@@Z
void* target(Template_16d4f0* self) {
    Condition* p = (Condition*)alloc(0x14);
    if (p) {
        p->init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004166b8);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}


// 0x0016d530 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityCondition>::vfunc_2 (43 B): matches/0x0016d530.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d530@fn_f9fa62c7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d530::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041754c;
    base1_dtor_00165b70();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f9fa62c7
