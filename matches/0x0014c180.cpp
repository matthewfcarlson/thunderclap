#include "gen/fight.h"

extern "C" char DAT_004136d8[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Track_14c180 {
  public:
    Track_14c180();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_5() {
    Track_14c180* p = (Track_14c180*)FUN_0008d690(0x10);
    if (p) {
        p->Track_14c180::Track_14c180();
        *(int*)p = ((int)DAT_004136d8);
        *((int*)p + 3) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
