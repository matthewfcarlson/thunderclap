// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 30/31, incomplete)
// read_long_string: a long string or comment up to the matching closing bracket (nested ones counted); the string
// (seminfo non-null) is interned and anchored in the function's constant table.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021b1c0 edi
extern "C" void FUN_0021b1c0(LuaVMLexState* ls);
// equiv-conv: FUN_0021b0d0 esi
extern "C" void FUN_0021b0d0(LuaVMLexState* ls);
// equiv-conv: FUN_0021b480 eax
extern "C" int FUN_0021b480(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key);

// equiv-conv: FUN_0021b520 ecx eax stack
extern "C" void FUN_0021b520(LuaVMLexState* ls, int sep, LuaVMSemInfo* seminfo) {
    int cont = 0;
    FUN_0021b1c0(ls);
    if (ls->current == 10 || ls->current == 13)
        FUN_0021b0d0(ls);
    for (;;) {
        switch (ls->current) {
        case -1:
            FUN_0021afd0(ls, seminfo ? "unfinished long string" : "unfinished long comment", 0x11f);
            break;
        case '[':
            if (FUN_0021b480(ls) == sep) {
                FUN_0021b1c0(ls);
                cont++;
            }
            break;
        case ']':
            if (FUN_0021b480(ls) == sep) {
                FUN_0021b1c0(ls);
                if (cont-- == 0) {
                    if (seminfo) {
                        LuaVMBuffer* b = ls->buff;
                        LuaVMState* L = ls->L;
                        LuaVMString* ts = FUN_00219430(L, b->buffer + sep + 2, b->n + (0x7ffffffe - sep) * 2);
                        LuaVMTObject* o = FUN_0021a500(L, ls->fs->h, ts);
                        if (o->tt == LUAVM_TNIL) {
                            o->value.b = 1;
                            o->tt = LUAVM_TBOOLEAN;
                        }
                        seminfo->ts = ts;
                    }
                    return;
                }
            }
            break;
        case '\n':
        case '\r': {
            LuaVMBuffer* b = ls->buff;
            if (b->n + 1 > b->buffsize) {
                b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20);
                b->buffsize = b->buffsize * 2 + 0x20;
            }
            b->buffer[b->n] = '\n';
            b->n++;
            FUN_0021b0d0(ls);
            if (!seminfo)
                ls->buff->n = 0;
            break;
        }
        default:
            if (seminfo) {
                FUN_0021b1c0(ls);
            } else {
                LuaVMZio* z = ls->z;
                unsigned int n = z->n;
                z->n = n - 1;
                if (n != 0)
                    ls->current = (unsigned char)*ls->z->p++;
                else
                    ls->current = FUN_0021a550(ls->z);
            }
            break;
        }
    }
}
