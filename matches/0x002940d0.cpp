#include "gen/owners.h"
class Inner_2940d0 {
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
    virtual unsigned int Get();
};
class Helper_2940d0 {
  public:
};
class Owner_2940d0 {
  public:
    char pad[0x18];
    Inner_2940d0* ptr;
    void Target(void* out, Helper_2940d0* h);
};
void Owner_2940d0::Target(void* out, Helper_2940d0* h) {
    if (ptr)
        ((owners::C_22d240 *)h)->FUN_0022d240((hulk_intptr)out, (hulk_intptr)(ptr->Get()));
}