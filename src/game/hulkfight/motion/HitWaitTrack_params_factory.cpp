// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154b80..0x00154c00 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc015f88 {
#define TREE_TU_END }
namespace fn_fc015f88 {} using namespace fn_fc015f88;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc015f88 {
extern "C" int __cdecl FUN_00344e74(void*, int, int, int, int);
} // namespace fn_fc015f88
namespace fight {
class TrackFactoryCaster_154b80 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitWaitTrack_154b80;
} }
namespace fn_fc015f88 {
extern char DAT_0049850c;
extern char DAT_004b3030;

} // namespace fn_fc015f88

// 0x00154b80 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitWaitTrack>::vfunc_0 (36 B): matches/0x00154b80.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitWaitTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitWaitTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_004b3030, 0) != 0;
}


// 0x00154bb0 fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::vfunc_0 (30 B): matches/0x00154bb0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitWaitTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::~ParamFloatConstRange() {}


// 0x00154bd0 fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_0 (30 B): matches/0x00154bd0.cpp
// sym: ??_G?$ParamEnumConstList@VHitWaitTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::~ParamEnumConstList() {}

