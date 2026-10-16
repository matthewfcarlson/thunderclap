#include "gen/core.h"

class Helper_26e7c0 {
  public:
    void run(void*, int);
};

void core::DebugConsole::vfunc_6(int a, int b) {
    int local[4];
    local[0] = 4;
    local[1] = (int)this;
    local[2] = a;
    local[3] = b;
    (*(Helper_26e7c0 * *)&this->f_a4)->run(local, 16);
}
