#include "gen/core.h"

class Pad_2693f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
    char rest[0x49c];
};

int core::ControllerSystemXBox::vfunc_3() {
    int n = 0;
    for (int i = 0; i < 4; ++i)
        if ((*(Pad_2693f0 (*)[4])&this->f_20)[i].f3())
            ++n;
    return n;
}
