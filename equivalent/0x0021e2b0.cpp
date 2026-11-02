// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0021e2b0 @ 0x0021e2b0
#include "compat/ptr.h"
struct Context { char pad[0x1c]; int handle; };
struct Result { int value; int unknown1; int unknown2; int status; int result; };
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002214b0(void *, void *);
extern void __cdecl FUN_00220d70(int, int);
// equiv-conv: FUN_0021e2b0 esi
int FUN_0021e2b0(Context* context) {
    Result result;
    FUN_0021ded0((Context *)context, (Result *)(&result), 0);
    if (result.value == 1) result.value = 3;
    FUN_002214b0((void *)(hulk_uintptr)(int)(context->handle), (Result *)(&result));
    FUN_00220d70(context->handle, result.status);
    return result.result;
}