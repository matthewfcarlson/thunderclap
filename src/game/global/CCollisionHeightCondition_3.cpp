// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000577c0..0x00057870 (kind game, layer game, confidence high), dominant class CCollisionHeightCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd594d6c {
#define TREE_TU_END }
namespace fn_fd594d6c {} using namespace fn_fd594d6c;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd594d6c {
class TrackFactoryTemplate_577c0 {
  public:
    TrackFactoryTemplate_577c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053540();
} // namespace fn_fd594d6c
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_fd594d6c {
class Base {
  public:
    Base(int) throw();
    virtual void f();
    char pad[8];
};
class CCollisionHeightCondition_57800 : public Base {
  public:
    CCollisionHeightCondition_57800() throw() : Base(0), a(0), b(0) {}
    virtual void f();
    int a, b;
};
extern int hulk_at_003f9368;
struct ConditionFactoryTemplate_57840 {
    void* m_vptr;
    void base1_dtor_00048ef0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd594d6c

// 0x000577c0 fight::ConditionFactoryCasterTemplate<CCollisionHeightCondition>::vfunc_1 (60 B): matches/0x000577c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionHeightCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionHeightCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_577c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_577c0* t = new (mem) TrackFactoryTemplate_577c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053540();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057800 fight::ConditionFactoryTemplate<CCollisionHeightCondition>::vfunc_5 (54 B): matches/0x00057800.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionHeightCondition@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<CCollisionHeightCondition>::vfunc_5() {
    return (void*)(new CCollisionHeightCondition_57800);
}

namespace fn_fd594d6c {

// 0x00057840 fight::ConditionFactoryTemplate<CCollisionHeightCondition>::vfunc_2 (43 B): matches/0x00057840.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57840@fn_fd594d6c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57840::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9368;
    base1_dtor_00048ef0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd594d6c
