#include "decls/address.h"
struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern const char name1[];
extern const char name2[];
class Base : public CtorV_001d0480 {
  public:
    Base(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Base {
  public:
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int c;
    Method1(const char*, int);
};
Method1::Method1(const char* s, int v) : Base(s) {
    c = v;
    b = FUN_001d04d0(name1);
    a = FUN_001d04d0(name2);
}
