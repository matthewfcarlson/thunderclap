#include "gen/global.h"
#include "gen/owners.h"

class Obj_e6a60 {
  public:
};

void FEThingsBase::vfunc_13() {
    if ((*(Obj_e6a60 * *)&this->f_175c)) {
        this->f_1768 = 0;
        vfunc_48(4);
        this->f_17f8 = 0;
        this->f_176c = 2;
        ((owners::Fader_e5440 *)((*(Obj_e6a60 * *)&this->f_175c)))->FUN_000e5440(2);
    }
}
