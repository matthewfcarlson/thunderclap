#include "gen/global.h"

class Child_e20f0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void callme(int);
};
class FELayout_e20f0 {
  public:
    virtual void f0();
    char pad[0x40];
    Child_e20f0* child;
};

void SingleLayout::vfunc_9(int x) {
    if ((*(Child_e20f0 * *)&this->f_44))
        (*(Child_e20f0 * *)&this->f_44)->callme(x);
}
