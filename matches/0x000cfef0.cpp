#include "decls/address.h"
class HUDOverlay;
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
extern const char a_cfef0[], b[], c[];
class Base_cfef0 : public CtorV_001d0480 {
  public:
    Base_cfef0(int n) : CtorV_001d0480(n, 2) { }
};
class Method2 : public Base_cfef0 {
  public:
    virtual void f();
    char pad[0xc];
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int arg;
    Method2(int, int);
};
Method2::Method2(int n, int v) : Base_cfef0(n) {
    arg = v;
    z = FUN_001d04d0(a_cfef0);
    x = FUN_001d04d0(b);
    y = FUN_001d04d0(c);
}
class Closure2 : public Method2 {
  public:
    int val;
    Closure2(int, int, int);
};
Closure2::Closure2(int n, int v, int w) : Method2(n, w) {
    val = v;
}