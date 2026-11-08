// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// LoadCode: the instruction count, then the instructions (32 bits each).
#include "decls/data/lua.h"

// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
// equiv-conv: FUN_0021f940 eax ecx edx stack
extern "C" void __cdecl FUN_0021f940(unsigned int n, unsigned char* b, LuaVMLoadState* S, unsigned int size);

// equiv-conv: FUN_0021faf0 eax ebx
extern "C" void __cdecl FUN_0021faf0(LuaVMLoadState* S, LuaVMProto* f) {
    int size;
    FUN_0021f8c0((char*)(int*)(&size), 4, S);
    if (size < 0)
        FUN_0021f800(S, "bad integer");
    f->code = (LuaVMInstruction*)FUN_0021add0(S->L, 0, 0, size * (unsigned int)sizeof(LuaVMInstruction));
    f->sizecode = size;
    FUN_0021f940((unsigned int)size, (unsigned char*)f->code, S, (unsigned int)sizeof(LuaVMInstruction));
}
