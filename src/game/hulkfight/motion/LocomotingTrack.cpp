// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00164ec0..0x00164f70 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotingTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdfc018a {
#define TREE_TU_END }
namespace fn_fdfc018a {} using namespace fn_fdfc018a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fdfc018a {
class TrackFactoryTemplate_164ec0 {
  public:
    TrackFactoryTemplate_164ec0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00161380();
extern int g_vftable_164f40;

} // namespace fn_fdfc018a

// 0x00164ec0 fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotingTrack>::vfunc_1 (60 B): matches/0x00164ec0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VLocomotingTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotingTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_164ec0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_164ec0* t = new (mem) TrackFactoryTemplate_164ec0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00161380();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00164f00 fight::TrackFactoryTemplate<hulkfight::motion::LocomotingTrack>::vfunc_5 (59 B): matches/0x00164f00.cpp [wrapped: conflict: fight::TrackFactory; fight::TrackFactoryTemplate]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VLocomotingTrack@motion@hulkfight@fn_00164f00@@@fight@fn_00164f00@@UAEPAXXZ
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_00164f00 {
/* size_t: tree_prelude.h */

namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    int base;
};
class LocomotingTrack : public BaseTrack {
  public:
    LocomotingTrack() throw() : BaseTrack() {
        zero = 0;
        neg = -1.0f;
        flag = 1;
    }
    virtual void v0();
    int flag;
    int zero;
    float neg;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc_5();
};
template <class T> class TrackFactoryTemplate : public TrackFactory {
  public:
    virtual void* vfunc_5();
};
template <class T> void* TrackFactoryTemplate<T>::vfunc_5() {
    return new T;
}
template void* TrackFactoryTemplate<hulkfight::motion::LocomotingTrack>::vfunc_5();
} // namespace fight
} // namespace fn_00164f00

namespace fn_fdfc018a {

// 0x00164f40 fight::TrackFactoryTemplate<hulkfight::motion::LocomotingTrack>::vfunc_2 (43 B): matches/0x00164f40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fdfc018a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_164f40;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fdfc018a
