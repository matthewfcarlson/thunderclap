// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000570f0..0x000571c0 (kind game, layer game, confidence high), dominant class CAxisUpCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f71d9e3d {
#define TREE_TU_END }
namespace fn_f71d9e3d {} using namespace fn_f71d9e3d;
namespace fn_f71d9e3d {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f71d9e3d {
class TrackFactoryTemplate_570f0 {
  public:
    TrackFactoryTemplate_570f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f917c;
struct ConditionFactoryTemplate_57130 {
    void* m_vptr;
    void base1_dtor_00048680();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern void* hulk_at_003f6d50[];
class CAxisTimeCondition_57190 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f71d9e3d
class CAxisUpCondition : public CAxisTimeCondition_57190 {
  public:
    CAxisUpCondition* vfunc_5(signed char flags);
};


// 0x000570f0 fight::ConditionFactoryCasterTemplate<CAxisUpCondition>::vfunc_1 (60 B): matches/0x000570f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisUpCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisUpCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_570f0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_570f0* t = new (mem) TrackFactoryTemplate_570f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052a40();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f71d9e3d {

// 0x00057130 fight::ConditionFactoryTemplate<CAxisUpCondition>::vfunc_2 (43 B): matches/0x00057130.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57130@fn_f71d9e3d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57130::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f917c;
    base1_dtor_00048680();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f71d9e3d

// 0x00057160 fight::ConditionFactoryTemplate<CAxisUpCondition>::vfunc_5 (38 B): matches/0x00057160.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?make@Factory@fn_00057160@@UAEPAVCAxisTimeCondition_57160@2@XZ
namespace fn_00057160 {

class CAxisTimeCondition_57160 {
    char pad[20];

  public:
    CAxisTimeCondition_57160();
    virtual void f();
};
class CAxisUpCondition : public CAxisTimeCondition_57160 {
  public:
    CAxisUpCondition();
    virtual void f();
};
CAxisUpCondition::CAxisUpCondition() : CAxisTimeCondition_57160() {}
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CAxisTimeCondition_57160* make();
};
CAxisTimeCondition_57160* Factory::make() {
    return new CAxisUpCondition;
}
} // namespace fn_00057160


// 0x00057190 CAxisUpCondition::vfunc_5 (36 B): matches/0x00057190.cpp
// sym: ?vfunc_5@CAxisUpCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisUpCondition* CAxisUpCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

