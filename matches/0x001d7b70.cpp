#include "gen/pure3d.h"

class Inner_1d7b70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int f7();
};
namespace pure3d { namespace prop {  }}
char pure3d::prop::StateProp::vfunc_7() {
    return (char)((*(Inner_1d7b70 * *)&this->f_9c)->f7());
}
