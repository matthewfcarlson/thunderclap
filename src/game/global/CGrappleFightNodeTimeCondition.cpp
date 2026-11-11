// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052430..0x00052540 (kind game, layer game, confidence high), dominant class CGrappleFightNodeTimeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcf73221 {
#define TREE_TU_END }
namespace fn_fcf73221 {} using namespace fn_fcf73221;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcf73221 {
class TrackFactoryTemplate_52430 {
  public:
    TrackFactoryTemplate_52430() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_52470;
struct ConditionFactoryTemplate_52470 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
struct CFightNodeTimeCondition_524a0 {
    virtual ~CFightNodeTimeCondition_524a0();
    char pad[0x10];
    void Initialize();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Result { char pad[0xdc]; };
struct Node_524d0 { char pad[0x330]; Result* first; Result* second; Result* third; };
struct Intermediate { Node_524d0* FUN_00059a30(); };

} // namespace fn_fcf73221

// 0x00052430 fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>::vfunc_1 (60 B): matches/0x00052430.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleFightNodeTimeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_52430));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_52430* t = new (mem) TrackFactoryTemplate_52430();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00236340();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fcf73221 {

// 0x00052470 fight::ConditionFactoryTemplate<CGrappleFightNodeTimeCondition>::vfunc_2 (43 B): matches/0x00052470.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_52470@fn_fcf73221@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_52470::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_52470;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcf73221

// 0x000524a0 fight::ConditionFactoryTemplate<CGrappleFightNodeTimeCondition>::vfunc_5 (38 B): matches/0x000524a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGrappleFightNodeTimeCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x000521a0 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CGrappleFightNodeTimeCondition>::vfunc_5() {
    CFightNodeTimeCondition_524a0* p = (CFightNodeTimeCondition_524a0*)FUN_0008d690((int)sizeof(CFightNodeTimeCondition_524a0));
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000524d0 CGrappleFightNodeTimeCondition::vfunc_7 (70 B): equivalent/0x000524d0.cpp
// sym: ?vfunc_7@CGrappleFightNodeTimeCondition@@UAEHPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 9/10, incomplete)
// CGrappleFightNodeTimeCondition::vfunc_7 @ 0x000524d0
hulk_intptr CGrappleFightNodeTimeCondition::vfunc_7(void* __p0) { Input * input = (Input *)__p0;

    if (!input) return (int)(0);
    Node_524d0* node = ((Intermediate *)((owners::Object_592a0 *)input)->FUN_000592a0())->FUN_00059a30();
    Result* result = node->second;
    if (!result) result = node->first;
    if (!result) result = node->third;
    if (!result) return (int)(0);
    return (hulk_intptr)((Result*)((char*)result + 0xdc));
}


// 0x00052520 CGrappleFightNodeTimeCondition::vfunc_5 (30 B): matches/0x00052520.cpp
// sym: ??_GCGrappleFightNodeTimeCondition@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleFightNodeTimeCondition::~CGrappleFightNodeTimeCondition() {}

