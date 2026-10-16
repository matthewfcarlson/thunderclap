#include "gen/global.h"

class Inner_e4da0 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual bool f6(int, int);
};

bool FEContainer::vfunc_2(int a, int b) {
    if ((this->f_854 == -1 || this->f_854 == b) && (*(Inner_e4da0 * *)&this->f_48) != 0)
        return (*(Inner_e4da0 * *)&this->f_48)->f6(a, b);
    return false;
}
