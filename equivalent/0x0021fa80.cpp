// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// LoadString: a size_t length (32 bits in the chunk, counting the NUL), then the characters; 0 is no string.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n);
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

// equiv-conv: FUN_0021fa80 eax
extern "C" LuaVMString* __cdecl FUN_0021fa80(LuaVMLoadState* S) {
    unsigned int size;
    FUN_0021f8c0((char*)(void*)(&size), 4, S);
    if (size == 0)
        return 0;
    char* s = FUN_0021a6b0(S->L, S->b, size);
    if (((int)FUN_0021a610(S->Z, s, size)))
        FUN_0021f800(S, "unexpected end of file");
    return FUN_00219430(S->L, s, size - 1);
}
