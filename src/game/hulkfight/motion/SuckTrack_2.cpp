// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e1a0..0x0017e260 (kind game, layer game, confidence high), dominant class hulkfight::motion::SuckTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_feb0571f {
#define TREE_TU_END }
namespace fn_feb0571f {} using namespace fn_feb0571f;
namespace fn_feb0571f {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_feb0571f {
class TrackFactoryTemplate_17e1a0 {
  public:
    TrackFactoryTemplate_17e1a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00179dc0();
} // namespace fn_feb0571f
void* operator new(size_t) HULK_NEW_THROW;
namespace hulkfight { namespace motion {
class BaseTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int extra, a;
    BaseTrack() throw();
};
} }
namespace hulkfight { namespace motion {
class Track_17e1e0 : public BaseTrack {
  public:
    int b;
    float c;
    int d, e, f, g;
    Track_17e1e0() throw() : b(0), d(0), e(0), f(0), g(0) {}
};
} }
namespace hulkfight { namespace motion {
class SuckTrack_17e1e0 : public Track_17e1e0 {
  public:
    SuckTrack_17e1e0() throw() : Track_17e1e0() {
        c = -1.0f;
        a = 1;
    }
    virtual void f0();
};
} }
namespace fn_feb0571f {
extern int hulk_at_00418e18;

} // namespace fn_feb0571f

// 0x0017e1a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckTrack>::vfunc_1 (60 B): matches/0x0017e1a0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSuckTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e1a0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17e1a0* t = new (mem) TrackFactoryTemplate_17e1a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00179dc0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e1e0 fight::TrackFactoryTemplate<hulkfight::motion::SuckTrack>::vfunc_5 (72 B): matches/0x0017e1e0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSuckTrack@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SuckTrack>::vfunc_5() {
    return (void*)(new hulkfight::motion::SuckTrack_17e1e0);
}

namespace fn_feb0571f {

// 0x0017e230 fight::TrackFactoryTemplate<hulkfight::motion::SuckTrack>::vfunc_2 (43 B): matches/0x0017e230.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_feb0571f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418e18;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_feb0571f
