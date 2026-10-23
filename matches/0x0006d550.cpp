#include "gen/fight.h"

struct CClearCollisionStun_6d550;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00498908;
namespace fight {
class TrackFactoryCaster_6d550 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CClearCollisionStun>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_00498908, 0) != 0;
}
