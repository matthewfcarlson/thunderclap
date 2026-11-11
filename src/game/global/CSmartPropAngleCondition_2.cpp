// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058710..0x000587c0 (kind game, layer game, confidence high), dominant class CSmartPropAngleCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0c8ca41 {
#define TREE_TU_END }
namespace fn_f0c8ca41 {} using namespace fn_f0c8ca41;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0c8ca41 {
class TrackFactoryTemplate_58710 {
  public:
    TrackFactoryTemplate_58710() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053bc0();
extern int hulk_at_003f9620;
struct ConditionFactoryTemplate_58790 {
    void* m_vptr;
    void base1_dtor_00049740();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0c8ca41

// 0x00058710 fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition>::vfunc_1 (60 B): matches/0x00058710.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropAngleCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58710));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58710* t = new (mem) TrackFactoryTemplate_58710();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053bc0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058750 fight::ConditionFactoryTemplate<CSmartPropAngleCondition>::vfunc_5 (54 B): matches/0x00058750.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@Factory@fn_00058750@@UAEPAVCSmartPropAngleCondition@2@XZ
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_00058750 {
/* size_t: tree_prelude.h */

class CCondition_58750 {
  public:
    CCondition_58750(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class CSmartPropAngleCondition : public CCondition_58750 {
  public:
    CSmartPropAngleCondition() throw();
    virtual void f0();
    float b;
    float c;
};
CSmartPropAngleCondition::CSmartPropAngleCondition() throw() : CCondition_58750(0) {
    b = 0.0f;
    c = 1.57079637f;
}
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CSmartPropAngleCondition* vfunc_5();
};
CSmartPropAngleCondition* Factory::vfunc_5() {
    return new CSmartPropAngleCondition;
}
} // namespace fn_00058750

namespace fn_f0c8ca41 {

// 0x00058790 fight::ConditionFactoryTemplate<CSmartPropAngleCondition>::vfunc_2 (43 B): matches/0x00058790.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58790@fn_f0c8ca41@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58790::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9620;
    base1_dtor_00049740();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0c8ca41
