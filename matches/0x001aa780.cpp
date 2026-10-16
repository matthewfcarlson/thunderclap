#include "gen/fight.h"

extern void* operator new(unsigned int);
class Track_1aa780 {
  public:
    int make();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_5() {
    Track_1aa780* p = (Track_1aa780*)operator new(0x198);
    if (p)
        return (void*)(p->make());
    return (void*)(0);
}
