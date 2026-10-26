#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Result_161500 {
    int Init(hulkfight::motion::LocomotionSprintTrack*, int);
};
extern Result_161500* Alloc(unsigned int);

hulk_intptr hulkfight::motion::LocomotionSprintTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    Result_161500* p = Alloc(0x30);
    if (p)
        return p->Init(this, c);
    return 0;
}
