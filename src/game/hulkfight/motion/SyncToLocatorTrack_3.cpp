// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179020..0x00179100 (kind game, layer game, confidence high), dominant class hulkfight::motion::SyncToLocatorTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2aa30a1 {
#define TREE_TU_END }
namespace fn_f2aa30a1 {} using namespace fn_f2aa30a1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2aa30a1 {
extern int hulk_at_0049850c, hulk_at_004ba0a8;
extern "C" int __cdecl check(void*, int, const int*, const int*, int);
} // namespace fn_f2aa30a1
namespace fight {
class TrackFactoryCaster_179020 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class SyncToLocatorTrack_179020;
} }


// 0x00179020 fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (36 B): matches/0x00179020.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &hulk_at_0049850c, &hulk_at_004ba0a8, 0) != 0;
}


// 0x00179050 fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x00179050.cpp
// sym: ??_G?$ParamFloatConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::~ParamFloatConstRange() {}


// 0x00179070 fight::ParamScript<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x00179070.cpp
// sym: ??_G?$ParamScript@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamScript<hulkfight::motion::SyncToLocatorTrack>::~ParamScript() {}


// 0x00179090 fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x00179090.cpp
// sym: ??_G?$ParamEnumConstList@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::~ParamEnumConstList() {}


// 0x001790b0 fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x001790b0.cpp
// sym: ??_G?$ParamVector@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::~ParamVector() {}


// 0x001790d0 fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_0 (30 B): matches/0x001790d0.cpp
// sym: ??_G?$ParamIntConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::~ParamIntConstRange() {}

