#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class A_15cb80 {
  public:
};
class B_15cb80 {
  public:
    int second();
    void third(int);
};

bool hulkfight::motion::LocomotingAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    hulk_intptr x;
    if ((*(A_15cb80 * *)&this->f_1c) == 0)
        return false;
    x = ((int)((owners::Object_592a0 *)((*(A_15cb80 * *)&this->f_1c)))->FUN_000592a0());
    if (x == 0)
        return false;
    x = ((B_15cb80*)x)->second();
    if (x == 0)
        return false;
    ((B_15cb80*)x)->third(1);
    return true;
}
