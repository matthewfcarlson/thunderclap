#include "gen/fight.h"

class TrackFactoryCaster_130f40 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_004aab18;

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::StatBeginTrialTrack>::vfunc_0(void* __p0) { const char * name = (const char *)__p0;

    return FUN_00344e74(name, 0, &DAT_0049850c, &DAT_004aab18, 0) != 0;
}
