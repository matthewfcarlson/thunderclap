// Same code shape as 0x0011a060 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_121f40;
struct StrafeRunAction_nv_121f40 {
    u32_121f40 init(hulkfight::ai::StrafeRunTrack*, u32_121f40);
};
extern int MatchType(u32_121f40, int, const void*, const void*, int);
extern hulkfight::ai::StrafeRunAction* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];

hulk_intptr hulkfight::ai::StrafeRunTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_121f40 a = (u32_121f40)__p0; u32_121f40 b = (u32_121f40)__p1; u32_121f40 c = (u32_121f40)__p2;

    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        hulkfight::ai::StrafeRunAction* p = Alloc(0x30);
        if (p)
            return (int)(((StrafeRunAction_nv_121f40*)(((hulkfight::ai::StrafeRunAction*)(p))))->init(this, c));
    }
    return (int)(0);
}
