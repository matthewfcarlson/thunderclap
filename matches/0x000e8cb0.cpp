#include "gen/global.h"

class Worker_e8cb0 {
  public:
    void run(int, int, int);
};
class FELayout_e8cb0 {
    char pad[0x44];
};

void SingleLayout::vfunc_10(int param) {
    Worker_e8cb0* p = (*(Worker_e8cb0 * *)&this->f_44);
    if (p)
        p->run(param, -1, -1);
}
