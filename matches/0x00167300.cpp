#include "gen/hulkfight.h"
#include "gen/owners.h"

class Obj {
  public:
};
class Mid {
  public:
    Obj* get();
};
class Arg {
  public:
    Mid* get();
};

bool hulkfight::motion::LocomotionMotionStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; Arg * b = (Arg *)__p1; int c = (int)__p2;

    Obj* p = b->get()->get();
    int x = this->locomotionMotionState;
    switch (this->compare) {
    case 0:
        return ((int)((owners::Widget_35910 *)p)->FUN_00035910()) == x;
    case 1:
        return ((int)((owners::Widget_35910 *)p)->FUN_00035910()) != x;
    default:
        return false;
    }
}
