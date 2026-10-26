#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int uint_23ef40;
struct Alloc_23ef40 {
    uint_23ef40 run(uint_23ef40, fight::SpawnTrack*, uint_23ef40);
};
extern Alloc_23ef40* FUN_0008d690(uint_23ef40);

hulk_intptr fight::SpawnTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { uint_23ef40 a = (uint_23ef40)__p0; uint_23ef40 b = (uint_23ef40)__p1; uint_23ef40 c = (uint_23ef40)__p2;

    Alloc_23ef40* p = FUN_0008d690(0x58);
    if (p)
        return (int)(p->run(a, this, c));
    return (int)(0);
}
