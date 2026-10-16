#include "gen/hulkfight.h"

extern int RTTI1_1617c0;
extern int RTTI2_1617c0;
class Result_1617c0 {
  public:
    int Make(void*);
};
extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern Result_1617c0* __cdecl FUN_0008d690(unsigned int);

int hulkfight::motion::LocomotingTrack::vfunc_10(int __p0, int __p1, int __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    if (FUN_00344e74(c, 0, &RTTI1_1617c0, &RTTI2_1617c0, 0)) {
        Result_1617c0* p = FUN_0008d690(0x20);
        if (p)
            return p->Make(c);
    }
    return 0;
}
