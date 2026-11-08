// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 20/20)
// FUN_0033cc10 @ 0x0033cc10
// lstrlib str_find
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx);
extern "C" char* __cdecl strpbrk(const char*, const char*);
extern "C" const char* __cdecl FUN_0033c7e0(LuaVMMatchState* ms, const char* s, const char* p);
// equiv-conv: FUN_0033caa0 eax stack stack stack
const char* FUN_0033caa0(const char* s1, unsigned int l1, const char* s2, unsigned int l2);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
// equiv-conv: FUN_0033cb70 esi ecx eax
int FUN_0033cb70(LuaVMMatchState* ms, const char* s, const char* e);

extern "C" int __cdecl FUN_0033cc10(LuaVMState* L) {
    // the original's frame order (the harness compares the uninitialized locals passed by address)
    struct {
        unsigned int l1;
        const char* pattern;
        unsigned int l2;
        int anchor;
        LuaVMMatchState ms;
    } f;
    const char* s = FUN_00339df0(L, 1, &f.l1);
    const char* p = FUN_00339df0(L, 2, &f.l2);
    f.pattern = p;
    unsigned int oldLength = f.l1;
    int requested = FUN_00339fe0(L, 3, 1);
    if (requested < 0)
        requested = (int)((unsigned)requested + oldLength + 1);
    unsigned int init = (unsigned)requested - 1;
    if ((int)init < 0)
        init = 0;
    else if (init > f.l1)
        init = f.l1;
    if (!FUN_00213160(L, 4) && strpbrk(p, "^$*+?.([%-")) {
        f.anchor = (*p == '^');
        if (f.anchor) {
            ++p;
            f.pattern = p;
        }
        f.ms.src_init = s;
        f.ms.src_end = s + f.l1;
        f.ms.L = L;
        const char* s1 = s + init;
        for (;;) {
            f.ms.level = 0;
            const char* e = FUN_0033c7e0(&f.ms, s1, p);
            if (e) {
                FUN_00213360(L, (int)(s1 - s) + 1);
                FUN_00213360(L, (int)(e - s));
                return FUN_0033cb70(&f.ms, 0, 0) + 2;
            }
            const char* previous = s1++;
            if (previous >= f.ms.src_end || f.anchor)
                break;
            p = f.pattern;
        }
    } else {
        const char* s2 = FUN_0033caa0(s + init, f.l1 - init, p, f.l2);
        if (s2) {
            unsigned int offset = (unsigned int)(s2 - s);
            FUN_00213360(L, (int)(offset + 1));
            FUN_00213360(L, (int)(offset + f.l2));
            return 2;
        }
    }
    FUN_00213320(L);
    return 1;
}
