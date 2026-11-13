// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077690..0x00077750 (kind game, layer game, confidence high), dominant class CSweepTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcf3eba1 {
#define TREE_TU_END }
namespace fn_fcf3eba1 {} using namespace fn_fcf3eba1;
namespace fn_fcf3eba1 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcf3eba1 {
class TrackFactoryTemplate_77690 {
  public:
    TrackFactoryTemplate_77690() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000712c0();
extern "C" char DAT_003fbc9c[];
struct CSweepTrack_776d0 {
    virtual ~CSweepTrack_776d0();
    char pad[0x20];
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct InitClass {
    void Init_00236d40();
};
extern int hulk_at_003feb4c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069b30();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcf3eba1

// 0x00077690 fight::TrackFactoryCasterTemplate<CSweepTrack>::vfunc_1 (60 B): matches/0x00077690.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSweepTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSweepTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77690));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_77690* t = new (mem) TrackFactoryTemplate_77690();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000712c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000776d0 fight::TrackFactoryTemplate<CSweepTrack>::vfunc_5 (76 B): matches/0x000776d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSweepTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CSweepTrack>::vfunc_5() {
    CSweepTrack_776d0* p = (CSweepTrack_776d0*)FUN_0008d690((int)sizeof(CSweepTrack_776d0));
    if (p) {
        ((InitClass*)p)->Init_00236d40();
        *(unsigned long*)((char*)p + 0x0c) = 0;
        *(unsigned long*)((char*)p + 0x14) = 0;
        *(unsigned long*)((char*)p + 0x1c) = 0;
        *(unsigned long*)((char*)p + 0x20) = 0;
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_003fbc9c);
        *(unsigned long*)((char*)p + 0x10) = 0x3f800000;
        *(unsigned long*)((char*)p + 0x18) = 0xffffffff;
        *(unsigned long*)((char*)p + 8) = 1;
    } else {
        return (void*)(0);
    }
    return (void*)(p);
}

namespace fn_fcf3eba1 {

// 0x00077720 fight::TrackFactoryTemplate<CSweepTrack>::vfunc_2 (43 B): matches/0x00077720.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fcf3eba1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003feb4c;
    base1_dtor_00069b30();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fcf3eba1
