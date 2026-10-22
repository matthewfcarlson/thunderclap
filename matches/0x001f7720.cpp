#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00424d4c[];
class Function_1f7720 {
  public:
    Function_1f7720(int, int);
};
extern char sA[];
extern char sB[];
extern char sC[];
class Method3_1f7720 : public Function_1f7720 {
  public:
    Method3_1f7720(int, int);
    char pad0[0x10];
    char m10, m11, m12;
    char pad13[5];
    char m18;
    char pad19[3];
    int m1c;
};
Method3_1f7720::Method3_1f7720(int a, int b) : Function_1f7720(a, 3) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00424d4c);
    m1c = b;
    m18 = FUN_001d04d0(sA);
    m10 = FUN_001d04d0(sB);
    m11 = FUN_001d04d0(sC);
    m12 = FUN_001d04d0(sC);
}