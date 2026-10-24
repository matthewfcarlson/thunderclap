#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004a4558;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_111720 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TokenSupressTrack_111720;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a4558, 0) != 0;
}
