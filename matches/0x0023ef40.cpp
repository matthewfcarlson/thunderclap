#include "gen/fight.h"

typedef unsigned int uint_23ef40;
struct Alloc_23ef40 {
    uint_23ef40 run(uint_23ef40, fight::SpawnTrack*, uint_23ef40);
};
extern Alloc_23ef40* FUN_0008d690(uint_23ef40);

int fight::SpawnTrack::vfunc_10(int __p0, int __p1, int __p2) { uint_23ef40 a = (uint_23ef40)__p0; uint_23ef40 b = (uint_23ef40)__p1; uint_23ef40 c = (uint_23ef40)__p2;

    Alloc_23ef40* p = FUN_0008d690(0x58);
    if (p)
        return (int)(p->run(a, this, c));
    return (int)(0);
}
