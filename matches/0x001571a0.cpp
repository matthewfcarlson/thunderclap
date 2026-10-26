#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_1571a0;
extern int RTTI1_1571a0, RTTI2;
struct Result_1571a0 {
    u32_1571a0 setup(hulkfight::motion::HitPushbackTrack*, hulk_uintptr);
};
extern int check(void*, int, int*, int*, int);
extern Result_1571a0* alloc(int);

hulk_intptr hulkfight::motion::HitPushbackTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1571a0 a = (u32_1571a0)__p0; u32_1571a0 b = (u32_1571a0)__p1; hulk_uintptr c = (u32_1571a0)__p2;

    if (check((void*)c, 0, &RTTI1_1571a0, &RTTI2, 0)) {
        Result_1571a0* p = alloc(0x44);
        if (p)
            return (int)(p->setup(this, c));
    }
    return (int)(0);
}
