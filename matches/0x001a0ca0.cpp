#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_1a0ca0;
extern int __cdecl Check(void*, int, const void*, const void*, int);
extern void* __cdecl Alloc(hulk_uintptr);
struct NewThing {
    int Init(hulkfight::motion::FireBeamTrack*, void*);
};
extern int rttiA_1a0ca0;
extern int rttiB;

int hulkfight::motion::FireBeamTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_1a0ca0 a = (u32_1a0ca0)__p0; u32_1a0ca0 b = (u32_1a0ca0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &rttiA_1a0ca0, &rttiB, 0)) {
        NewThing* q = (NewThing*)Alloc(0x98);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}
