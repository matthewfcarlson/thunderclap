#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" int FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
class TrackFactoryCaster_12dc80 {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
namespace fight {

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::PostEvent_StringTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    int result = FUN_00344e74(a, 0, 0x49850c, 0x4a9b10, 0);
    return result != 0;
}
