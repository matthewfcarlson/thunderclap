// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011fa30..0x00123510 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathLocatorTestCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001234c0 hulkfight::ai::PathFormationTrack::vfunc_10 (73 B): matches/0x001234c0.cpp [isolated: conflict: check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PathFormationTrack@ai@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

struct PathFormationAction_nv_1234c0 {
    int build_001233a0(hulkfight::ai::PathFormationTrack*, hulk_intptr);
};
extern int check(void*, int, const void*, const void*, int);
extern void* alloc_0008d690(int);
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;

hulk_intptr hulkfight::ai::PathFormationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::ai::PathFormationTrack* p = (hulkfight::ai::PathFormationTrack*)alloc_0008d690(0xd0);
        if (p)
            return ((PathFormationAction_nv_1234c0*)(((hulkfight::ai::PathFormationAction*)(((hulkfight::ai::PathFormationAction*)(p))))))->build_001233a0(this, c);
    }
    return 0;
}

