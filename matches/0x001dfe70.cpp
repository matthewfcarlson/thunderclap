// FUN_001dfe70 @ 0x001dfe70
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00423368[];

class Method5_1dfe70 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Method5_1dfe70* Init(void*, void*);
};

Method5_1dfe70* Method5_1dfe70::Init(void* arg, void* value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_00423368;
    p1c = value;
    b18 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b10 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b11 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    b13 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    b14 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}
