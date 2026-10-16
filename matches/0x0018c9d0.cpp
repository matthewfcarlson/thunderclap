#include "gen/fight.h"

typedef unsigned int U32_18c9d0;
struct Obj_18c9d0 {
    U32_18c9d0 run();
};
extern void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_5() {
    Obj_18c9d0* p = (Obj_18c9d0*)operator new(0x98);
    if (p)
        return (void*)(p->run());
    return (void*)(0);
}
