#include "gen/global.h"

class Obj_e6a60 {
  public:
    void run(int);
};

void FEThingsBase::vfunc_13() {
    if ((*(Obj_e6a60 * *)&this->f_175c)) {
        this->f_1768 = 0;
        vfunc_48(4);
        this->f_17f8 = 0;
        this->f_176c = 2;
        (*(Obj_e6a60 * *)&this->f_175c)->run(2);
    }
}
