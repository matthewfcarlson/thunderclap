#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_003f425c[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
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
    ((ThisCall_001d0480*)(this))->FUN_001d0480(arg1, 3);
    vftable = ((hulk_intptr)DAT_003f425c);
    member1c = arg2;
    flag18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    flag10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    flag11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    flag12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}