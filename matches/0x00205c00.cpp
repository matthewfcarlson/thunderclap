#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned char byte;
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(int);
};
Base::Base(int x) : CtorV_001d0480(x, 1) {
}
class Closure1_205c00 : public Base {
  public:
    virtual void invoke();
    char pad[12];
    byte b;
    char pad2[7];
    byte a;
    char pad3[3];
    int obj;
    Closure1_205c00(int, int);
};
class Closure1 : public Closure1_205c00 {
  public:
    virtual void invoke();
    int val;
    Closure1(int, int, int);
};
Closure1_205c00::Closure1_205c00(int x, int y) : Base(x) {
    obj = y;
    a = FUN_001d04d0(((const char*)&DAT_0048e100));
    b = FUN_001d04d0(((const char*)&DAT_0048e134));
}
Closure1::Closure1(int x, int y, int z) : Closure1_205c00(x, z) {
    val = y;
}