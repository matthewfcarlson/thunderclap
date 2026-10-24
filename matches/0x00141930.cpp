#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_141930 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004ad588;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WallRunTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ad588, 0) != 0;
}
