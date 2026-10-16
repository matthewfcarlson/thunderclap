#include "decls/address.h"
extern "C" char DAT_004234c8[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0048e134[];
extern "C" void __stdcall FUN_001d0480(void*, int);
class CSPManager {
  public:
    int vp;
    char p04[0xc];
    char m10;
    char m11;
    char m12;
    char m13;
    char m14;
    char m15;
    char p16[2];
    char m18;
    char p19[3];
    int m1c;
    CSPManager(int, int);
};
CSPManager::CSPManager(int a, int b) {
    FUN_001d0480((void*)a, 6);
    vp = ((int)DAT_004234c8);
    m1c = b;
    m18 = FUN_001d04d0((const char*)((int)DAT_0048e100));
    m10 = FUN_001d04d0((const char*)((int)DAT_0048e134));
    m11 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    m12 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    m13 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    m14 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    m15 = FUN_001d04d0((const char*)((int)DAT_0048e134));
}