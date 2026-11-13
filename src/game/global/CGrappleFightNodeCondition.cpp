// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052210..0x00052320 (kind game, layer game, confidence high), dominant class CGrappleFightNodeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f94403bb {
#define TREE_TU_END }
namespace fn_f94403bb {} using namespace fn_f94403bb;
namespace fn_f94403bb {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f94403bb {
class TrackFactoryTemplate_52210 {
  public:
    TrackFactoryTemplate_52210() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f8568;
struct ConditionFactoryTemplate_52250 {
    void* m_vptr;
    void base1_dtor_00235a00();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CFightNodeCondition_52280 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init_00235a30();
};
struct Actor { char pad[0x330]; char *first; char *second; char *third; };
struct Stage { Actor * FUN_00059a30(); };

} // namespace fn_f94403bb

// 0x00052210 fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>::vfunc_1 (60 B): matches/0x00052210.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleFightNodeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_52210));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_52210* t = new (mem) TrackFactoryTemplate_52210();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_002361a0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f94403bb {

// 0x00052250 fight::ConditionFactoryTemplate<CGrappleFightNodeCondition>::vfunc_2 (43 B): matches/0x00052250.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_52250@fn_f94403bb@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_52250::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f8568;
    base1_dtor_00235a00();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f94403bb

// 0x00052280 fight::ConditionFactoryTemplate<CGrappleFightNodeCondition>::vfunc_5 (38 B): matches/0x00052280.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGrappleFightNodeCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x00051fe0 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CGrappleFightNodeCondition>::vfunc_5() {
    CFightNodeCondition_52280* p = (CFightNodeCondition_52280*)FUN_0008d690(0x1c);
    if (p) {
        p->Init_00235a30();
        *(void**)p = &CFightNodeConditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000522b0 CGrappleFightNodeCondition::vfunc_7 (70 B): equivalent/0x000522b0.cpp
// sym: ?vfunc_7@CGrappleFightNodeCondition@@UAEHPAX@Z @2d7d8caea0d7 @w8fa6254b59b2
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 9/10, incomplete)
// CGrappleFightNodeCondition::vfunc_7 @ 0x000522b0
hulk_intptr CGrappleFightNodeCondition::vfunc_7(void* __p0) { Input * input = (Input *)__p0;
 if (!input) return (int)(0); Actor *a = ((Stage *)((owners::Object_592a0 *)input)->FUN_000592a0())->FUN_00059a30(); char *p = a->second; if (!p) p = a->first; if (!p) p = a->third; return (hulk_intptr)(p ? p + 0xdc : 0); }


// 0x00052300 CGrappleFightNodeCondition::vfunc_5 (30 B): matches/0x00052300.cpp
// sym: ??_GCGrappleFightNodeCondition@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleFightNodeCondition::~CGrappleFightNodeCondition() {}

