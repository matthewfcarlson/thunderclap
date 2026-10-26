// Same code shape as 0x001571a0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_17bbc0;
extern int RTTI1_17bbc0, RTTI2;
struct Result_17bbc0 {
    u32_17bbc0 setup(hulkfight::motion::SurfTrack*, hulk_uintptr);
};
extern int check(void*, int, int*, int*, int);
extern Result_17bbc0* alloc(int);

hulk_intptr hulkfight::motion::SurfTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17bbc0 a = (u32_17bbc0)__p0; u32_17bbc0 b = (u32_17bbc0)__p1; hulk_uintptr c = (u32_17bbc0)__p2;

    if (check((void*)c, 0, &RTTI1_17bbc0, &RTTI2, 0)) {
        Result_17bbc0* p = alloc(0x44);
        if (p)
            return (int)(p->setup(this, c));
    }
    return (int)(0);
}
