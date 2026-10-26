#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_003f421c[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
class Method4_2d830 : public Ctor_001d0480 {
  public:
    hulk_intptr vptr;
    char pad4[0xc];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int m1c;
    Method4_2d830(const char*, int);
};
Method4_2d830::Method4_2d830(const char* a, int b) : Ctor_001d0480(a, 4) {
    vptr = ((hulk_intptr)DAT_003f421c);
    m1c = b;
    b18 = FUN_001d04d0(((const char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b11 = FUN_001d04d0(((const char*)&DAT_0048e128));
    b12 = FUN_001d04d0(((const char*)&DAT_0048e128));
    b13 = FUN_001d04d0(((const char*)&DAT_0048e128));
}