#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int U_1224b0;
extern int g1_1224b0;
extern int g2_1224b0;

struct NewObj_1224b0 {
    U_1224b0 Init(hulkfight::ai::RoutTrack*, hulk_uintptr);
};
extern int IsType(void*, int, int*, int*, int);
extern NewObj_1224b0* Allocate(int);

int hulkfight::ai::RoutTrack::vfunc_10(int __p0, int __p1, int __p2) { U_1224b0 a = (U_1224b0)__p0; U_1224b0 b = (U_1224b0)__p1; hulk_uintptr c = (U_1224b0)__p2;

    if (IsType((void*)c, 0, &g1_1224b0, &g2_1224b0, 0)) {
        NewObj_1224b0* p = Allocate(0xb8);
        if (p)
            return (int)(p->Init(this, c));
    }
    return (int)(0);
}
