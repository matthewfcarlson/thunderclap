#include "decls/address.h"
extern void __stdcall FUN_001d0480(int, int);
extern const char a[], b[];
class Base {
  public:
    Base(int n) { FUN_001d0480(n, 1); }
};
class Method1 : public Base {
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
    Method1(int n, int v) : Base(n) {
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