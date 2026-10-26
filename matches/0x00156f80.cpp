// Same code shape as 0x001421d0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_156f80;
struct Helper_156f80 {
    int run(hulkfight::motion::HitReactionTrack*, u32_156f80);
};
extern int __cdecl FUN_00344e74(u32_156f80, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_156f80[];
extern const char RTTI2_156f80[];

hulk_intptr hulkfight::motion::HitReactionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_156f80 a = (u32_156f80)__p0; u32_156f80 b = (u32_156f80)__p1; u32_156f80 c = (u32_156f80)__p2;

    if (FUN_00344e74(c, 0, RTTI1_156f80, RTTI2_156f80, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_156f80*)p)->run(this, c);
    }
    return 0;
}
