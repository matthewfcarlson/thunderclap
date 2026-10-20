// FUN_000d5890 @ 0x000d5890
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_0040b1f8[];
extern "C" char DAT_0048e10c[];

class Callback_d5890 {
  public:
    int vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback_d5890* Init(void*, void*);
};

Callback_d5890* Callback_d5890::Init(void* arg, void* value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_0040b1f8;
    p1c = value;
    b18 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    b11 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    b13 = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    b14 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
