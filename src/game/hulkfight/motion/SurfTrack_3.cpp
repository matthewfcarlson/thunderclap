// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179720..0x001797a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SurfTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc5a7e71 {
#define TREE_TU_END }
namespace fn_fc5a7e71 {} using namespace fn_fc5a7e71;
#include "game/hulkfight/motion.h"


// 0x00179720 fight::TrackFactoryCasterTemplate<hulkfight::motion::SurfTrack>::vfunc_0 (36 B): matches/0x00179720.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSurfTrack@motion@hulkfight@fn_00179720@@@fight@fn_00179720@@UAEHPAX@Z
namespace fn_00179720 {
extern char DAT_0049850c, DAT_004ba8b8;
extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> int TrackFactoryCasterTemplate<T>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba8b8, 0) != 0;
}
} // namespace fight
namespace hulkfight {
namespace motion {
class SurfTrack {};
} // namespace motion
} // namespace hulkfight
template int fight::TrackFactoryCasterTemplate<hulkfight::motion::SurfTrack>::vfunc_0(void*);
} // namespace fn_00179720


// 0x00179750 fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::vfunc_0 (30 B): matches/0x00179750.cpp
// sym: ??_G?$ParamFloatConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179750)
#endif


// 0x00179770 fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::vfunc_0 (30 B): matches/0x00179770.cpp
// sym: ??_G?$ParamIntConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::SurfTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x179770)
#endif

