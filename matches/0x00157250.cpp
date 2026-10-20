// Same code shape as 0x00138c50 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_157250;
struct Created_157250 {
    int init(hulkfight::motion::HitFloatTrack*, u32_157250);
};
extern int __cdecl check(u32_157250, int, const void*, const void*, int);
extern void* __cdecl alloc(hulk_uintptr);
extern const int typeA_157250;
extern const int typeB_157250;

int hulkfight::motion::HitFloatTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_157250 a = (u32_157250)__p0; u32_157250 b = (u32_157250)__p1; u32_157250 c = (u32_157250)__p2;

    if (check(c, 0, &typeA_157250, &typeB_157250, 0)) {
        Created_157250* p = (Created_157250*)alloc(0x38);
        if (p)
            return p->init(this, c);
    }
    return 0;
}
