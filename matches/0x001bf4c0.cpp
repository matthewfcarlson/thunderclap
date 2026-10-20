// FUN_001bf4c0 @ 0x001bf4c0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_004214d0[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
class MethodObj_1bf4c0 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char a0, a1, a2, a3;
    char pad14[4];
    char result;
    char pad19[3];
    void* fn;
    MethodObj_1bf4c0* FUN_001bf4c0(void*, void*);
};
MethodObj_1bf4c0* MethodObj_1bf4c0::FUN_001bf4c0(void* name, void* f) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_004214d0;
    fn = f;
    result = FUN_001d04d0(((char*)&DAT_0048e100));
    a0 = FUN_001d04d0(((char*)&DAT_0048e134));
    a1 = FUN_001d04d0(((char*)&DAT_0048e128));
    a2 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    a3 = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}
