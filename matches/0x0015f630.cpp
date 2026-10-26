// Same code shape as 0x0011a1b0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct TypeInfo_15f630 {
    int x;
};
extern TypeInfo_15f630 CFightParamsType_15f630;
extern TypeInfo_15f630 FightParamsType_15f630;
int __cdecl IsType(void*, int, TypeInfo_15f630*, TypeInfo_15f630*, int);
void* __cdecl Allocate(int);
class Allocated_15f630 {
  public:
    int Init(hulkfight::motion::HeliLocomotionTrack*, void*);
};

hulk_intptr hulkfight::motion::HeliLocomotionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * p = (void *)__p2;

    int ok = IsType(p, 0, &FightParamsType_15f630, &CFightParamsType_15f630, 0);
    if (ok) {
        Allocated_15f630* x = (Allocated_15f630*)Allocate(0x68);
        if (x)
            return x->Init(this, p);
    }
    return 0;
}
