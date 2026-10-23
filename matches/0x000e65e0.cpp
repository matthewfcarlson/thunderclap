#include "gen/global.h"

typedef unsigned int u32_e65e0;
extern void* __cdecl allocThing(u32_e65e0);
class Thing_e65e0 {
  public:
    u32_e65e0 initialize();
};

int FEThingsBase::vfunc_61(int __p0) {
    Thing_e65e0* p = (Thing_e65e0*)allocThing(0x800);
    if (p)
        return (int)(p->initialize());
    return (int)(0);
}
