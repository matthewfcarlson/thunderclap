#include "gen/fight.h"

extern "C" int __cdecl CastCheck(void*, void*, void*, void*, void*);
extern char a, b;
namespace fight {
class TrackFactoryCaster_1548a0 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastCheck(p, 0, &a, &b, 0) != 0;
}
