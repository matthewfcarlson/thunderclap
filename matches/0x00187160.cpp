#include "gen/fight.h"

class Track_187160 {};
class Caster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
extern "C" void* __cdecl DynamicCast(void*, int, void*, void*, int);

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return DynamicCast(p, 0, (void*)0x49850c, (void*)0x4be240, 0) != 0;
}
