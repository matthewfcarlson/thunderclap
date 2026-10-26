#include "decls/address.h"
#include "decls/data/game/global.h"
class CScenarioManager;
struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
struct Function_1ce730 : public CtorV_001d0480 {
    Function_1ce730(const char* a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Function_1ce730 {
  public:
    virtual void fn();
    char pad[12];
    unsigned char b10;
    char pad2[7];
    unsigned char b18;
    char pad3[3];
    int arg;
    Method1(const char*, int);
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    int extra;
    Closure1(const char*, int, int);
};
inline Method1::Method1(const char* a, int c) : Function_1ce730(a) {
    arg = c;
    b18 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b10 = FUN_001d04d0(((const char*)&DAT_0048e134));
}
Closure1::Closure1(const char* a, int b, int c) : Method1(a, c) {
    extra = b;
}
