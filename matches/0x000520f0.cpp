// Same code shape as 0x00052010 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

class Helper_520f0 {
  public:
    int second();
};

hulk_intptr CFightNodeParentCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    hulk_intptr x = ((int)((owners::Object_592a0 *)(((Helper_520f0*)arg)))->FUN_000592a0());
    return ((Helper_520f0*)x)->second() + 0xdc;
}
