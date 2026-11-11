// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154a60..0x00154b80 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f182fbb4 {
#define TREE_TU_END }
namespace fn_f182fbb4 {} using namespace fn_f182fbb4;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f182fbb4 {
extern "C" void* __cdecl dynamic_cast_helper(void*, int, void*, void*, int);
} // namespace fn_f182fbb4
namespace fight {
class TrackFactoryCaster_154a60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitPauseTrack_154a60 {};
} }
namespace fn_f182fbb4 {
extern char DAT_0049850c;
extern char DAT_004b2ee0;
} // namespace fn_f182fbb4
namespace fight {
class TrackFactoryCaster_154ac0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HitReactionTrack_154ac0 {};
} }
namespace fn_f182fbb4 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b2f88;

} // namespace fn_f182fbb4

// 0x00154a60 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_0 (36 B): matches/0x00154a60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitPauseTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return dynamic_cast_helper(p, 0, &DAT_0049850c, &DAT_004b2ee0, 0) != 0;
}


// 0x00154a90 fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::vfunc_0 (30 B): matches/0x00154a90.cpp
// sym: ??_G?$ParamFloatConstRange@VHitPauseTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::~ParamFloatConstRange() {}


// 0x00154ac0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionTrack>::vfunc_0 (36 B): matches/0x00154ac0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b2f88, 0) != 0;
}


// 0x00154af0 fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154af0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::~ParamFloatConstRange() {}


// 0x00154b10 fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154b10.cpp
// sym: ??_G?$ParamEnumConstList@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::~ParamEnumConstList() {}


// 0x00154b30 fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154b30.cpp
// sym: ??_G?$ParamIntConstRange@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::~ParamIntConstRange() {}


// 0x00154b50 fight::ParamBool<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154b50.cpp
// sym: ??_G?$ParamBool@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::HitReactionTrack>::~ParamBool() {}

