#include "gen/core.h"

class Helper_26e750 {
  public:
    void run(void*, unsigned int);
};

void core::DebugConsole::vfunc_4(unsigned int p) {
    struct Data {
        unsigned int a, b, c;
    } d;
    d.a = 2;
    d.b = (unsigned int)this;
    d.c = p;
    (*(Helper_26e750 * *)&this->f_a4)->run(&d, 12);
    this->f_94 = p;
}
