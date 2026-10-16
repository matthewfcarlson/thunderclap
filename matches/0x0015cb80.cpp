#include "gen/hulkfight.h"

class A_15cb80 {
  public:
    int first();
};
class B_15cb80 {
  public:
    int second();
    void third(int);
};

bool hulkfight::motion::LocomotingAction::vfunc_3(int __p0, int __p1) {
    int x;
    if ((*(A_15cb80 * *)&this->f_1c) == 0)
        return false;
    x = (*(A_15cb80 * *)&this->f_1c)->first();
    if (x == 0)
        return false;
    x = ((B_15cb80*)x)->second();
    if (x == 0)
        return false;
    ((B_15cb80*)x)->third(1);
    return true;
}
