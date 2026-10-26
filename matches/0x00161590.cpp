// Same code shape as 0x00161500 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct LocomotionSteerAction_nv_161590 {
    int Init(hulkfight::motion::LocomotionSteerTrack*, int);
};
extern hulkfight::motion::LocomotionSteerAction* Alloc(unsigned int);

hulk_intptr hulkfight::motion::LocomotionSteerTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    hulkfight::motion::LocomotionSteerAction* p = Alloc(0x30);
    if (p)
        return ((LocomotionSteerAction_nv_161590*)(((hulkfight::motion::LocomotionSteerAction*)(p))))->Init(this, c);
    return 0;
}
