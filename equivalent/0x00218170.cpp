// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 23/23)
// Arith: ra = rb op rc for numbers (and convertible strings), ^ by the global __pow, else by a metamethod;
// saves pc first and returns the (possibly moved) base.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00215ff0(const char* s, float* result);
extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
// equiv-conv: FUN_00217750 ecx stack eax edx
extern "C" void __cdecl FUN_00217750(LuaVMState* L, const LuaVMTObject* f, const LuaVMTObject* p1,
                                     const LuaVMTObject* p2);
// equiv-conv: FUN_00217790 ecx eax
extern "C" void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res);
// equiv-conv: FUN_00217af0 esi ebx edi stack stack
extern "C" int __cdecl FUN_00217af0(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2, LuaVMTObject* res,
                                    int event);
extern "C" void __cdecl FUN_00214d40(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2);

// equiv-conv: FUN_00218170 eax ecx edx stack stack stack
extern "C" LuaVMTObject* __cdecl FUN_00218170(const LuaVMTObject* rc, const LuaVMTObject* rb, const LuaVMInstruction* pc,
                                          LuaVMState* L, LuaVMTObject* ra, int op) {
    LuaVMValue num;  // luaO_str2d's result, copied by its bits
    LuaVMTObject tempc;
    LuaVMTObject tempb;
    const LuaVMTObject* b = rb;
    const LuaVMTObject* c = rc;
    L->ci->savedpc = pc;

    bool bnum = rb->tt == LUAVM_TNUMBER;
    if (rb->tt == LUAVM_TSTRING) {
        if (FUN_00215ff0(LUAVM_GETSTR(rb->value.gc), &num.n)) {
            tempb.value = num;
            tempb.tt = LUAVM_TNUMBER;
            b = &tempb;
            bnum = true;
        }
    }

    if (bnum) {
        bool cnum = rc->tt == LUAVM_TNUMBER;
        if (rc->tt == LUAVM_TSTRING) {
            if (FUN_00215ff0(LUAVM_GETSTR(rc->value.gc), &num.n)) {
                tempc.value = num;
                tempc.tt = LUAVM_TNUMBER;
                c = &tempc;
                cnum = true;
            }
        }
        if (cnum) {
            switch (op) {
            case 5: {  // TM_ADD
                float v = c->value.n + b->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 6: {  // TM_SUB
                float v = b->value.n - c->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 7: {  // TM_MUL
                float v = c->value.n * b->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 8: {  // TM_DIV
                float v = b->value.n / c->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 9: {  // TM_POW: the global __pow
                const LuaVMTObject* f = FUN_00219e50((LuaVMTable*)L->_gt.value.gc, L->l_G->tmname[9]);
                if (f->tt != LUAVM_TFUNCTION)
                    FUN_00214a90(L, "`__pow' (`^' operator) is not a function");
                FUN_00217750(L, f, b, c);
                FUN_00217790(L, ra);
                return L->base;
            }
            default:
                return L->base;
            }
        }
    }

    if (FUN_00217af0(L, rb, rc, ra, op) == 0)
        FUN_00214d40(L, rb, rc);
    return L->base;
}
