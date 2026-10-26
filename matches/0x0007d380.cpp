#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_003ff014[];
extern const char s3[];
class Function_7d380 {
  public:
    void Init(const char*, int);
};
class Method4_7d380 : public Function_7d380 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int member1c;
    Method4_7d380(const char*, int);
};
Method4_7d380::Method4_7d380(const char* p, int x) {
    Init(p, 4);
    vptr = ((hulk_intptr)DAT_003ff014);
    member1c = x;
    b18 = FUN_001d04d0(((const char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b11 = FUN_001d04d0(((const char*)&DAT_0048e134));
    b12 = FUN_001d04d0(s3);
    b13 = FUN_001d04d0(s3);
}