#include "gen/fight.h"

extern int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004aac50;
namespace fight {
class TrackFactoryCaster_131040 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class DialogueTrack_131040 {};
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::DialogueTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004aac50, 0) != 0;
}
