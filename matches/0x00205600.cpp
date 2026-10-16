#include "decls/address.h"
extern "C" char DAT_00425be4[];
class InitBase_205600 {
  public:
    void Init(const char*, int);
};
class CWorldStreamManager {
  public:
    CWorldStreamManager(const char*, int);
    int vptr;
    char p[12];
    char f10, f11, f12;
    char p2[5];
    char f18;
    char p3[3];
    int f1c;
};
extern char str1_205600[], str2[], str3[], str4[];
CWorldStreamManager::CWorldStreamManager(const char* a, int b) {
    ((InitBase_205600*)this)->Init(a, 3);
    vptr = ((int)DAT_00425be4);
    f1c = b;
    f18 = (char)FUN_001d04d0(str1_205600);
    f10 = (char)FUN_001d04d0(str2);
    f11 = (char)FUN_001d04d0(str3);
    f12 = (char)FUN_001d04d0(str4);
}