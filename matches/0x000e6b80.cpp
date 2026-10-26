#include "compat/ptr.h"
#include "gen/global.h"

class Obj_e6b80 {
  public:
    void Helper(int);
};

void FEThingsBase::vfunc_19(hulk_intptr x) {
    if ((Obj_e6b80*)x != (*(Obj_e6b80 * *)&this->f_175c)) {
        this->f_1768 = x;
        if (x) {
            vfunc_27(x);
            this->f_17f8 = 3;
            this->f_176c = 2;
            if ((*(Obj_e6b80 * *)&this->f_175c))
                (*(Obj_e6b80 * *)&this->f_175c)->Helper(2);
        }
    }
}
