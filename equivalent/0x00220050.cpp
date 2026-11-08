// STATUS: equivalent (tools/equiv.py level 3: 2915 inputs, branch coverage 24/24)
// LoadFunction: a prototype (anchored on the stack while it loads): source, line, sizes, then its parts.
#include "decls/data/lua.h"

extern "C" LuaVMProto* __cdecl FUN_002196d0(LuaVMState* L);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
// equiv-conv: FUN_0021fa80 eax
extern "C" LuaVMString* __cdecl FUN_0021fa80(LuaVMLoadState* S);
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
// equiv-conv: FUN_0021fcb0 eax ebx
extern "C" void __cdecl FUN_0021fcb0(LuaVMLoadState* S, LuaVMProto* f);
// equiv-conv: FUN_0021faf0 eax ebx
extern "C" void __cdecl FUN_0021faf0(LuaVMLoadState* S, LuaVMProto* f);
// equiv-conv: FUN_0021fb50 eax stack
extern "C" void __cdecl FUN_0021fb50(LuaVMLoadState* S, LuaVMProto* p);
// equiv-conv: FUN_0021fd10 eax stack
extern "C" void __cdecl FUN_0021fd10(LuaVMLoadState* S, LuaVMProto* f);
// equiv-conv: FUN_0021fe20 eax stack
extern "C" void __cdecl FUN_0021fe20(LuaVMLoadState* S, LuaVMProto* f);
extern "C" int __cdecl FUN_002146a0(const LuaVMProto* pt);

// LoadByte (inlined in the original).
static int LoadByte(LuaVMLoadState* S) {
    LuaVMZio* z = S->Z;
    unsigned int n = z->n;
    z->n = n - 1;
    z = S->Z;
    int ch;
    if (n != 0) {
        const char* p = z->p;
        ch = *(const unsigned char*)p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800(S, "unexpected end of file");
    return ch;
}

extern "C" LuaVMProto* __cdecl FUN_00220050(LuaVMLoadState* S, LuaVMString* p) {
    int v;
    LuaVMProto* f = FUN_002196d0(S->L);
    LuaVMState* L = S->L;
    LuaVMTObject* t = L->top;
    t->value.gc = (LuaVMGCObject*)f;
    t->tt = LUAVM_TPROTO;
    L = S->L;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    S->L->top++;
    f->source = FUN_0021fa80(S);
    if (f->source == 0)
        f->source = p;
    FUN_0021f8c0((char*)(void*)(&v), 4, S);
    if (v < 0)
        FUN_0021f800(S, "bad integer");
    f->lineDefined = v;
    f->nups = (unsigned char)LoadByte(S);
    f->numparams = (unsigned char)LoadByte(S);
    f->is_vararg = (unsigned char)LoadByte(S);
    f->maxstacksize = (unsigned char)LoadByte(S);
    FUN_0021fcb0(S, f);
    FUN_0021fb50(S, f);
    FUN_0021fd10(S, f);
    FUN_0021fe20(S, f);
    FUN_0021faf0(S, f);
    if (FUN_002146a0(f) == 0)
        FUN_0021f800(S, "bad code");
    S->L->top--;
    return f;
}
