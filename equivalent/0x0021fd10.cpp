// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 18/18)
// LoadUpvalues: the upvalue name count (0 or nups), then each name.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n);
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

// equiv-conv: FUN_0021fd10 eax stack
extern "C" void __cdecl FUN_0021fd10(LuaVMLoadState* S, LuaVMProto* f) {
    struct {
        int count;
        int length;
    } local;  // the integers read from the chunk (32 bits each)
    FUN_0021f8c0((char*)(int*)(&local.count), 4, S);
    int count = local.count;
    if (count < 0) {
        FUN_0021f800(S, "bad integer");
        count = local.count;
    }
    if (count != 0 && count != f->nups)
        FUN_0021f800(S, "bad nupvalues (read %d; expected %d)", count, (int)f->nups);
    f->upvalues = (LuaVMString**)FUN_0021add0(S->L, 0, 0, (unsigned int)count * (unsigned int)sizeof(LuaVMString*));
    f->sizeupvalues = count;
    for (int i = 0; i < count; ++i)
        f->upvalues[i] = 0;
    local.count = 0;
    for (int i = 0; i < count; ++i) {
        FUN_0021f8c0((char*)(int*)(&local.length), 4, S);
        int length = local.length;
        LuaVMString* value = 0;
        if (length != 0) {
            char* buffer = FUN_0021a6b0(S->L, S->b, (unsigned int)length);
            if (((int)FUN_0021a610(S->Z, buffer, (unsigned int)length)))
                FUN_0021f800(S, "unexpected end of file");
            value = FUN_00219430(S->L, buffer, (unsigned int)(length - 1));
            i = local.count;
        }
        f->upvalues[i] = value;
        local.count = i + 1;
    }
}
