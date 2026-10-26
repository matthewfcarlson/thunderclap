#include "decls/address.h"
#include "decls/data/game/global.h"
class Function_86f50 {
  public:
    virtual void f();
    Function_86f50(const char*, int);
};
class Function2 : public Function_86f50 {
  public:
    virtual void f();
    char pad[12];
    unsigned char a, b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int d;
    Function2(const char*, int);
};
Function2::Function2(const char* s, int v) : Function_86f50(s, 2) {
    d = v;
    c = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    a = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}