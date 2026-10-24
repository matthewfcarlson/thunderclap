#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049b088;
namespace fight {
class TrackFactoryCaster_6e710 {
  public:
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSweepTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (int)FUN_00344e74((void*)a, 0, (void*)&DAT_0049850c, (void*)&DAT_0049b088, 0) != 0;
}
