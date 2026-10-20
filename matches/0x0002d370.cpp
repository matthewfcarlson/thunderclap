// FUN_0002d370 @ 0x0002d370
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_003f41ac[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
class MethodCtor7_2d370 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char arg[7];
    char pad17;
    char result;
    char pad19[3];
    void* func;
    MethodCtor7_2d370* Init(void* name, void* fn);
};
MethodCtor7_2d370* MethodCtor7_2d370::Init(void* name, void* fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (hulk_intptr)DAT_003f41ac;
    func = fn;
    result = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    arg[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    arg[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    arg[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    arg[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    arg[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    arg[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    arg[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}
