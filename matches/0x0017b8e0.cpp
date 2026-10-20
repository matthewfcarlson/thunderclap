// Same code shape as 0x001421d0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b8e0;
struct Helper_17b8e0 {
    int run(hulkfight::motion::SyncToLocatorTrack*, u32_17b8e0);
};
extern int __cdecl FUN_00344e74(u32_17b8e0, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_17b8e0[];
extern const char RTTI2_17b8e0[];

int hulkfight::motion::SyncToLocatorTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17b8e0 a = (u32_17b8e0)__p0; u32_17b8e0 b = (u32_17b8e0)__p1; u32_17b8e0 c = (u32_17b8e0)__p2;

    if (FUN_00344e74(c, 0, RTTI1_17b8e0, RTTI2_17b8e0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_17b8e0*)p)->run(this, c);
    }
    return 0;
}
