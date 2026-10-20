// FUN_0009ad40 @ 0x0009ad40
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00404c80[];

class Callback_9ad40 {
  public:
    int vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback_9ad40* Init(void*, void*);
};

Callback_9ad40* Callback_9ad40::Init(void* arg, void* value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_00404c80;
    p1c = value;
    b18 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b11 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b12 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b13 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b14 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
