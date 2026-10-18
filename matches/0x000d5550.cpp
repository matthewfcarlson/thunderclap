// FUN_000d5550 @ 0x000d5550
// Method7 registration constructor: base init, vftable, then the seven result/argument type tags.
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_0040b1a8[];

class Callback_d5550 {
  public:
    int vptr;
    char pad4[12];
    char arg[7];
    char pad17;
    char result;
    char pad19[3];
    void* owner;
    void FUN_001d0480(void*, int);
    Callback_d5550* Init(void*, void*);
};

Callback_d5550* Callback_d5550::Init(void* name, void* value) {
    FUN_001d0480(name, 7);
    vptr = (int)DAT_0040b1a8;
    owner = value;
    result = FUN_001d04d0((void*)((int)((char*)&DAT_0048e100)));
    arg[0] = FUN_001d04d0((void*)((int)((char*)&DAT_0048e0f0)));
    arg[1] = FUN_001d04d0((void*)((int)((char*)&DAT_0048e0f0)));
    arg[2] = FUN_001d04d0((void*)((int)((char*)&DAT_0048e0f0)));
    arg[3] = FUN_001d04d0((void*)((int)((char*)&DAT_0048e0f0)));
    arg[4] = FUN_001d04d0((void*)((int)((char*)&DAT_0048e0f0)));
    arg[5] = FUN_001d04d0((void*)((int)((char*)&DAT_0048e0f0)));
    arg[6] = FUN_001d04d0((void*)((int)((char*)&DAT_0048e0f0)));
    return this;
}
