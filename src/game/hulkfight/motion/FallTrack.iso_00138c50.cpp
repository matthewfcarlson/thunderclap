// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00138c50 hulkfight::motion::FallTrack::vfunc_10 (70 B): matches/0x00138c50.cpp [isolated: conflict: check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@FallTrack@motion@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

typedef unsigned int u32_138c50;
struct FallAction_nv_138c50 {
    int init_00134e30(hulkfight::motion::FallTrack*, u32_138c50);
};
extern int __cdecl check(u32_138c50, int, const void*, const void*, int);
extern void* __cdecl alloc(hulk_uintptr);
extern const int hulk_at_00494b44;
extern const int hulk_at_00494b60;

hulk_intptr hulkfight::motion::FallTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_138c50 a = (u32_138c50)__p0; u32_138c50 b = (u32_138c50)__p1; u32_138c50 c = (u32_138c50)__p2;

    if (check(c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::motion::FallAction* p = (hulkfight::motion::FallAction*)alloc(0x38);
        if (p)
            return ((FallAction_nv_138c50*)(((hulkfight::motion::FallAction*)(p))))->init_00134e30(this, c);
    }
    return 0;
}

