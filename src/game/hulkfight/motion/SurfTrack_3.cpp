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

