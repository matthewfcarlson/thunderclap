// Same code shape as 0x001421d0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_156ff0;
struct Helper_156ff0 {
    int run(hulkfight::motion::HitReactionFloatTrack*, u32_156ff0);
};
extern int __cdecl FUN_00344e74(u32_156ff0, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern const char RTTI1_156ff0[];
extern const char RTTI2_156ff0[];

int hulkfight::motion::HitReactionFloatTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_156ff0 a = (u32_156ff0)__p0; u32_156ff0 b = (u32_156ff0)__p1; u32_156ff0 c = (u32_156ff0)__p2;

    if (FUN_00344e74(c, 0, RTTI1_156ff0, RTTI2_156ff0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_156ff0*)p)->run(this, c);
    }
    return 0;
}
