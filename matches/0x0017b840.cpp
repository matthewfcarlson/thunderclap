// Same code shape as 0x0011a060 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b840;
struct TeleportToLocatorAction_nv_17b840 {
    u32_17b840 init(hulkfight::motion::TeleportToLocatorTrack*, u32_17b840);
};
extern int MatchType(u32_17b840, int, const void*, const void*, int);
extern hulkfight::motion::TeleportToLocatorAction* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];

int hulkfight::motion::TeleportToLocatorTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17b840 a = (u32_17b840)__p0; u32_17b840 b = (u32_17b840)__p1; u32_17b840 c = (u32_17b840)__p2;

    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        hulkfight::motion::TeleportToLocatorAction* p = Alloc(0x30);
        if (p)
            return (int)(((TeleportToLocatorAction_nv_17b840*)(((hulkfight::motion::TeleportToLocatorAction*)(p))))->init(this, c));
    }
    return (int)(0);
}
