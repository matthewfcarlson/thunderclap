#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_003f432c[];
class Function_2e350 {
  public:
    void Init(int, int);
};
class Method3 : public Function_2e350 {
  public:
    hulk_intptr v;
    char p[0x0c];
    unsigned char b10, b11, b12;
    char q[5];
    unsigned char b18;
    int m1c;
    Method3(int, int);
};
extern const char s1_2e350[];
extern const char s2_2e350[];
extern const char DAT_0048e10c[];
Method3::Method3(int a, int x) {
    Init(a, 3);
    v = ((hulk_intptr)DAT_003f432c);
    m1c = x;
    b18 = FUN_001d04d0(s1_2e350);
    b10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b11 = FUN_001d04d0(DAT_0048e10c);
    b12 = FUN_001d04d0(DAT_0048e10c);
}