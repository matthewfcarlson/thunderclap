#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(const char*, int, const char*, const char*, int);
namespace fight {
class TrackFactoryCaster_190fe0 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class SimulationTrack_190fe0 {};
} // namespace motion
} // namespace hulkfight
extern const char a[], b[];
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SimulationTrack>::vfunc_0(void* __p0) { const char * name = (const char *)__p0;

    return FUN_00344e74(name, 0, a, b, 0) != 0;
}
