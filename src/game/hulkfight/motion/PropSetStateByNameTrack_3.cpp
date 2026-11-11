// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186d40..0x00186dc0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByNameTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f356d859 {
#define TREE_TU_END }
namespace fn_f356d859 {} using namespace fn_f356d859;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f356d859 {
struct Base {
    virtual bool Check(void*);
    virtual void other();
};
extern "C" int __cdecl Lookup(void*, int, void*, void*, int);
extern void* hulk_at_0049850c;
extern void* hulk_at_004bdd60;

} // namespace fn_f356d859

// 0x00186d40 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (36 B): matches/0x00186d40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Lookup(p, 0, &hulk_at_0049850c, &hulk_at_004bdd60, 0) != 0;
}


// 0x00186d70 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (30 B): matches/0x00186d70.cpp
// sym: ??_G?$ParamFloatConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::~ParamFloatConstRange() {}


// 0x00186d90 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (30 B): matches/0x00186d90.cpp
// sym: ??_G?$ParamIntConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::~ParamIntConstRange() {}

