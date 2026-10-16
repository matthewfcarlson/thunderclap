#include "gen/pure3d.h"

class Inner_2df240 {
  public:
    void f();
};

void pure3d::ShadowSkin::vfunc_24() {
    Inner_2df240* p = (*(Inner_2df240 * *)&this->f_48);
    Inner_2df240* q = (Inner_2df240*)*(volatile void* const volatile*)p;
    q->f();
}
