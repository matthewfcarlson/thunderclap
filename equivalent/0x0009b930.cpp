// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009b930 @ 0x0009b930
#include "decls/address.h"
extern "C" char DAT_0048e100[];
extern "C" char DAT_0049cad8[];
extern "C" char DAT_00404d80[];
extern "C" void __stdcall FUN_001d0480(void*, int);
class MethodObj_9b930 {
  public:
    int vptr;
    char pad4[12];
    char a0, a1, a2, a3;
    char pad14[4];
    char result;
    char pad19[3];
    void* fn;
    MethodObj_9b930* FUN_0009b930(void*, void*);
};
MethodObj_9b930* MethodObj_9b930::FUN_0009b930(void* name, void* f) {
    FUN_001d0480(name, 4);
    vptr = (int)DAT_00404d80;
    fn = f;
    result = FUN_001d04d0(DAT_0048e100);
    a0 = FUN_001d04d0(DAT_0049cad8);
    a1 = FUN_001d04d0(DAT_0049cad8);
    a2 = FUN_001d04d0(DAT_0049cad8);
    a3 = FUN_001d04d0(DAT_0049cad8);
    return this;
}
