#include "decls/address.h"
#include "decls/data/game/global.h"
class Function_1df750 {
  public:
    virtual void f();
    char pad[12];
    Function_1df750(const char*, int);
};
class Method3 : public Function_1df750 {
  public:
    char a;
    char b;
    char c;
    char pad2[5];
    char d;
    char pad3[3];
    int value;
    Method3(const char*, int);
    virtual void f();
};
Method3::Method3(const char* name, int v) : Function_1df750(name, 3) {
    value = v;
    d = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    a = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b = FUN_001d04d0(((const char*)&DAT_0048e134));
    c = FUN_001d04d0(((const char*)&DAT_0048e134));
}