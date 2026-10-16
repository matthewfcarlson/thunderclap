#include "decls/address.h"
extern "C" char DAT_00424d4c[];
class Base_1f7720 {
  public:
    Base_1f7720(int, int);
};
extern char sA[];
extern char sB[];
extern char sC[];
class Obj_1f7720 : public Base_1f7720 {
  public:
    Obj_1f7720(int, int);
    char pad0[0x10];
    char m10, m11, m12;
    char pad13[5];
    char m18;
    char pad19[3];
    int m1c;
};
Obj_1f7720::Obj_1f7720(int a, int b) : Base_1f7720(a, 3) {
    *(int*)this = ((int)DAT_00424d4c);
    m1c = b;
    m18 = FUN_001d04d0(sA);
    m10 = FUN_001d04d0(sB);
    m11 = FUN_001d04d0(sC);
    m12 = FUN_001d04d0(sC);
}