#include "decls/address.h"
extern void __stdcall FUN_001d0480(int, int);
extern char g1_cfcf0[], g2[], g3[];
class B_cfcf0 {
  public:
    B_cfcf0(int x) { FUN_001d0480(x, 2); }
};
class Method2 : public B_cfcf0 {
  public:
    virtual void f();
    char pad[0xc];
    unsigned char a, b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int d;
    Method2(int x, int y) : B_cfcf0(x) {
        d = y;
        c = FUN_001d04d0(g1_cfcf0);
        a = FUN_001d04d0(g2);
        b = FUN_001d04d0(g3);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void f();
    int e;
    Closure2(int, int, int);
};
Closure2::Closure2(int x, int y, int z) : Method2(x, z) {
    e = y;
}