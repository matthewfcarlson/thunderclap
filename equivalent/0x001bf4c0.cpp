// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001bf4c0 @ 0x001bf4c0
#include "decls/address.h"
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0048e134[];
extern "C" char DAT_004214d0[];
extern "C" void __stdcall FUN_001d0480(void*, int);
class MethodObj_1bf4c0 {
  public:
    int vptr;
    char pad4[12];
    char a0, a1, a2, a3;
    char pad14[4];
    char result;
    char pad19[3];
    void* fn;
    MethodObj_1bf4c0* FUN_001bf4c0(void*, void*);
};
MethodObj_1bf4c0* MethodObj_1bf4c0::FUN_001bf4c0(void* name, void* f) {
    FUN_001d0480(name, 4);
    vptr = (int)DAT_004214d0;
    fn = f;
    result = FUN_001d04d0(DAT_0048e100);
    a0 = FUN_001d04d0(DAT_0048e134);
    a1 = FUN_001d04d0(DAT_0048e128);
    a2 = FUN_001d04d0(DAT_0048e0f0);
    a3 = FUN_001d04d0(DAT_0048e128);
    return this;
}
