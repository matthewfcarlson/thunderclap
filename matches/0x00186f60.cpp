#include "gen/fight.h"

class TrackFactoryCaster_186f60 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern const char a[], b[];
extern "C" int __cdecl check(const char*, int, const char*, const char*, int);

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return check(s, 0, a, b, 0) != 0;
}
