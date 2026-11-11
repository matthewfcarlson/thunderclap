// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00051ed0..0x00052050 (kind game, layer game, confidence high), dominant class CFightNodeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f43bcfc1 {
#define TREE_TU_END }
namespace fn_f43bcfc1 {} using namespace fn_f43bcfc1;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f43bcfc1 {
class TrackFactoryTemplate_51f70 {
  public:
    TrackFactoryTemplate_51f70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_51fb0;
struct ConditionFactoryTemplate_51fb0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CFightNodeCondition_51fe0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init();
};
class Helper_52010 {
  public:
    int second();
};

} // namespace fn_f43bcfc1

// 0x00051ed0 fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_0 (30 B): matches/0x00051ed0.cpp
// sym: ??_G?$ParamEnumConstList@VCIntentionSpeedCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CIntentionSpeedCondition>::~ParamEnumConstList() {}


// 0x00051ef0 fight::ParamFloatConstRange<CIntentionSpeedCondition>::vfunc_0 (30 B): matches/0x00051ef0.cpp
// sym: ??_G?$ParamFloatConstRange@VCIntentionSpeedCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CIntentionSpeedCondition>::~ParamFloatConstRange() {}


// 0x00051f10 fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_0 (30 B): matches/0x00051f10.cpp
// sym: ??_G?$ParamEnumConstList@VCClimbEdgeCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CClimbEdgeCondition>::~ParamEnumConstList() {}


// 0x00051f30 fight::ParamBool<CClimbEdgeCondition>::vfunc_0 (30 B): matches/0x00051f30.cpp
// sym: ??_G?$ParamBool@VCClimbEdgeCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CClimbEdgeCondition>::~ParamBool() {}


// 0x00051f50 fight::ParamFloatConstRange<CMotionClimbAngleCondition>::vfunc_0 (30 B): matches/0x00051f50.cpp
// sym: ??_G?$ParamFloatConstRange@VCMotionClimbAngleCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CMotionClimbAngleCondition>::~ParamFloatConstRange() {}


// 0x00051f70 fight::ConditionFactoryCasterTemplate<CFightNodeCondition>::vfunc_1 (60 B): matches/0x00051f70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCFightNodeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CFightNodeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_51f70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_51f70* t = new (mem) TrackFactoryTemplate_51f70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_002361a0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f43bcfc1 {

// 0x00051fb0 fight::ConditionFactoryTemplate<CFightNodeCondition>::vfunc_2 (43 B): matches/0x00051fb0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_51fb0@fn_f43bcfc1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_51fb0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_51fb0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f43bcfc1

// 0x00051fe0 fight::ConditionFactoryTemplate<CFightNodeCondition>::vfunc_5 (38 B): matches/0x00051fe0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCFightNodeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CFightNodeCondition>::vfunc_5() {
    CFightNodeCondition_51fe0* p = (CFightNodeCondition_51fe0*)FUN_0008d690(0x1c);
    if (p) {
        p->Init();
        *(void**)p = &CFightNodeConditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00052010 CFightNodeCondition::vfunc_7 (24 B): matches/0x00052010.cpp
// sym: ?vfunc_7@CFightNodeCondition@@UAEHPAX@Z
hulk_intptr CFightNodeCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    hulk_intptr x = ((int)((owners::Object_592a0 *)(((Helper_52010*)arg)))->FUN_000592a0());
    return ((Helper_52010*)x)->second() + 0xdc;
}


// 0x00052030 CFightNodeCondition::vfunc_5 (30 B): matches/0x00052030.cpp
// sym: ??_GCFightNodeCondition@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CFightNodeCondition::~CFightNodeCondition() {}

