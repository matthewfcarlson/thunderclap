#include "gen/pure3d.h"

class Child_296930 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};
class Callback_296930 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};

void pure3d::scenegraph::TransformNode::vfunc_9() {
    if ((*(Callback_296930 * *)&this->f_a8))
        (*(Callback_296930 * *)&this->f_a8)->f23();
    (*(unsigned int *)&this->f_10) &= 0xfffffffe;
    for (unsigned int i = 0; i < this->f_18; ++i)
        (*(Child_296930 ** *)&this->f_1c)[i]->f9();
}
