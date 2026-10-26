#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_003f420c[];
class Method4_2d770 {
  public:
    hulk_intptr vt;
    char pad4[0x0c];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int m1c;
    Method4_2d770(const char*, int);
};
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
Method4_2d770::Method4_2d770(const char* p, int q) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(p, 4);
    vt = ((hulk_intptr)DAT_003f420c);
    m1c = q;
    b18 = FUN_001d04d0(((const char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b11 = FUN_001d04d0(((const char*)&DAT_0048e128));
    b12 = FUN_001d04d0(((const char*)&DAT_0048e134));
    b13 = FUN_001d04d0(((const char*)&DAT_0048e128));
}