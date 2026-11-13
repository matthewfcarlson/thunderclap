// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e4a0..0x0017e560 (kind game, layer game, confidence high), dominant class hulkfight::motion::MotionStateTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb34bd6d {
#define TREE_TU_END }
namespace fn_fb34bd6d {} using namespace fn_fb34bd6d;
namespace fn_fb34bd6d {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb34bd6d {
class TrackFactoryTemplate_17e4a0 {
  public:
    TrackFactoryTemplate_17e4a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a260();
} // namespace fn_fb34bd6d
void* operator new(size_t) HULK_NEW_THROW;
namespace hulkfight { namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void f0();
    char pad[8];
};
} }
namespace hulkfight { namespace motion {
class MotionStateTrack_17e4e0 : public BaseTrack {
  public:
    MotionStateTrack_17e4e0() throw() : BaseTrack(), b(0), c(-1.0f), d(0) { *(int*)(pad + 4) = 1; }
    virtual void f0();
    int b;
    float c;
    int d;
};
} }
namespace fight {
class TrackFactory_17e4e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual hulkfight::motion::MotionStateTrack_17e4e0* vfunc_5();
};
}
namespace fn_fb34bd6d {
extern int hulk_at_00418e88;

} // namespace fn_fb34bd6d

// 0x0017e4a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionStateTrack>::vfunc_1 (60 B): matches/0x0017e4a0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionStateTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionStateTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e4a0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17e4a0* t = new (mem) TrackFactoryTemplate_17e4a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a260();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e4e0 fight::TrackFactoryTemplate<hulkfight::motion::MotionStateTrack>::vfunc_5 (66 B): matches/0x0017e4e0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionStateTrack@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MotionStateTrack>::vfunc_5() {
    return (void*)(new hulkfight::motion::MotionStateTrack_17e4e0);
}

namespace fn_fb34bd6d {

// 0x0017e530 fight::TrackFactoryTemplate<hulkfight::motion::MotionStateTrack>::vfunc_2 (43 B): matches/0x0017e530.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fb34bd6d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418e88;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fb34bd6d
