// STATUS: equivalent (tools/equiv.py level 3: 2564 inputs, branch coverage 4/4)
// FUN_0033e570 @ 0x0033e570
// lbaselib composename: replace each `?' of the path piece on the top by the required name
#include "decls/data/lua.h"

extern "C" char *__cdecl strchr(const char *s, int c);

extern "C" const char *__cdecl FUN_00213190(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00338fe0(LuaVMState *L, int space, const char *mes);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_002133d0(LuaVMState *L, const char *s);
extern "C" void __cdecl FUN_00213c90(LuaVMState *L, int n);

// equiv-conv: FUN_0033e570 ebx
void FUN_0033e570(LuaVMState *L)
{
    const char *s = FUN_00213190(L, -1);
    int pieces = 1;
    const char *mark = strchr(s, '?');
    while (mark != 0) {
        FUN_00338fe0(L, 3, "too many marks in a path component");
        FUN_00213380(L, s, (unsigned int)(mark - s));
        FUN_00212ed0(L, 1);
        s = mark + 1;
        pieces += 2;
        mark = strchr(s, '?');
    }
    FUN_002133d0(L, s);
    FUN_00213c90(L, pieces);
}
