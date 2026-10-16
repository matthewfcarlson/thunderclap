#include "gen/global.h"

class Callback_f8dd0 {
  public:
    virtual void call(int);
};

void NamedValueInt::vfunc_1() {
    this->f_40 = this->f_44;
    if ((*(Callback_f8dd0 * *)&this->f_48))
        (*(Callback_f8dd0 * *)&this->f_48)->call(this->f_44);
    vfunc_0();
}
