#include "gen/global.h"

class Gate_e30a0 {
  public:
    void H(int);
};

void TextSelector::FUN_000e30a0() {
    if ((*(Gate_e30a0 * *)&this->f_1d94))
        (*(Gate_e30a0 * *)&this->f_1d94)->H(this->f_154);
    vfunc_0();
}
