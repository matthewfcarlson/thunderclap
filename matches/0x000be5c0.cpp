#include "decls/address.h"
#include "decls/data/game/global.h"
class Function_be5c0 {
  public:
    Function_be5c0(const char*, int);
    virtual void v0();
    char pad[0xc];
};
class Method6_be5c0 : public Function_be5c0 {
  public:
    Method6_be5c0(const char*, int);
    char c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c1a, c1b;
    int m1c;
};
Method6_be5c0::Method6_be5c0(const char* p, int x) : Function_be5c0(p, 6) {
    m1c = x;
    c18 = FUN_001d04d0(((char*)&DAT_0048e100));
    c10 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    c11 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    c12 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    c13 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    c14 = FUN_001d04d0(((char*)&DAT_0048e134));
    c15 = FUN_001d04d0(((char*)&DAT_0048e134));
}
