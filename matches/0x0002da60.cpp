#include "decls/address.h"
extern "C" char DAT_003f424c[];
extern "C" char DAT_0048e0e4[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e128[];
class CActorManager {
  public:
    int vf;
    char pad04[0x0c];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
    void Init(void*, int);
    CActorManager(void*, int);
};
CActorManager::CActorManager(void* p, int x) {
    Init(p, 3);
    vf = ((int)DAT_003f424c);
    m1c = x;
    b18 = FUN_001d04d0((const char*)((int)DAT_0048e0e4));
    b10 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    b11 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    b12 = FUN_001d04d0((const char*)((int)DAT_0048e128));
}
