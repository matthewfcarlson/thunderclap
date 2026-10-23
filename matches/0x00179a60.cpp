#include "gen/fight.h"

extern "C" void* __cdecl cast(void*, int, const void*, const void*, int);
extern "C" char DAT_0049850c, DAT_004bada0;
namespace hulkfight {
namespace motion {
class ChargeClearTrack_179a60;
}
} // namespace hulkfight
namespace fight {
class TrackFactoryCaster_179a60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeClearTrack>::vfunc_0(void* __p0) { void * object = (void *)__p0;

    return cast(object, 0, &DAT_0049850c, &DAT_004bada0, 0) != 0;
}
