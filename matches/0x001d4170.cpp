#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern int g1, g2;
class Function_1d4170 : public CtorV_001d0480 {
  public:
    Function_1d4170(void* x) : CtorV_001d0480(x, 1) { }
};
class Method1_1d4170 : public Function_1d4170 {
  public:
    virtual void f();
    char p[12];
    unsigned char a;
    char p2[7];
    unsigned char b;
    char p3[3];
    void* obj;
    Method1_1d4170(void* x, void* z) : Function_1d4170(x) {
        obj = z;
        b = FUN_001d04d0(&g2);
        a = FUN_001d04d0(&g1);
    }
};
class Closure1_1d4170 : public Method1_1d4170 {
  public:
    virtual void f();
    void* val;
    Closure1_1d4170(void*, void*, void*);
};
Closure1_1d4170::Closure1_1d4170(void* x, void* y, void* z) : Method1_1d4170(x, z) {
    val = y;
}