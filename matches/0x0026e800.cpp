#include "gen/core.h"

class Helper_26e800 {
  public:
    void call(void*, unsigned int);
};

void core::DebugConsole::vfunc_7(int param) {
    int local[3];
    local[0] = 5;
    local[1] = (int)this;
    local[2] = param;
    (*(Helper_26e800 * *)&this->f_a4)->call(local, 12);
    this->f_98 = param;
}
