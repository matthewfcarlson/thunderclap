#include "decls/address.h"
extern "C" char DAT_00404c10[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e10c[];
extern "C" char DAT_0048e128[];
extern "C" void __stdcall FUN_001d0480(int, int);
class CCameraManager {
  public:
    char pad00[0x10];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int value1c;
    CCameraManager(int a, int b);
};
CCameraManager::CCameraManager(int a, int b) {
    FUN_001d0480(a, 4);
    *(int*)this = ((int)DAT_00404c10);
    value1c = b;
    b18 = FUN_001d04d0((const char*)((int)DAT_0048e100));
    b10 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    b11 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    b12 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
    b13 = FUN_001d04d0((const char*)((int)DAT_0048e128));
}