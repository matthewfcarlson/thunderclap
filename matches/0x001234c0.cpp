#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct PathFormationAction_nv_1234c0 {
    int build(hulkfight::ai::PathFormationTrack*, int);
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
