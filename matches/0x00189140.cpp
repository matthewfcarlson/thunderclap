#include "gen/hulkfight.h"

struct Allocated_189140 {
    int run(hulkfight::motion::BallAndChainShootTrack*, int);
};
extern int check(void*, int, int*, int*, int);
extern Allocated_189140* alloc(int);
extern int typeA_189140, typeB;

int hulkfight::motion::BallAndChainShootTrack::vfunc_10(int a, int b, int c) {
    if (check((void*)c, 0, &typeA_189140, &typeB, 0)) {
        Allocated_189140* q = alloc(0x54);
        if (q)
            return q->run(this, c);
    }
    return 0;
}
