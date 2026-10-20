#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00423468[];
class Method3_1e0ac0 {
  public:
    int x;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
    void Init(int, int);
    Method3_1e0ac0* Run(int, int);
};
extern const char s0_1e0ac0[];
extern const char s1_1e0ac0[];
extern const char s2_1e0ac0[];
extern const char s3_1e0ac0[];
Method3_1e0ac0* Method3_1e0ac0::Run(int a, int b) {
    Init(a, 3);
    x = ((hulk_intptr)DAT_00423468);
    m1c = b;
    b18 = FUN_001d04d0(s0_1e0ac0);
    b10 = FUN_001d04d0(s1_1e0ac0);
    b11 = FUN_001d04d0(s2_1e0ac0);
    b12 = FUN_001d04d0(s3_1e0ac0);
    return this;
}