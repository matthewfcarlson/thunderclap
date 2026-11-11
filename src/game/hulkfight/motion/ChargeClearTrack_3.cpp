// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179a60..0x00179ae0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeClearTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1942bfb {
#define TREE_TU_END }
namespace fn_f1942bfb {} using namespace fn_f1942bfb;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1942bfb {
extern "C" void* __cdecl cast(void*, int, const void*, const void*, int);
extern "C" char DAT_0049850c, DAT_004bada0;
} // namespace fn_f1942bfb
namespace hulkfight { namespace motion {
class ChargeClearTrack_179a60;
} }
namespace fight {
class TrackFactoryCaster_179a60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x00179a60 fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_0 (36 B): matches/0x00179a60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VChargeClearTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_0(void* __p0) { void * object = (void *)__p0;

    return cast(object, 0, &DAT_0049850c, &DAT_004bada0, 0) != 0;
}


// 0x00179a90 fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::vfunc_0 (30 B): matches/0x00179a90.cpp
// sym: ??_G?$ParamFloatConstRange@VChargeClearTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179a90)
#endif


// 0x00179ab0 fight::ParamBool<hulkfight::motion::ChargeClearTrack>::vfunc_0 (30 B): matches/0x00179ab0.cpp
// sym: ??_G?$ParamBool@VChargeClearTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::ChargeClearTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::ChargeClearTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179ab0)
#endif

