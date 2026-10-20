#include "compat/ptr.h"
extern "C" char DAT_0042fb54[];
typedef unsigned int U_2df4d0;
class Base_2df4d0 {
  public:
    char pad[0x40];
    Base_2df4d0();
};
class PrimGroup : public Base_2df4d0 {
  public:
    U_2df4d0 a, b, c, d, e;
    PrimGroup(U_2df4d0 x, U_2df4d0 y);
};
PrimGroup::PrimGroup(U_2df4d0 x, U_2df4d0 y) {
    a = 0;
    b = 0;
    c = x;
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042fb54);
    d = y;
    e = 0xffffffff;
}