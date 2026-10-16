#include "decls/address.h"
extern "C" char DAT_003f428c[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern void __stdcall FUN_001d0480(const char*, int);
class CActorManager {
  public:
    int vptr;
    char pad04[0x0c];
    char m10, m11, m12, m13;
    char pad14[4];
    char m18;
    char pad19[3];
    int m1c;
    CActorManager(const char*, int);
};
CActorManager::CActorManager(const char* a, int b) {
    FUN_001d0480(a, 4);
    vptr = ((int)DAT_003f428c);
    m1c = b;
    m18 = FUN_001d04d0((const char*)((int)DAT_0048e100));
    m10 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    m11 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    m12 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    m13 = FUN_001d04d0((const char*)((int)DAT_0048e128));
}