// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 22/22)
// FUN_0033cff0 @ 0x0033cff0
// cl-flags: /GS
// lstrlib str_gsub
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);
extern "C" const char* __cdecl FUN_0033c7e0(LuaVMMatchState* ms, const char* s, const char* p);
// equiv-conv: FUN_0033cec0 eax ebx stack stack
void FUN_0033cec0(LuaVMMatchState* ms, LuaVMLBuffer* b, const char* s, const char* e);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* B, const char* s, unsigned int l);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);

extern "C" int __cdecl FUN_0033cff0(LuaVMState* L) {
    unsigned int srcl;
    const char* src = FUN_00339df0(L, 1, &srcl);
    const char* p = FUN_00339df0(L, 2, 0);
    int max_s = FUN_00339fe0(L, 4, (int)(srcl + 1));
    bool anchor = (*p == '^');
    if (anchor)
        ++p;
    int n = 0;
    if (FUN_00212d70(L) < 3 || (!FUN_00212fb0(L, 3) && FUN_00212f00(L, 3) != LUAVM_TFUNCTION))
        FUN_00339c30(L, 3, "string or function expected");
    LuaVMLBuffer b;
    FUN_00339630(L, &b);
    LuaVMMatchState ms;
    ms.L = L;
    ms.src_init = src;
    ms.src_end = src + srcl;
    if (max_s > 0) {
        do {
            ms.level = 0;
            const char* e = FUN_0033c7e0(&ms, src, p);
            if (e) {
                ++n;
                FUN_0033cec0(&ms, &b, src, e);
            }
            if (e && e > src)
                src = e;
            else {
                if (src >= ms.src_end)
                    break;
                if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
                    FUN_00339470(&b);
                *b.p = *src;
                ++b.p;
                ++src;
            }
        } while (!anchor && n < max_s);
    }
    FUN_003394b0(&b, src, (unsigned int)(ms.src_end - src));
    FUN_00339540(&b);
    FUN_00213360(L, n);
    return 2;
}
