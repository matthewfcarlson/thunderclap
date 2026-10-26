#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00423478[];
class Method3_1e0b60 {
  public:
    void Init(int, int);
    hulk_intptr m0;
    char pad4[0x0c];
    char m10, m11, m12;
    char pad13[5];
    char m18;
    char pad19[3];
    int m1c;
    Method3_1e0b60(int, int);
};
Method3_1e0b60::Method3_1e0b60(int x, int y) {
    Init(x, 3);
    m0 = ((hulk_intptr)DAT_00423478);
    m1c = y;
    m18 = FUN_001d04d0(((char*)&DAT_0048e100));
    m10 = FUN_001d04d0(((char*)&DAT_0048e128));
    m11 = FUN_001d04d0(((char*)&DAT_0048e128));
    m12 = FUN_001d04d0(((char*)&DAT_0048e128));
}