// Same code shape as 0x002df6f0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

class Helper_2df710 {
  public:
    void go(int, int, int);
};

void pure3d::PrimGroupSkinnedStreamed::vfunc_11(int arg) {
    ((Helper_2df710*)(*(hulk_intptr *)&this->f_5c))->go(arg, this->f_60, this->f_64);
}
