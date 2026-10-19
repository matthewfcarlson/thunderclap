#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern int g1, g2;
class Parent : public CtorV_001d0480 {
  public:
    Parent(void* x) : CtorV_001d0480(x, 1) { }
};
class Method : public Parent {
  public:
    virtual void f();
    char p[12];
    unsigned char a;
    char p2[7];
    unsigned char b;
    char p3[3];
    void* obj;
    Method(void* x, void* z) : Parent(x) {
        obj = z;
        b = FUN_001d04d0(&g2);
        a = FUN_001d04d0(&g1);
    }
};
class Closure : public Method {
  public:
    virtual void f();
    void* val;
    Closure(void*, void*, void*);
};
Closure::Closure(void* x, void* y, void* z) : Method(x, z) {
    val = y;
}