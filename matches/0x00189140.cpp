#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Allocated_189140 {
    int run(hulkfight::motion::BallAndChainShootTrack*, hulk_intptr);
};
extern int check(void*, int, int*, int*, int);
extern Allocated_189140* alloc(int);
extern int typeA_189140, typeB;

hulk_intptr hulkfight::motion::BallAndChainShootTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (check((void*)c, 0, &typeA_189140, &typeB, 0)) {
        Allocated_189140* q = alloc(0x54);
        if (q)
            return q->run(this, c);
    }
    return 0;
}
