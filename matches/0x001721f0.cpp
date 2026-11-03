#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class Holder_1721f0 {
  public:
    int second();
};

bool hulkfight::motion::SuckInPropsAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    hulk_intptr value = ((int)((owners::Object_592a0 *)((*(Holder_1721f0 * *)&this->f_20)))->FUN_000592a0());
    if (value == 0)
        return false;
    if (((Holder_1721f0*)value)->second() == 0)
        return false;
    return true;
}
