#include "compat/ptr.h"
class Base_1c4160 {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_1c4160 {
  public:
    char pad[0x10];
    Base_1c4160* member;
    hulk_intptr target(unsigned char flag);
};
void thunk(Obj_1c4160*);
hulk_intptr Obj_1c4160::target(unsigned char flag) {
    if (member)
        member->f1();
    member = 0;
    if (flag & 1)
        thunk(this);
    return (hulk_intptr)this;
}