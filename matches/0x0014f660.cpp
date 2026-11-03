#include "gen/hulkfight.h"
#include "gen/owners.h"

class Obj_14f660 {
  public:
    Obj_14f660* B();
    void C(int);
};

void hulkfight::motion::NoHitPushbackAction::vfunc_4() {
    Obj_14f660* p = (*(Obj_14f660 * *)&this->f_20);
    if (p) {
        p = ((Obj_14f660 *)((owners::Object_592a0 *)p)->FUN_000592a0());
        p = p->B();
        p->C(0);
    }
}
