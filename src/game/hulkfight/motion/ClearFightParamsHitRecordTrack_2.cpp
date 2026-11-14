// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a020..0x0015a0d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ClearFightParamsHitRecordTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f210eeb7 {
#define TREE_TU_END }
namespace fn_f210eeb7 {} using namespace fn_f210eeb7;
namespace fn_f210eeb7 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f210eeb7 {
class TrackFactoryTemplate_15a020 {
  public:
    TrackFactoryTemplate_15a020() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156420();
} // namespace fn_f210eeb7
void* __cdecl operator new(size_t);
namespace hulkfight { namespace motion {
class BaseTrack {
  public:
    BaseTrack();
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    int count;
    int zero;
};
} }
namespace hulkfight { namespace motion {
class ClearFightParamsHitRecordTrack_15a060 : public BaseTrack {
  public:
    ClearFightParamsHitRecordTrack_15a060() {
        zero = 0;
        count = 1;
    }
    virtual void a();
    virtual void b();
    virtual void c();
};
} }
namespace fn_f210eeb7 {
extern int hulk_at_004157d8;

} // namespace fn_f210eeb7

// 0x0015a020 fight::TrackFactoryCasterTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_1 (60 B): matches/0x0015a020.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a020));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_15a020* t = new (mem) TrackFactoryTemplate_15a020();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156420();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a060 fight::TrackFactoryTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_5 (52 B): matches/0x0015a060.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_5() {
    return (void*)(new hulkfight::motion::ClearFightParamsHitRecordTrack_15a060);
}

namespace fn_f210eeb7 {

// 0x0015a0a0 fight::TrackFactoryTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_2 (43 B): matches/0x0015a0a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f210eeb7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004157d8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f210eeb7
