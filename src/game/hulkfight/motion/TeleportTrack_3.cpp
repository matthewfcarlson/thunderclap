// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001795c0..0x00179640 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f672871b {
#define TREE_TU_END }
namespace fn_f672871b {} using namespace fn_f672871b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f672871b {
extern char DAT_0049850c;
extern char DAT_004ba760;
extern "C" void* __cdecl Find(void*, void*, void*, void*, void*);
} // namespace fn_f672871b
namespace fight {
class TrackFactoryCaster_1795c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class TeleportTrack_1795c0;
} }


// 0x001795c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportTrack>::vfunc_0 (36 B): matches/0x001795c0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTeleportTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_0049850c, &DAT_004ba760, 0) != 0;
}

