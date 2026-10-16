#include "decls/address.h"
extern void __stdcall FUN_001d0480(void*, int);
extern int g1_d0080;
extern int g2_d0080;
class Base_d0080 {
  public:
    Base_d0080(void* p) { FUN_001d0480(p, 2); }
};
class Method2 : public Base_d0080 {
  public:
    virtual void f();
    char pad[12];
    unsigned char b10, b11;
    char pad2[6];
    unsigned char b18;
    char pad3[3];
    int m1;
    Method2(void*, int, int);
};
Method2::Method2(void* p, int a, int b) : Base_d0080(p) {
    m1 = b;
    b18 = FUN_001d04d0(&g1_d0080);
    b10 = FUN_001d04d0(&g2_d0080);
    b11 = FUN_001d04d0(&g2_d0080);
}
class Closure2 : public Method2 {
  public:
    virtual void f();
    int m2;
    Closure2(void*, int, int);
};
Closure2::Closure2(void* p, int a, int b) : Method2(p, a, b) {
    m2 = a;
}