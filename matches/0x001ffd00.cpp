#include "decls/address.h"
#include "decls/data/game/global.h"
// data: label = DAT_0048e134
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
class Function_1ffd00 : public CtorV_001d0480 {
  public:
    Function_1ffd00(int a) : CtorV_001d0480(a, 0) { }
};
class Method0 : public Function_1ffd00 {
  public:
    virtual void f();
    char pad[0x14];
    unsigned char flag;
    char pad2[3];
    int value;
    Method0(int a, int c) : Function_1ffd00(a) {
        value = c;
        flag = FUN_001d04d0(((int*)&DAT_0048e134));
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
