// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186e40..0x00186ec0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDropTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fedb0ab7 {
#define TREE_TU_END }
namespace fn_fedb0ab7 {} using namespace fn_fedb0ab7;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fedb0ab7 {
class TrackFactoryCaster_186e40 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004bdec8;

} // namespace fn_fedb0ab7

// 0x00186e40 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDropTrack>::vfunc_0 (36 B): matches/0x00186e40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropDropTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDropTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004bdec8, 0) != 0;
}

