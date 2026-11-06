#include "gen/fight.h"
extern char DAT_0049850c;
extern char DAT_004be240;

class Track_187160 {};
class Caster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
extern "C" void* __cdecl DynamicCast(void*, int, void*, void*, int);

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return DynamicCast(p, 0, (void*)&DAT_0049850c, (void*)&DAT_004be240, 0) != 0;
}
