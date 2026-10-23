#include "gen/fight.h"

struct TypeDescriptor {
    char bytes[8];
};
extern TypeDescriptor sourceType;
extern TypeDescriptor targetType;
extern "C" void* __cdecl performCast(void*, long, TypeDescriptor*, TypeDescriptor*, int);
namespace fight {
class TrackFactoryCaster_6e690 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CStageTrack_6e690;
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CStageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return performCast(p, 0, &sourceType, &targetType, 0) != 0;
}
