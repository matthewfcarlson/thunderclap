// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000943c0 @ 0x000943c0
#include "decls/address.h"
extern "C" char DAT_0040470c[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e134[];
extern "C" void __stdcall FUN_001d0480(void*, int);
class MethodCtor7_943c0 {
  public:
    int vptr;
    char pad4[12];
    char arg[7];
    char pad17;
    char result;
    char pad19[3];
    void* func;
    MethodCtor7_943c0* Init(void* name, void* fn);
};
MethodCtor7_943c0* MethodCtor7_943c0::Init(void* name, void* fn) {
    FUN_001d0480(name, 7);
    vptr = (int)DAT_0040470c;
    func = fn;
    result = FUN_001d04d0((void*)((int)DAT_0048e100));
    arg[0] = FUN_001d04d0((void*)((int)DAT_0048e0f0));
    arg[1] = FUN_001d04d0((void*)((int)DAT_0048e134));
    arg[2] = FUN_001d04d0((void*)((int)DAT_0048e0f0));
    arg[3] = FUN_001d04d0((void*)((int)DAT_0048e0f0));
    arg[4] = FUN_001d04d0((void*)((int)DAT_0048e0f0));
    arg[5] = FUN_001d04d0((void*)((int)DAT_0048e0f0));
    arg[6] = FUN_001d04d0((void*)((int)DAT_0048e134));
    return this;
}
