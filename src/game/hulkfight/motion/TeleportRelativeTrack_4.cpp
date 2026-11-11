// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017ea40..0x0017eb10 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportRelativeTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa4635ce {
#define TREE_TU_END }
namespace fn_fa4635ce {} using namespace fn_fa4635ce;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fa4635ce {
class TrackFactoryTemplate_17ea40 {
  public:
    TrackFactoryTemplate_17ea40() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017ab80();
} // namespace fn_fa4635ce
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_fa4635ce {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[8];
};
struct Fields {
    Fields() : f10(0), f14(0), f18(-1.0f), f1c(0), f20(0), f24(0) {}
    volatile int f10, f14;
    volatile float f18;
    volatile int f1c, f20, f24;
};
class TeleportRelativeTrack_17ea80 : public BaseTrack {
  public:
    TeleportRelativeTrack_17ea80() throw() : f0c(0), fields() {}
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    volatile int f0c;
    Fields fields;
    float f28;
};
extern int hulk_at_00418f68;

} // namespace fn_fa4635ce

// 0x0017ea40 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_1 (60 B): matches/0x0017ea40.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17ea40));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17ea40* t = new (mem) TrackFactoryTemplate_17ea40();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ab80();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017ea80 fight::TrackFactoryTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_5 (82 B): matches/0x0017ea80.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_5() {
    TeleportRelativeTrack_17ea80* p = new TeleportRelativeTrack_17ea80;
    if (p) {
        p->f28 = 2.0f;
        ((int*)((char*)p + 8))[0] = 1;
    }
    return (void*)(p);
}

namespace fn_fa4635ce {

// 0x0017eae0 fight::TrackFactoryTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_2 (43 B): matches/0x0017eae0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fa4635ce@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418f68;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fa4635ce
