#include "gen/global.h"

class ControllerPollerBase_ddb40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual bool f2();
    virtual bool f3();
    virtual bool f4(int, int);
    virtual void f5();
};

bool ControllerPoller::vfunc_3(int arg) {
    int i = 0;
    do {
        if (vfunc_4(arg, i))
            return true;
        ++i;
    } while (i < 1);
    return false;
}
