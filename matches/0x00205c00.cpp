#include "decls/address.h"
typedef unsigned char byte;
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
extern const char g1[], g2[];
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
    a = FUN_001d04d0(g1);
    b = FUN_001d04d0(g2);
}
Closure1::Closure1(int x, int y, int z) : Closure1_205c00(x, z) {
    val = y;
}