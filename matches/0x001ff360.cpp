#include "decls/address.h"
extern "C" char DAT_00425384[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e10c[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0048e134[];
extern "C" void __stdcall FUN_001d0480(const char*, int);
class Trigger_1ff360 {
  public:
    void* vft;
    char pad4[12];
    unsigned char a10, a11, a12, a13, a14;
    char pad15[3];
    unsigned char a18;
    char pad19[3];
    int m1c;
    Trigger_1ff360(const char*, int);
};
Trigger_1ff360::Trigger_1ff360(const char* s, int x) {
    FUN_001d0480(s, 5);
    vft = (void*)((int)DAT_00425384);
    m1c = x;
    a18 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    a10 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
    a11 = FUN_001d04d0((const char*)((int)DAT_0048e134));
    a12 = FUN_001d04d0((const char*)((int)DAT_0048e134));
    a13 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    a14 = FUN_001d04d0((const char*)((int)DAT_0048e128));
}