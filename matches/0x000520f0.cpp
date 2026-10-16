// Same code shape as 0x00052010 (propagated; names are from that function)
#include "gen/global.h"

class Helper_520f0 {
  public:
    int first();
    int second();
};

int CFightNodeParentCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    int x = ((Helper_520f0*)arg)->first();
    return ((Helper_520f0*)x)->second() + 0xdc;
}
