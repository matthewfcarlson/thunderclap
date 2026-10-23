#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_138c50;
struct FallAction_nv_138c50 {
    int init(hulkfight::motion::FallTrack*, u32_138c50);
};
extern int __cdecl check(u32_138c50, int, const void*, const void*, int);
extern void* __cdecl alloc(hulk_uintptr);
extern const int typeA_138c50;
extern const int typeB_138c50;

int hulkfight::motion::FallTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_138c50 a = (u32_138c50)__p0; u32_138c50 b = (u32_138c50)__p1; u32_138c50 c = (u32_138c50)__p2;

    if (check(c, 0, &typeA_138c50, &typeB_138c50, 0)) {
        hulkfight::motion::FallAction* p = (hulkfight::motion::FallAction*)alloc(0x38);
        if (p)
            return ((FallAction_nv_138c50*)(((hulkfight::motion::FallAction*)(p))))->init(this, c);
    }
    return 0;
}
