#include "gen/global.h"

class Child_e4d20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
    virtual void f9();
    virtual void f10(int);
};
struct FEContainer_nv_e4d20 {
    void helper();
};

void FEContainer::vfunc_14() {
    ((FEContainer_nv_e4d20*)this)->helper();
    if ((*(Child_e4d20 * *)&this->f_48)) {
        (*(Child_e4d20 * *)&this->f_48)->f8(0);
        (*(Child_e4d20 * *)&this->f_48)->f10(2);
    }
}
