#include "decls/address.h"
#include "decls/data/game/global.h"
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
extern char DAT_0048e10c[];
class Function_cfcf0 : public CtorV_001d0480 {
  public:
    Function_cfcf0(int x) : CtorV_001d0480(x, 2) { }
};
class Method2 : public Function_cfcf0 {
  public:
    virtual void f();
    char pad[0xc];
    unsigned char a, b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int d;
    Method2(int x, int y) : Function_cfcf0(x) {
        d = y;
        c = FUN_001d04d0(((char*)&DAT_0048e100));
        a = FUN_001d04d0(((char*)&DAT_0048e134));
        b = FUN_001d04d0(DAT_0048e10c);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void f();
    int e;
    Closure2(int, int, int);
};
Closure2::Closure2(int x, int y, int z) : Method2(x, z) {
    e = y;
}