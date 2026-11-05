#include "compat/ptr.h"
class C_1048d0 {
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
    char pad[0x58];
    int value;
    void set(hulk_intptr x);
};
void C_1048d0::set(hulk_intptr x) {
    if (value != x) {
        f9();
        value = x;
    }
}