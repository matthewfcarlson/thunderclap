#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
extern const char a[], b[];
class Function_b0350 : public CtorV_001d0480 {
  public:
    Function_b0350(int n) : CtorV_001d0480(n, 1) { }
};
class Method1 : public Function_b0350 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[12];
    unsigned char x;
    char p2[7];
    unsigned char y;
    char p3[3];
    int arg;
    Method1(int n, int v) : Function_b0350(n) {
        arg = v;
        y = FUN_001d04d0(a);
        x = FUN_001d04d0(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int extra;
    Closure1(int n, int v, int z);
};
Closure1::Closure1(int n, int v, int z) : Method1(n, z) {
    extra = v;
}