// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179960..0x00179a60 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportToLocatorTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7e413dc {
#define TREE_TU_END }
namespace fn_f7e413dc {} using namespace fn_f7e413dc;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7e413dc {
extern char DAT_0049850c;
extern char DAT_004bac38;
} // namespace fn_f7e413dc
namespace fight {
class TrackFactoryCaster_179960 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class IntentionClearTrack_179960 {};
} }
namespace hulkfight { namespace motion {
class TeleportToLocatorTrack_1799c0;
} }
namespace fn_f7e413dc {
extern int a, b;
extern "C" int __cdecl cast(void*, int, const int*, const int*, int);
} // namespace fn_f7e413dc
namespace fight {
class TrackFactoryCaster_1799c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179960 fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_0 (36 B): matches/0x00179960.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VIntentionClearTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004bac38, 0) != 0;
}


// 0x00179990 fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::vfunc_0 (30 B): matches/0x00179990.cpp
// sym: ??_G?$ParamFloatConstRange@VIntentionClearTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::~ParamFloatConstRange() {}


// 0x001799c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (36 B): matches/0x001799c0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast(p, 0, &a, &b, 0) != 0;
}


// 0x001799f0 fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (30 B): matches/0x001799f0.cpp
// sym: ??_G?$ParamFloatConstRange@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::~ParamFloatConstRange() {}


// 0x00179a10 fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (30 B): matches/0x00179a10.cpp
// sym: ??_G?$ParamString@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::~ParamString() {}


// 0x00179a30 fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (30 B): matches/0x00179a30.cpp
// sym: ??_G?$ParamVector@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::~ParamVector() {}

