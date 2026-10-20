// FUN_000943c0 @ 0x000943c0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_0040470c[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
class MethodCtor7_943c0 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char arg[7];
    char pad17;
    char result;
    char pad19[3];
    void* func;
    MethodCtor7_943c0* Init(void* name, void* fn);
};
MethodCtor7_943c0* MethodCtor7_943c0::Init(void* name, void* fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (hulk_intptr)DAT_0040470c;
    func = fn;
    result = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    arg[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    arg[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    arg[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    arg[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    arg[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    arg[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    arg[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    return this;
}
