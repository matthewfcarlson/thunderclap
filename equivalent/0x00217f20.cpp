// STATUS: equivalent (tools/equiv.py level 3: 399 inputs, branch coverage 31/32, incomplete)
// luaV_concat: concatenate the total values ending at base[last] (strings and numbers, else by __concat).
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00217640(LuaVMState* L, LuaVMTObject* obj);
extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
extern "C" void __cdecl FUN_00214d20(LuaVMState* L, LuaVMTObject* p1, LuaVMTObject* p2);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

extern "C" void __cdecl FUN_00217f20(LuaVMState* L, int total, int last) {
    int n;
    do {
        LuaVMTObject* top = L->base + last + 1;
        n = 2;
        if ((top[-2].tt == LUAVM_TSTRING || FUN_00217640(L, top - 2)) &&
            (top[-1].tt == LUAVM_TSTRING || FUN_00217640(L, top - 1))) {
            LuaVMString* s1 = (LuaVMString*)top[-1].value.gc;
            if (s1->len != 0) {
                unsigned int tl = ((LuaVMString*)top[-2].value.gc)->len + s1->len;
                if (total > n) {
                    LuaVMTObject* p = top - 3;
                    do {
                        if (p->tt != LUAVM_TSTRING && !FUN_00217640(L, p))
                            break;
                        tl += ((LuaVMString*)p->value.gc)->len;
                        n++;
                        p--;
                    } while (n < total);
                }
                if (tl > 0xfffffffdu)
                    FUN_00214a90(L, "string size overflow");
                char* buffer = FUN_0021a6b0(L, &L->l_G->buff, tl);
                tl = 0;
                for (int i = n; i > 0; i--) {
                    LuaVMString* s = (LuaVMString*)top[-i].value.gc;
                    unsigned int len = s->len;
                    memcpy(buffer + tl, LUAVM_GETSTR(s), len);
                    tl += len;
                }
                top[-n].value.gc = (LuaVMGCObject*)FUN_00219430(L, buffer, tl);
                top[-n].tt = LUAVM_TSTRING;
            }
        } else {
            LuaVMTObject* p1 = top - 2;
            LuaVMTObject* p2 = top - 1;
            const LuaVMTObject* tm = FUN_002175b0(L, p1, 0xd);  // call_binTM(TM_CONCAT), inlined
            if (tm->tt == LUAVM_TNIL)
                tm = FUN_002175b0(L, p2, 0xd);
            if (tm->tt != LUAVM_TFUNCTION) {
                FUN_00214d20(L, p1, p2);
            } else {
                L->top->tt = LUAVM_TFUNCTION;
                L->top->value = tm->value;
                LUAVM_SETOBJ(L->top + 1, p1);
                LUAVM_SETOBJ(L->top + 2, p2);
                hulk_intptr result = (char*)(top - 2) - (char*)L->stack;
                if ((char*)L->stack_last - (char*)L->top <= 3 * (int)sizeof(LuaVMTObject))
                    FUN_00215460(L, 3);
                LuaVMTObject* func = L->top;
                L->top = func + 3;
                FUN_002159e0(L, func, 1);
                LuaVMTObject* res = L->top - 1;
                LuaVMTObject* stack = L->stack;
                L->top = res;
                LuaVMTObject* dst = (LuaVMTObject*)((char*)stack + result);
                LUAVM_SETOBJ(dst, res);
            }
        }
        total -= n - 1;
        last -= n - 1;
    } while (total > 1);
}
