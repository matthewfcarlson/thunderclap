// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000773b0..0x00077480 (kind game, layer game, confidence high), dominant class COrientTargetTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcb81868 {
#define TREE_TU_END }
namespace fn_fcb81868 {} using namespace fn_fcb81868;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcb81868 {
class TrackFactoryTemplate_773b0 {
  public:
    TrackFactoryTemplate_773b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003feaa0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a680();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
struct COrientTargetTrack_77420 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init_0006a6b0();
    char pad[0x28];
};
extern "C" void* FUN_0008d690(unsigned int);
extern void* hulk_at_003feabc;
extern void* hulk_at_003f98d0[];
class COrientTrack_77450 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fcb81868
class COrientTargetTrack : public COrientTrack_77450 {
  public:
    COrientTargetTrack* vfunc_5(signed char flags);
};


// 0x000773b0 fight::TrackFactoryCasterTemplate<COrientTargetTrack>::vfunc_1 (60 B): matches/0x000773b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCOrientTargetTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<COrientTargetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_773b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_773b0* t = new (mem) TrackFactoryTemplate_773b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071fb0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fcb81868 {

// 0x000773f0 fight::TrackFactoryTemplate<COrientTargetTrack>::vfunc_2 (43 B): matches/0x000773f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fcb81868@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003feaa0;
    base1_dtor_0006a680();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcb81868

// 0x00077420 fight::TrackFactoryTemplate<COrientTargetTrack>::vfunc_5 (38 B): matches/0x00077420.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCOrientTargetTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<COrientTargetTrack>::vfunc_5() {
    COrientTargetTrack_77420* p = (COrientTargetTrack_77420*)FUN_0008d690((int)sizeof(COrientTargetTrack_77420));
    if (p) {
        p->init_0006a6b0();
        *(void**)p = &hulk_at_003feabc;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00077450 COrientTargetTrack::vfunc_5 (36 B): matches/0x00077450.cpp
// sym: ?vfunc_5@COrientTargetTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
COrientTargetTrack* COrientTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f98d0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

