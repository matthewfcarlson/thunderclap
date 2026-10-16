// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0002d370 @ 0x0002d370
#include "decls/address.h"
extern "C" char DAT_003f41ac[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" void __stdcall FUN_001d0480(void*, int);
class MethodCtor7_2d370 {
  public:
    int vptr;
    char pad4[12];
    char arg[7];
    char pad17;
    char result;
    char pad19[3];
    void* func;
    MethodCtor7_2d370* Init(void* name, void* fn);
};
MethodCtor7_2d370* MethodCtor7_2d370::Init(void* name, void* fn) {
    FUN_001d0480(name, 7);
    vptr = (int)DAT_003f41ac;
    func = fn;
    result = FUN_001d04d0((void*)((int)DAT_0048e100));
    arg[0] = FUN_001d04d0((void*)((int)DAT_0048e0f0));
    arg[1] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[2] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[3] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[4] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[5] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[6] = FUN_001d04d0((void*)((int)DAT_0048e0f0));
    return this;
}
