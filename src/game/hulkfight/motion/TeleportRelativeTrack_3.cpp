// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001798e0..0x00179960 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportRelativeTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1775de3 {
#define TREE_TU_END }
namespace fn_f1775de3 {} using namespace fn_f1775de3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1775de3 {
extern char DAT_0049850c;
extern char DAT_004bab80;
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
} // namespace fn_f1775de3
namespace fight {
class TrackFactoryCaster_1798e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TeleportRelativeTrack_1798e0;
} }


// 0x001798e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_0 (36 B): matches/0x001798e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004bab80, 0) != 0;
}


// 0x00179910 fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::vfunc_0 (30 B): matches/0x00179910.cpp
// sym: ??_G?$ParamFloatConstRange@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::~ParamFloatConstRange() {}


// 0x00179930 fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::vfunc_0 (30 B): matches/0x00179930.cpp
// sym: ??_G?$ParamVector@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::~ParamVector() {}

