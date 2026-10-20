// Same code shape as 0x001617c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int RTTI1_17bb40;
extern int RTTI2_17bb40;
struct TargetBreakAction_nv_17bb40 {
    int Make(void*);
};
extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern hulkfight::motion::TargetBreakAction* __cdecl FUN_0008d690(unsigned int);

int hulkfight::motion::TargetBreakTrack::vfunc_10(int __p0, int __p1, int __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    if (FUN_00344e74(c, 0, &RTTI1_17bb40, &RTTI2_17bb40, 0)) {
        hulkfight::motion::TargetBreakAction* p = FUN_0008d690(0x20);
        if (p)
            return ((TargetBreakAction_nv_17bb40*)(p))->Make(c);
    }
    return 0;
}
