#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_1421d0;
struct Helper_1421d0 {
    int run(hulkfight::motion::WallRunTrack*, u32_1421d0);
};
extern int __cdecl FUN_00344e74(u32_1421d0, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_1421d0[];
extern const char RTTI2_1421d0[];

hulk_intptr hulkfight::motion::WallRunTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1421d0 a = (u32_1421d0)__p0; u32_1421d0 b = (u32_1421d0)__p1; u32_1421d0 c = (u32_1421d0)__p2;

    if (FUN_00344e74(c, 0, RTTI1_1421d0, RTTI2_1421d0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_1421d0*)p)->run(this, c);
    }
    return 0;
}
