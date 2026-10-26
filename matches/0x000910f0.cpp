#include "decls/address.h"
#include "decls/data/game/global.h"
struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_910f0 : public CtorV_001d0480 {
  public:
    Function_910f0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_910f0 {
  public:
    virtual void f();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    int z;
    Method1(const char* s, int n) : Function_910f0(s) {
        z = n;
        y = FUN_001d04d0(((const char*)&DAT_0048e134));
        x = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void g();
    int w;
    Closure1(const char*, int, int);
};
Closure1::Closure1(const char* s, int n, int v) : Method1(s, v) {
    w = n;
}
