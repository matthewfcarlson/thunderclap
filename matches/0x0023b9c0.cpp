// Same code shape as 0x0023b410 (propagated; names are from that function)
#include "gen/fight.h"

class Inner_23b9c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

void fight::BinReader::vfunc_18() {
    (*(Inner_23b9c0 * *)&this->f_08)->f3();
}
