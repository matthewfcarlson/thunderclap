// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00052320..0x00052430 (kind game, layer game, confidence high), dominant class CGrappleFightNodeParentCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f165d3e7 {
#define TREE_TU_END }
namespace fn_f165d3e7 {} using namespace fn_f165d3e7;
namespace fn_f165d3e7 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f165d3e7 {
class TrackFactoryTemplate_52320 {
  public:
    TrackFactoryTemplate_52320() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f85a8;
struct ConditionFactoryTemplate_52360 {
    void* m_vptr;
    void base1_dtor_00235ad0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003f85c4[];
class CGrappleFightNodeParentCondition_52390 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
extern "C" void* FUN_0008d690(unsigned int);
struct Actor { char pad[0x330]; char *alternate; char *primary; char *fallback; };
struct Context_523c0 { Actor * FUN_00059a30(); };

} // namespace fn_f165d3e7

// 0x00052320 fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::vfunc_1 (60 B): matches/0x00052320.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleFightNodeParentCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_52320));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_52320* t = new (mem) TrackFactoryTemplate_52320();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00236250();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f165d3e7 {

// 0x00052360 fight::ConditionFactoryTemplate<CGrappleFightNodeParentCondition>::vfunc_2 (43 B): matches/0x00052360.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_52360@fn_f165d3e7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_52360::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f85a8;
    base1_dtor_00235ad0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f165d3e7

// 0x00052390 fight::ConditionFactoryTemplate<CGrappleFightNodeParentCondition>::vfunc_5 (38 B): matches/0x00052390.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGrappleFightNodeParentCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CGrappleFightNodeParentCondition>::vfunc_5() {
    CGrappleFightNodeParentCondition_52390* p = (CGrappleFightNodeParentCondition_52390*)FUN_0008d690(0x20);
    if (p) {
        ((fight::FightNodeParentCondition *)p)->FUN_00235b00();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f85c4);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000523c0 CGrappleFightNodeParentCondition::vfunc_7 (70 B): equivalent/0x000523c0.cpp
// sym: ?vfunc_7@CGrappleFightNodeParentCondition@@UAEHPAX@Z @2d7d8caea0d7 @w8fa6254b59b2
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 9/10, incomplete)
// CGrappleFightNodeParentCondition::vfunc_7 @ 0x000523c0
hulk_intptr CGrappleFightNodeParentCondition::vfunc_7(void* __p0) { Input * input = (Input *)__p0;
 if (!input) return (int)(0); Actor *actor = ((Context_523c0 *)((owners::Object_592a0 *)input)->FUN_000592a0())->FUN_00059a30(); char *result = actor->primary; if (!result) result = actor->alternate; if (!result) result = actor->fallback; return (hulk_intptr)(result ? result + 0xdc : 0); }


// 0x00052410 CGrappleFightNodeParentCondition::vfunc_5 (30 B): matches/0x00052410.cpp
// sym: ??_GCGrappleFightNodeParentCondition@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleFightNodeParentCondition::~CGrappleFightNodeParentCondition() {}

