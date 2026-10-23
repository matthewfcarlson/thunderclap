#include "gen/hulkfight.h"

class Obj {
  public:
    int value();
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
    int x = this->f_10;
    switch (this->f_0c) {
    case 0:
        return p->value() == x;
    case 1:
        return p->value() != x;
    default:
        return false;
    }
}
