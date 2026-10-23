#include "gen/fight.h"

extern "C" int __cdecl Find(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004a47f0;
namespace fight {
class TrackFactoryCaster_111920 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class ButtonTrack_111920 {};
} // namespace ai
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_0049850c, &DAT_004a47f0, 0) != 0;
}
