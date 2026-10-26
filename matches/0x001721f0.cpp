#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Holder_1721f0 {
  public:
    int first();
    int second();
};

bool hulkfight::motion::SuckInPropsAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    hulk_intptr value = (*(Holder_1721f0 * *)&this->f_20)->first();
    if (value == 0)
        return false;
    if (((Holder_1721f0*)value)->second() == 0)
        return false;
    return true;
}
