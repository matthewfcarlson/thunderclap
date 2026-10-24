#include "gen/fight.h"

namespace hulkfight {
namespace ai {
class PathFormationTrack_120780;
}
} // namespace hulkfight
int __cdecl CastFunc(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_120780 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::PathFormationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastFunc(p, 0, (void*)0x49850c, (void*)0x4a66d8, 0) != 0;
}
