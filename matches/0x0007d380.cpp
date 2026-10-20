#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_003ff014[];
extern const char s0_7d380[], s1[], s2[], s3[];
class Base_7d380 {
  public:
    void Init(const char*, int);
};
class Target_7d380 : public Base_7d380 {
  public:
    int vptr;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int member1c;
    Target_7d380(const char*, int);
};
Target_7d380::Target_7d380(const char* p, int x) {
    Init(p, 4);
    vptr = ((hulk_intptr)DAT_003ff014);
    member1c = x;
    b18 = FUN_001d04d0(s0_7d380);
    b10 = FUN_001d04d0(s1);
    b11 = FUN_001d04d0(s2);
    b12 = FUN_001d04d0(s3);
    b13 = FUN_001d04d0(s3);
}