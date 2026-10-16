#include "gen/global.h"

class Child_e4dd0 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual bool f7(int, int);
};

bool FEContainer::vfunc_3(int a, int b) {
    if (this->f_854 == -1 || this->f_854 == b) {
        if ((*(Child_e4dd0 * *)&this->f_48) != 0)
            return (*(Child_e4dd0 * *)&this->f_48)->f7(a, b);
    }
    return false;
}
