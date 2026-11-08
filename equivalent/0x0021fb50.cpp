// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 17/18, incomplete)
// LoadLocals: the local variable count, then each one's name, startpc and endpc.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n);
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

// equiv-conv: FUN_0021fb50 eax stack
extern "C" void __cdecl FUN_0021fb50(LuaVMLoadState* S, LuaVMProto* p) {
    struct {
        int w;
        int count;
        unsigned int size;
        char* s;
        int pad;
        int v;
    } f;  // the original's frame: the integers read from the chunk (32 bits each) and the string buffer
    FUN_0021f8c0((char*)(void*)(&f.v), 4, S);
    if (f.v < 0) {
        FUN_0021f800(S, "bad integer");
    }
    int n = f.v;
    p->locvars = (LuaVMLocVar*)FUN_0021add0(S->L, 0, 0, n * (unsigned int)sizeof(LuaVMLocVar));
    p->sizelocvars = n;
    int i;
    for (i = 0; i < n; i++)
        p->locvars[i].varname = 0;
    f.count = n;
    for (i = 0; i < n; i++) {
        FUN_0021f8c0((char*)(void*)(&f.size), 4, S);
        LuaVMString* name = 0;
        if (f.size != 0) {
            f.s = FUN_0021a6b0(S->L, S->b, f.size);
            if (((int)FUN_0021a610(S->Z, f.s, f.size)))
                FUN_0021f800(S, "unexpected end of file");
            name = FUN_00219430(S->L, f.s, f.size - 1);
        }
        p->locvars[i].varname = name;
        FUN_0021f8c0((char*)(void*)(&f.v), 4, S);
        if (f.v < 0)
            FUN_0021f800(S, "bad integer");
        p->locvars[i].startpc = f.v;
        FUN_0021f8c0((char*)(void*)(&f.w), 4, S);
        if (f.w < 0)
            FUN_0021f800(S, "bad integer");
        p->locvars[i].endpc = f.w;
    }
}
