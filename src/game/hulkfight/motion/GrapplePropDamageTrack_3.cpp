// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186f60..0x00186fe0 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrapplePropDamageTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9bb6ced {
#define TREE_TU_END }
namespace fn_f9bb6ced {} using namespace fn_f9bb6ced;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9bb6ced {
class TrackFactoryCaster_186f60 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern const char a[], b[];
extern "C" int __cdecl check(const char*, int, const char*, const char*, int);

} // namespace fn_f9bb6ced

// 0x00186f60 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0 (36 B): matches/0x00186f60.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return check(s, 0, a, b, 0) != 0;
}


// 0x00186f90 fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0 (30 B): matches/0x00186f90.cpp
// sym: ??_G?$ParamFloatConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::~ParamFloatConstRange() {}


// 0x00186fb0 fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0 (30 B): matches/0x00186fb0.cpp
// sym: ??_G?$ParamIntConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::~ParamIntConstRange() {}

