#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

class Helper_52010 {
  public:
    int second();
};

hulk_intptr CFightNodeCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    hulk_intptr x = ((int)((owners::Object_592a0 *)(((Helper_52010*)arg)))->FUN_000592a0());
    return ((Helper_52010*)x)->second() + 0xdc;
}
