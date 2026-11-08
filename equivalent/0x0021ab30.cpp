// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 8/8)
// DumpFunction: a prototype (its source unless the parent's, header bytes, lines, locals, upvalue names (none when
// stripped), constants and code).
#include "decls/data/lua.h"

// equiv-conv: FUN_0021a790 eax esi
extern "C" void __cdecl FUN_0021a790(const LuaVMString* s, LuaVMDumpState* D);
// equiv-conv: FUN_0021a830 esi stack
extern "C" void __cdecl FUN_0021a830(LuaVMDumpState* D, const LuaVMProto* f);
// equiv-conv: FUN_0021a960 esi stack
extern "C" void __cdecl FUN_0021a960(LuaVMDumpState* D, const LuaVMProto* f);
// equiv-conv: FUN_0021aa00 esi stack
extern "C" void __cdecl FUN_0021aa00(LuaVMDumpState* D, const LuaVMProto* f);

// One scratch slot serves every value handed to the writer, as in the original (it lives in a dead
// argument slot, so the bytes around a one-byte value are stale).
union LuaVMDumpScratch_21ab30 {
    int i;
    unsigned char c;
};

extern "C" void __cdecl FUN_0021ab30(const LuaVMProto* f, const LuaVMString* p, LuaVMDumpState* D) {
    LuaVMDumpScratch_21ab30 v;
    FUN_0021a790(f->source == p ? 0 : f->source, D);
    v.i = f->lineDefined;
    D->writer(D->L, &v, 4, D->data);
    v.c = f->nups;
    D->writer(D->L, &v, 1, D->data);
    v.c = f->numparams;
    D->writer(D->L, &v, 1, D->data);
    v.c = f->is_vararg;
    D->writer(D->L, &v, 1, D->data);
    v.c = f->maxstacksize;
    D->writer(D->L, &v, 1, D->data);
    if (D->strip) {
        v.i = 0;
        D->writer(D->L, &v, 4, D->data);
    } else {
        v.i = f->sizelineinfo;
        D->writer(D->L, &v, 4, D->data);
        D->writer(D->L, f->lineinfo, f->sizelineinfo * 4, D->data);
    }
    if (D->strip) {
        v.i = 0;
        D->writer(D->L, &v, 4, D->data);
    } else {
        FUN_0021a830(D, f);
    }
    if (D->strip) {
        v.i = 0;
        D->writer(D->L, &v, 4, D->data);
    } else {
        FUN_0021a960(D, f);
    }
    FUN_0021aa00(D, f);
    v.i = f->sizecode;
    D->writer(D->L, &v, 4, D->data);
    D->writer(D->L, f->code, f->sizecode * 4, D->data);
}
