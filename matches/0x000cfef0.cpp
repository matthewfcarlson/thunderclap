#include "decls/address.h"
#include "decls/data/game/global.h"
// data: a_cfef0 = DAT_0048e100
class HUDOverlay;
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
class Base_cfef0 : public CtorV_001d0480 {
  public:
    Base_cfef0(int n) : CtorV_001d0480(n, 2) { }
};
class Closure2_cfef0 : public Base_cfef0 {
  public:
    virtual void f();
    char pad[0xc];
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int arg;
    Closure2_cfef0(int, int);
};
Closure2_cfef0::Closure2_cfef0(int n, int v) : Base_cfef0(n) {
    arg = v;
    z = FUN_001d04d0(((const char*)&DAT_0048e100));
    x = FUN_001d04d0(((const char*)&DAT_0048e134));
    y = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
class Closure2 : public Closure2_cfef0 {
  public:
    int val;
    Closure2(int, int, int);
};
Closure2::Closure2(int n, int v, int w) : Closure2_cfef0(n, w) {
    val = v;
}