#include "gen/fight.h"

struct GrappleHoverTrack_137560;
namespace fight {
class TrackFactoryCaster_137560 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_0049850c;
extern char DAT_004aba50;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHoverTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aba50, 0) != 0;
}
