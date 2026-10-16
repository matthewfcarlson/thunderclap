#include "gen/fight.h"

typedef unsigned int u32_139860;
struct Init_139860 {
    u32_139860 run();
};
extern void* alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FallTrack>::vfunc_5() {
    void* p = alloc(0x4c);
    if (p)
        return (void*)(((Init_139860*)p)->run());
    return (void*)(0);
}
