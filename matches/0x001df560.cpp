#include "decls/address.h"
extern char g100_1df560[], g0f0[], g128[];
class Function_1df560 {
  public:
    Function_1df560(const char*, int);
    virtual void v0();
    char pad[0xc];
};
class Function5_1df560 : public Function_1df560 {
  public:
    Function5_1df560(const char*, int);
    char c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c1a, c1b;
    int m1c;
};
Function5_1df560::Function5_1df560(const char* p, int x) : Function_1df560(p, 5) {
    m1c = x;
    c18 = FUN_001d04d0(g100_1df560);
    c10 = FUN_001d04d0(g0f0);
    c11 = FUN_001d04d0(g128);
    c12 = FUN_001d04d0(g128);
    c13 = FUN_001d04d0(g128);
    c14 = FUN_001d04d0(g128);
}
