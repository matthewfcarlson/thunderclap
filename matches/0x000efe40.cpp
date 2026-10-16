#include "gen/global.h"

extern void* __cdecl allocThing(unsigned int);
class Thing_efe40 {
  public:
    int init(int);
};

int FEThingsBase::vfunc_55(int x) {
    Thing_efe40* p = (Thing_efe40*)allocThing(0x2b0);
    if (p)
        return p->init(x);
    return 0;
}
