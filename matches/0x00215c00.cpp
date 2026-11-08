// f_parser: the protected body of luaD_protectedparser: undump a binary chunk or parse the source, then push
// its main function as a closure with fresh upvalues.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a590(LuaVMZio* z);
extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMProto* __cdecl FUN_00220480(LuaVMState* L, LuaVMZio* Z, LuaVMBuffer* buff, const char* name);
extern "C" LuaVMProto* __cdecl FUN_0021f710(LuaVMState* L, LuaVMZio* z, LuaVMBuffer* buff, const char* name);
extern "C" LuaVMClosure* __cdecl FUN_00219560(LuaVMState* L, int nelems, const LuaVMTObject* e);
extern "C" LuaVMUpVal* __cdecl FUN_002195d0(LuaVMState* L);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

extern "C" void __cdecl FUN_00215c00(LuaVMState* L, void* ud) {
    LuaVMSParser* p = (LuaVMSParser*)ud;
    unsigned int c = (unsigned int)FUN_0021a590(p->z);
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    typedef LuaVMProto*(__cdecl * Loader)(LuaVMState*, LuaVMZio*, LuaVMBuffer*, const char*);
    Loader loader = c == 0x1b ? &FUN_00220480 : &FUN_0021f710;
    LuaVMProto* tf = loader(L, p->z, &p->buff, p->name);
    LuaVMClosure* cl = FUN_00219560(L, tf->nups, &L->_gt);
    cl->l.p = tf;
    for (int i = 0; i < tf->nups; ++i)
        cl->l.upvals[i] = FUN_002195d0(L);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)cl;
    o->tt = LUAVM_TFUNCTION;
    if ((int)((char*)L->stack_last - (char*)L->top) <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top = L->top + 1;
}
