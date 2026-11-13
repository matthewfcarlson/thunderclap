// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057500..0x000575b0 (kind game, layer game, confidence high), dominant class CCharacterSizeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8e3f2ed {
#define TREE_TU_END }
namespace fn_f8e3f2ed {} using namespace fn_f8e3f2ed;
namespace fn_f8e3f2ed {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8e3f2ed {
class TrackFactoryTemplate_57500 {
  public:
    TrackFactoryTemplate_57500() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053220();
class CCharacterSizeCondition_57540 {
  public:
    hulk_intptr x;
    int a;
    int b;
    int c;
    int d;
    void Init_00234590(int);
};
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_003f6f80[];
extern int hulk_at_003f92f8;
struct ConditionFactoryTemplate_57580 {
    void* m_vptr;
    void base1_dtor_00048a70();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f8e3f2ed

// 0x00057500 fight::ConditionFactoryCasterTemplate<CCharacterSizeCondition>::vfunc_1 (60 B): matches/0x00057500.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCharacterSizeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCharacterSizeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57500));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_57500* t = new (mem) TrackFactoryTemplate_57500();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053220();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057540 fight::ConditionFactoryTemplate<CCharacterSizeCondition>::vfunc_5 (54 B): matches/0x00057540.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCharacterSizeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCharacterSizeCondition>::vfunc_5() {
    CCharacterSizeCondition_57540* p = (CCharacterSizeCondition_57540*)FUN_0008d690((int)sizeof(CCharacterSizeCondition_57540));
    if (p) {
        p->Init_00234590(0);
        p->x = (hulk_intptr)hulk_at_003f6f80;
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f8e3f2ed {

// 0x00057580 fight::ConditionFactoryTemplate<CCharacterSizeCondition>::vfunc_2 (43 B): matches/0x00057580.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57580@fn_f8e3f2ed@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57580::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f92f8;
    base1_dtor_00048a70();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f8e3f2ed
