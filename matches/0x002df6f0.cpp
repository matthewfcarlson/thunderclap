#include "compat/ptr.h"
#include "gen/pure3d.h"

class Helper_2df6f0 {
  public:
    void go(int, int, int);
};

void pure3d::PrimGroupSkinnedStreamed::vfunc_12(int arg) {
    ((Helper_2df6f0*)(*(hulk_intptr *)&this->f_5c))->go(arg, this->f_60, this->f_64);
}
