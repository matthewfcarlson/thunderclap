#include "decls/address.h"
#include "decls/data/game/global.h"
// data: name1 = DAT_0048e0e4, name2 = DAT_0048e0f0
struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_2c790 : public CtorV_001d0480 {
  public:
    Function_2c790(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_2c790 {
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
Method1::Method1(const char* s, int v) : Function_2c790(s) {
    c = v;
    b = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    a = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
