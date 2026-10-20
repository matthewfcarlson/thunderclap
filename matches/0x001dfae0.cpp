#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_00423318[];
extern "C" char DAT_0048e10c[];
class Base_1dfae0 {
  public:
    Base_1dfae0(const char*, int);
};
class Target_1dfae0 : public Base_1dfae0 {
  public:
    char pad[0x10];
    char m10;
    char m11;
    char m12;
    char m13;
    char m14;
    char m15;
    char pad16[2];
    char m18;
    char pad19[3];
    int m1c;
    Target_1dfae0(const char*, int);
};
Target_1dfae0::Target_1dfae0(const char* p, int n) : Base_1dfae0(p, 6) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00423318);
    m1c = n;
    m18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    m13 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m14 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    m15 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}