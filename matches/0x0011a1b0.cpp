#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct TypeInfo_11a1b0 {
    int x;
};
extern TypeInfo_11a1b0 CFightParamsType_11a1b0;
extern TypeInfo_11a1b0 FightParamsType_11a1b0;
int __cdecl IsType(void*, int, TypeInfo_11a1b0*, TypeInfo_11a1b0*, int);
void* __cdecl Allocate(int);
class Allocated_11a1b0 {
  public:
    int Init(hulkfight::ai::MotionClosestWaypointTrack*, void*);
};

hulk_intptr hulkfight::ai::MotionClosestWaypointTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * p = (void *)__p2;

    int ok = IsType(p, 0, &FightParamsType_11a1b0, &CFightParamsType_11a1b0, 0);
    if (ok) {
        Allocated_11a1b0* x = (Allocated_11a1b0*)Allocate(0x68);
        if (x)
            return x->Init(this, p);
    }
    return 0;
}
