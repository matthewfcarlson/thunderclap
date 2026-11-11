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
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_773f0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
struct COrientTargetTrack_77420 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init();
    char pad[0x28];
};
extern "C" void* FUN_0008d690(unsigned int);
extern void* orient_vtable;
extern void* COrientTrack_77450_vftable[];
class COrientTrack_77450 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
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
    m_vptr = (void*)&g_vftable_773f0;
    base1_dtor();
    base2_dtor();
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
        p->init();
        *(void**)p = &orient_vtable;
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
    *(void***)this = COrientTrack_77450_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

