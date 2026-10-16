#include "gen/fight.h"

class Condition_23d4e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int, int, int);
};

bool fight::DebugCondition::vfunc_6(void* __p0, void* __p1, void* __p2) {
    switch (this->f_0c) {
    case 0:
        return this->f_10 == 2;
    case 1:
        return this->f_10 != 2;
    default:
        return false;
    }
}
