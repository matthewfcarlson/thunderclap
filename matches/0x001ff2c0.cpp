#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00425374[];
struct Function_1ff2c0 {
    void Init(const char*, int);
};
class Method3_1ff2c0 : public Function_1ff2c0 {
  public:
    Method3_1ff2c0(const char*, int);
    hulk_intptr m0;
    char p04[0x0c];
    char b10;
    char b11;
    char b12;
    char p13[5];
    char b18;
    char p19[3];
    int m1c;
};
Method3_1ff2c0::Method3_1ff2c0(const char* a, int c) {
    Init(a, 3);
    m0 = ((hulk_intptr)DAT_00425374);
    m1c = c;
    b18 = FUN_001d04d0(((char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    b11 = FUN_001d04d0(((char*)&DAT_0048e134));
    b12 = FUN_001d04d0(&DAT_0048e0e4);
}