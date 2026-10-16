#include "decls/address.h"
extern "C" char DAT_003f425c[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern void __stdcall FUN_001d0480(void*, int);
class CActorManager {
  public:
    int vftable;
    char pad04[0x0c];
    char flag10, flag11, flag12;
    char pad13[5];
    char flag18;
    char pad19[3];
    void* member1c;
    CActorManager* Init(void*, void*);
};
CActorManager* CActorManager::Init(void* arg1, void* arg2) {
    FUN_001d0480(arg1, 3);
    vftable = ((int)DAT_003f425c);
    member1c = arg2;
    flag18 = FUN_001d04d0((const char*)((int)DAT_0048e100));
    flag10 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    flag11 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    flag12 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    return this;
}