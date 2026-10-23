#include "gen/fight.h"

extern "C" void* __cdecl do_cast(void*, long, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_004b9ff8;
namespace fight {
class TrackFactoryCaster_178f60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class JointRelativeTrack_178f60;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return do_cast(p, 0, &DAT_0049850c, &DAT_004b9ff8, 0) != 0;
}
