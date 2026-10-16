#include "gen/global.h"

class Thing_efe60 {
  public:
    int init(int);
};
extern void* __cdecl alloc(int);

int FEThingsBase::vfunc_57(int x) {
    Thing_efe60* p = (Thing_efe60*)alloc(0x1f8);
    if (p)
        return p->init(x);
    return 0;
}
