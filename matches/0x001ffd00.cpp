#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
extern int label;
class Base : public CtorV_001d0480 {
  public:
    Base(int a) : CtorV_001d0480(a, 0) { }
};
class Method0 : public Base {
  public:
    virtual void f();
    char pad[0x14];
    unsigned char flag;
    char pad2[3];
    int value;
    Method0(int a, int c) : Base(a) {
        value = c;
        flag = FUN_001d04d0(&label);
    }
};
class Closure0 : public Method0 {
  public:
    virtual void f();
    int other;
    Closure0(int a, int b, int c);
};
Closure0::Closure0(int a, int b, int c) : Method0(a, c) {
    other = b;
}
