#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_003f420c[];
class CActorManager {
  public:
    hulk_intptr vt;
    char pad4[0x0c];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int m1c;
    CActorManager(const char*, int);
};
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
extern const char s0_2d770[], s1[], s2[], s3[];
CActorManager::CActorManager(const char* p, int q) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(p, 4);
    vt = ((hulk_intptr)DAT_003f420c);
    m1c = q;
    b18 = FUN_001d04d0(s0_2d770);
    b10 = FUN_001d04d0(s1);
    b11 = FUN_001d04d0(s2);
    b12 = FUN_001d04d0(s3);
    b13 = FUN_001d04d0(s2);
}