#include "gen/fight.h"

class CDropTrack_6d790;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00498dbc;
namespace fight {
class TrackFactoryCaster_6d790 {
  public:
    virtual int vfunc_0(CDropTrack_6d790*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CDropTrack>::vfunc_0(void* __p0) { CDropTrack_6d790 * p = (CDropTrack_6d790 *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498dbc, 0) != 0;
}
