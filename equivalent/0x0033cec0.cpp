// STATUS: equivalent (tools/equiv.py level 3: 2485 inputs, branch coverage 22/22)
// FUN_0033cec0 @ 0x0033cec0
// lstrlib add_s (gsub's replacement: a string with %n captures, or a function)
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" int __cdecl _isdigit(int);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
// equiv-conv: FUN_0033cb10 eax esi
void FUN_0033cb10(int i, LuaVMMatchState* ms);
extern "C" void __cdecl FUN_00339590(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
// equiv-conv: FUN_0033cb70 esi ecx eax
int FUN_0033cb70(LuaVMMatchState* ms, const char* s, const char* e);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);

// equiv-conv: FUN_0033cec0 eax ebx stack stack
void FUN_0033cec0(LuaVMMatchState* ms, LuaVMLBuffer* b, const char* s, const char* e) {
    LuaVMState* L = ms->L;
    if (FUN_00212fb0(L, 3)) {
        const unsigned char* news = (const unsigned char*)FUN_00213190(L, 3);
        unsigned int l = FUN_002131f0(L, 3);
        for (unsigned int i = 0; i < l; ++i) {
            if (news[i] != '%') {
                if (b->p >= b->buffer + LUAVM_BUFFERSIZE)
                    FUN_00339470(b);
                *b->p = news[i];
                ++b->p;
            } else {
                ++i;
                if (!_isdigit(news[i])) {
                    if (b->p >= b->buffer + LUAVM_BUFFERSIZE)
                        FUN_00339470(b);
                    *b->p = news[i];
                    ++b->p;
                } else {
                    int index = (signed char)news[i] - '1';
                    if (index < 0 || index >= ms->level || ms->capture[index].len == LUAVM_CAP_UNFINISHED)
                        index = FUN_00338e20(ms->L, "invalid capture index");
                    FUN_0033cb10(index, ms);
                    FUN_00339590(b);
                }
            }
        }
    } else {
        FUN_00212ed0(L, 3);
        int n = FUN_0033cb70(ms, s, e);
        FUN_002139a0(L, n, 1);
        if (FUN_00212fb0(L, -1))
            FUN_00339590(b);
        else
            FUN_00212d80(L, -2);
    }
}
