#include "gen/hulkfight.h"

class Obj_14f660 {
  public:
    Obj_14f660* A();
    Obj_14f660* B();
    void C(int);
};

void hulkfight::motion::NoHitPushbackAction::vfunc_4() {
    Obj_14f660* p = (*(Obj_14f660 * *)&this->f_20);
    if (p) {
        p = p->A();
        p = p->B();
        p->C(0);
    }
}
