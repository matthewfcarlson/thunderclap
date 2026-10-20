// FUN_000ceaa0 @ 0x000ceaa0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_0048e10c[];
extern "C" char DAT_0040a500[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
class MethodObj_ceaa0 {
  public:
    int vptr;
    char pad4[12];
    char a0, a1, a2, a3;
    char pad14[4];
    char result;
    char pad19[3];
    void* fn;
    MethodObj_ceaa0* FUN_000ceaa0(void*, void*);
};
MethodObj_ceaa0* MethodObj_ceaa0::FUN_000ceaa0(void* name, void* f) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_0040a500;
    fn = f;
    result = FUN_001d04d0(((char*)&DAT_0048e100));
    a0 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    a1 = FUN_001d04d0(((char*)&DAT_0048e128));
    a2 = FUN_001d04d0(((char*)&DAT_0048e128));
    a3 = FUN_001d04d0(DAT_0048e10c);
    return this;
}
