#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

class Helper_48650 {
  public:
    int second();
};

void CAxisCondition::vfunc_8(hulk_intptr arg) {
    Helper_48650* h = ((Helper_48650 *)((owners::Object_592a0 *)(((Helper_48650*)arg)))->FUN_000592a0());
    int v = h->second();
    vfunc_9(v, v + this->f_0c * 0x38 + 0x1ff4);
}
