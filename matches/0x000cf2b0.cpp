// FUN_000cf2b0 @ 0x000cf2b0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_0040a5c0[];
extern "C" char DAT_0048e10c[];

class Callback_cf2b0 {
  public:
    int vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback_cf2b0* Init(void*, void*);
};

Callback_cf2b0* Callback_cf2b0::Init(void* arg, void* value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_0040a5c0;
    p1c = value;
    b18 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    b10 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    b11 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    b13 = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    b14 = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    return this;
}
