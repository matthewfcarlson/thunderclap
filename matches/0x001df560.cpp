#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
class Function_1df560 {
  public:
    Function_1df560(const char*, int);
    virtual void v0();
    char pad[0xc];
};
class Function5_1df560 : public Function_1df560 {
  public:
    Function5_1df560(const char*, int);
    char c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c1a, c1b;
    int m1c;
};
Function5_1df560::Function5_1df560(const char* p, int x) : Function_1df560(p, 5) {
    m1c = x;
    c18 = FUN_001d04d0(((char*)&DAT_0048e100));
    c10 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    c11 = FUN_001d04d0(((char*)&DAT_0048e128));
    c12 = FUN_001d04d0(((char*)&DAT_0048e128));
    c13 = FUN_001d04d0(((char*)&DAT_0048e128));
    c14 = FUN_001d04d0(((char*)&DAT_0048e128));
}
