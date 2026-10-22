// Same code shape as 0x00161500 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct LocomotionSteerAction_161590 {
    int Init(hulkfight::motion::LocomotionSteerTrack*, int);
};
extern hulkfight::motion::LocomotionSteerAction* Alloc(unsigned int);

int hulkfight::motion::LocomotionSteerTrack::vfunc_10(int a, int b, int c) {
    hulkfight::motion::LocomotionSteerAction* p = Alloc(0x30);
    if (p)
        return ((LocomotionSteerAction_161590*)(p))->Init(this, c);
    return 0;
}
