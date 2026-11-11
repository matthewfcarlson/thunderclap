// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017ed30..0x0017ede0 (kind game, layer game, confidence high), dominant class hulkfight::motion::VisibilityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f50f90cf {
#define TREE_TU_END }
namespace fn_f50f90cf {} using namespace fn_f50f90cf;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f50f90cf {
class TrackFactoryTemplate_17ed30 {
  public:
    TrackFactoryTemplate_17ed30() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017aee0();
extern "C" char DAT_00417d48[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct Track_17ed70 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[4];
    int x;
    int y;
    unsigned char z;
};
extern void __fastcall init_00236d40(Track_17ed70*);
extern int hulk_at_00418fd8;

} // namespace fn_f50f90cf

// 0x0017ed30 fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>::vfunc_1 (60 B): matches/0x0017ed30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VVisibilityTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::VisibilityTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17ed30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17ed30* t = new (mem) TrackFactoryTemplate_17ed30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017aee0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017ed70 fight::TrackFactoryTemplate<hulkfight::motion::VisibilityTrack>::vfunc_5 (56 B): matches/0x0017ed70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VVisibilityTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::VisibilityTrack>::vfunc_5() {
    Track_17ed70* p = (Track_17ed70*)FUN_0008d690((int)sizeof(Track_17ed70));
    if (p) {
        init_00236d40(p);
        p->z = 1;
        p->x = 1;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00417d48);
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f50f90cf {

// 0x0017edb0 fight::TrackFactoryTemplate<hulkfight::motion::VisibilityTrack>::vfunc_2 (43 B): matches/0x0017edb0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f50f90cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418fd8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f50f90cf
