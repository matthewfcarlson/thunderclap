// Same code shape as 0x002762d0 (propagated; names are from that function)
#include "gen/core.h"

class Inner_277030 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

void core::InstanceDrive::vfunc_39() {
    (*(Inner_277030 * *)&this->f_0c)->f4();
}
