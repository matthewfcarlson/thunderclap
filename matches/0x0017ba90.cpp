// Same code shape as 0x001421d0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_17ba90;
struct Helper_17ba90 {
    int run(hulkfight::motion::MoveJointTrack*, u32_17ba90);
};
extern int __cdecl FUN_00344e74(u32_17ba90, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern const char RTTI1_17ba90[];
extern const char RTTI2_17ba90[];

int hulkfight::motion::MoveJointTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17ba90 a = (u32_17ba90)__p0; u32_17ba90 b = (u32_17ba90)__p1; u32_17ba90 c = (u32_17ba90)__p2;

    if (FUN_00344e74(c, 0, RTTI1_17ba90, RTTI2_17ba90, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_17ba90*)p)->run(this, c);
    }
    return 0;
}
