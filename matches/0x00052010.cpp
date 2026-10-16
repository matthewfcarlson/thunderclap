#include "gen/global.h"

class Helper_52010 {
  public:
    int first();
    int second();
};

int CFightNodeCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    int x = ((Helper_52010*)arg)->first();
    return ((Helper_52010*)x)->second() + 0xdc;
}
