// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058eb0..0x00058f60 (kind game, layer game, confidence high), dominant class CGrappleCharacterTemplateCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6ad9474 {
#define TREE_TU_END }
namespace fn_f6ad9474 {} using namespace fn_f6ad9474;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6ad9474 {
class TrackFactoryTemplate_58eb0 {
  public:
    TrackFactoryTemplate_58eb0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00056a40();
extern int hulk_at_003f9778;
struct ConditionFactoryTemplate_58f30 {
    void* m_vptr;
    void base1_dtor_0004a0b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f6ad9474

// 0x00058eb0 fight::ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>::vfunc_1 (60 B): matches/0x00058eb0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleCharacterTemplateCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58eb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58eb0* t = new (mem) TrackFactoryTemplate_58eb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00056a40();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f6ad9474 {

// 0x00058f30 fight::ConditionFactoryTemplate<CGrappleCharacterTemplateCondition>::vfunc_2 (43 B): matches/0x00058f30.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58f30@fn_f6ad9474@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58f30::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9778;
    base1_dtor_0004a0b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6ad9474
