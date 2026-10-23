#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_111a40 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TokenTrack_111a40 {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004a4930;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004a4930, 0) != 0;
}
