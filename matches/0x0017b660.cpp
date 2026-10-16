// Same code shape as 0x00138c50 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b660;
struct Created_17b660 {
    int init(hulkfight::motion::DriftToHulkTrack*, u32_17b660);
};
extern int __cdecl check(u32_17b660, int, const void*, const void*, int);
extern void* __cdecl alloc(unsigned int);
extern const int typeA_17b660;
extern const int typeB_17b660;

int hulkfight::motion::DriftToHulkTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17b660 a = (u32_17b660)__p0; u32_17b660 b = (u32_17b660)__p1; u32_17b660 c = (u32_17b660)__p2;

    if (check(c, 0, &typeA_17b660, &typeB_17b660, 0)) {
        Created_17b660* p = (Created_17b660*)alloc(0x38);
        if (p)
            return p->init(this, c);
    }
    return 0;
}
