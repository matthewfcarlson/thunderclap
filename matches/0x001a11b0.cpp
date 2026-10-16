#include "gen/fight.h"

typedef unsigned int u32_1a11b0;
struct Track_1a11b0 {
    char x[0x148];
    u32_1a11b0 Init();
};
void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FireMissileTrack>::vfunc_5() {
    Track_1a11b0* p = (Track_1a11b0*)::operator new(0x148);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}
