// Same code shape as 0x0011a060 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b7a0;
struct Object_17b7a0 {
    u32_17b7a0 init(hulkfight::motion::TeleportRelativeTrack*, u32_17b7a0);
};
extern int MatchType(u32_17b7a0, int, const void*, const void*, int);
extern Object_17b7a0* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];

int hulkfight::motion::TeleportRelativeTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17b7a0 a = (u32_17b7a0)__p0; u32_17b7a0 b = (u32_17b7a0)__p1; u32_17b7a0 c = (u32_17b7a0)__p2;

    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        Object_17b7a0* p = Alloc(0x30);
        if (p)
            return (int)(p->init(this, c));
    }
    return (int)(0);
}
