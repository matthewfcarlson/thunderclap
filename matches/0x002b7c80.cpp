// Same code shape as 0x000e9100 (propagated; names are from that function)
#include "gen/pure3d.h"

class Thing_2b7c80 {
  public:
    virtual void A();
    virtual void B();
};

void pure3d::PolySkin::vfunc_10(int __p0) { Thing_2b7c80 * p = (Thing_2b7c80 *)__p0;

    if (p)
        p->A();
    if ((*(Thing_2b7c80 * *)&this->f_60))
        (*(Thing_2b7c80 * *)&this->f_60)->B();
    (*(Thing_2b7c80 * *)&this->f_60) = p;
}
