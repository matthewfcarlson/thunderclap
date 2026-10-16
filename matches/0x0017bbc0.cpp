// Same code shape as 0x001571a0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17bbc0;
extern int RTTI1_17bbc0, RTTI2;
struct Result_17bbc0 {
    u32_17bbc0 setup(hulkfight::motion::SurfTrack*, u32_17bbc0);
};
extern int check(void*, int, int*, int*, int);
extern Result_17bbc0* alloc(int);

int hulkfight::motion::SurfTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17bbc0 a = (u32_17bbc0)__p0; u32_17bbc0 b = (u32_17bbc0)__p1; u32_17bbc0 c = (u32_17bbc0)__p2;

    if (check((void*)c, 0, &RTTI1_17bbc0, &RTTI2, 0)) {
        Result_17bbc0* p = alloc(0x44);
        if (p)
            return (int)(p->setup(this, c));
    }
    return (int)(0);
}
