#include "decls/address.h"
#include "decls/data/game/global.h"
struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern const char DAT_0048e10c[];
class Function_106af0 : public CtorV_001d0480 {
  public:
    Function_106af0(const char* name) : CtorV_001d0480(name, 3) { }
};
class Method3 : public Function_106af0 {
  public:
    virtual void f();
    char pad[12];
    unsigned char a, b, c;
    char pad2[5];
    unsigned char d;
    char pad3[3];
    int value;
    Method3(const char*, int);
};
Method3::Method3(const char* name, int v) : Function_106af0(name) {
    value = v;
    d = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    a = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b = FUN_001d04d0(((const char*)&DAT_0048e134));
    c = FUN_001d04d0(DAT_0048e10c);
}