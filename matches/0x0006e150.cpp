#include "gen/fight.h"

struct Info {
    int x;
};
extern char DAT_0049850c;
extern char DAT_0049a37c;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6e150 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CMoveAddYTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a37c, 0) != 0;
}
