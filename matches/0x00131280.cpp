#include "gen/fight.h"

namespace hulkfight {
class XPTrack_131280;
}
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004aaea8;
namespace fight {
class TrackFactoryCaster_131280 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::XPTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aaea8, 0) != 0;
}
