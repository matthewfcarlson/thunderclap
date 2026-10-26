#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00423468[];
class Method3_1e0ac0 {
  public:
    hulk_intptr x;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
    void Init(int, int);
    Method3_1e0ac0* Run(int, int);
};
Method3_1e0ac0* Method3_1e0ac0::Run(int a, int b) {
    Init(a, 3);
    x = ((hulk_intptr)DAT_00423468);
    m1c = b;
    b18 = FUN_001d04d0(((const char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((const char*)&DAT_0048e134));
    b11 = FUN_001d04d0(((const char*)&DAT_0048e134));
    b12 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    return this;
}