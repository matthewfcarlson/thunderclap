#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
extern const char g1[];
extern const char g2[];
class Base : public CtorV_001d0480 {
  public:
    Base(int x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int c;
    Method1(int x, int y) : Base(x) {
        c = y;
        b = FUN_001d04d0(g1);
        a = FUN_001d04d0(g2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    int d;
    Closure1(int, int, int);
};
Closure1::Closure1(int x, int y, int z) : Method1(x, z) {
    d = y;
}