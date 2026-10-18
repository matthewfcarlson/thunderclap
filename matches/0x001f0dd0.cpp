// FUN_001f0dd0 @ 0x001f0dd0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_0042470c[];

class Callback_1f0dd0 {
  public:
    int vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback_1f0dd0* Init(void*, void*);
};

Callback_1f0dd0* Callback_1f0dd0::Init(void* arg, void* value) {
    FUN_001d0480(arg, 5);
    vptr = (int)DAT_0042470c;
    p1c = value;
    b18 = FUN_001d04d0((void*)((int)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((void*)((int)((char*)&DAT_0049cad8)));
    b11 = FUN_001d04d0((void*)((int)((char*)&DAT_0049cad8)));
    b12 = FUN_001d04d0((void*)((int)((char*)&DAT_0048e128)));
    b13 = FUN_001d04d0((void*)((int)((char*)&DAT_0048e128)));
    b14 = FUN_001d04d0((void*)((int)((char*)&DAT_0048e128)));
    return this;
}
