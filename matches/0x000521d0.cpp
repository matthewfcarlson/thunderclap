// Same code shape as 0x00052010 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class Helper_521d0 {
  public:
    int first();
    int second();
};

int CFightNodeTimeCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    hulk_intptr x = ((Helper_521d0*)arg)->first();
    return ((Helper_521d0*)x)->second() + 0xdc;
}
