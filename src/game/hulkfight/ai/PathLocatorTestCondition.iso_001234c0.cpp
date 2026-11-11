// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011fa30..0x00123510 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathLocatorTestCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001234c0 hulkfight::ai::PathFormationTrack::vfunc_10 (73 B): matches/0x001234c0.cpp [isolated: conflict: check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PathFormationTrack@ai@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

struct PathFormationAction_nv_1234c0 {
    int build(hulkfight::ai::PathFormationTrack*, hulk_intptr);
};
extern int check(void*, int, const void*, const void*, int);
extern void* alloc(int);
extern int RTTI_A;
extern int RTTI_B;

hulk_intptr hulkfight::ai::PathFormationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (check((void*)c, 0, &RTTI_A, &RTTI_B, 0)) {
        hulkfight::ai::PathFormationTrack* p = (hulkfight::ai::PathFormationTrack*)alloc(0xd0);
        if (p)
            return ((PathFormationAction_nv_1234c0*)(((hulkfight::ai::PathFormationAction*)(((hulkfight::ai::PathFormationAction*)(p))))))->build(this, c);
    }
    return 0;
}

