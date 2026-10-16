#include "gen/pure3d.h"

class Obj_2a35d0 {
  public:
    virtual void f0();
    virtual void f1();
};

void pure3d::DrawableHierarchy::vfunc_14() {
    if ((*(Obj_2a35d0 * *)&this->f_10)) {
        (*(Obj_2a35d0 * *)&this->f_10)->f1();
        (*(Obj_2a35d0 * *)&this->f_10) = 0;
    }
}
