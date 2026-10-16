#include "gen/fight.h"

class Inner_23b8e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(unsigned int*);
    virtual void f7(unsigned int*);
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
};

bool fight::IFileDataReader::vfunc_5() {
    unsigned int b, a;
    (*(Inner_23b8e0 * *)&this->f_08)->f21();
    (*(Inner_23b8e0 * *)&this->f_08)->f6(&a);
    (*(Inner_23b8e0 * *)&this->f_08)->f7(&b);
    (*(Inner_23b8e0 * *)&this->f_08)->f21();
    return a >= b;
}
