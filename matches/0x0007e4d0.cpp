#include "decls/address.h"
extern const char DAT_0048e100[], DAT_0048e0f0[], DAT_0048e128[];
class Function_7e4d0 {
  public:
    virtual void fn();
    Function_7e4d0(int, int);
    char pad[12];
    unsigned char x;
    unsigned char y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int u;
};
class Method2 : public Function_7e4d0 {
  public:
    virtual void fn();
    Method2(int p, int r) : Function_7e4d0(p, 2) {
        u = r;
        z = FUN_001d04d0(DAT_0048e100);
        x = FUN_001d04d0(DAT_0048e0f0);
        y = FUN_001d04d0(DAT_0048e128);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void fn();
    int v;
    Closure2(int, int, int);
};
Closure2::Closure2(int p, int q, int r) : Method2(p, r) {
    v = q;
}