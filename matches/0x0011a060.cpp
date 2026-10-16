#include "gen/hulkfight.h"

typedef unsigned int u32_11a060;
struct Object_11a060 {
    u32_11a060 init(hulkfight::ai::MotionLocatorTrack*, u32_11a060);
};
extern int MatchType(u32_11a060, int, const void*, const void*, int);
extern Object_11a060* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];

int hulkfight::ai::MotionLocatorTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_11a060 a = (u32_11a060)__p0; u32_11a060 b = (u32_11a060)__p1; u32_11a060 c = (u32_11a060)__p2;

    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        Object_11a060* p = Alloc(0x30);
        if (p)
            return (int)(p->init(this, c));
    }
    return (int)(0);
}
