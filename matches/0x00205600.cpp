#include "decls/data/game/global.h"
// data: str1_205600 = DAT_0048e100, str2 = DAT_0048e0f0, str3 = DAT_0048e134, str4 = DAT_0048e0e4

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00425be4[];
class InitBase_205600 {
  public:
    void Init(const char*, int);
};
class Method3_205600 {
  public:
    Method3_205600(const char*, int);
    hulk_intptr vptr;
    char p[12];
    char f10, f11, f12;
    char p2[5];
    char f18;
    char p3[3];
    int f1c;
};
Method3_205600::Method3_205600(const char* a, int b) {
    ((InitBase_205600*)this)->Init(a, 3);
    vptr = ((hulk_intptr)DAT_00425be4);
    f1c = b;
    f18 = (char)FUN_001d04d0(((char*)&DAT_0048e100));
    f10 = (char)FUN_001d04d0(((char*)&DAT_0048e0f0));
    f11 = (char)FUN_001d04d0(((char*)&DAT_0048e134));
    f12 = (char)FUN_001d04d0(((char*)&DAT_0048e0e4));
}