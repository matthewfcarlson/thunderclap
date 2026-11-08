// hookf: the debug library's hook (a LuaVMHook): calls the hook table's function of this thread with
// (event name, current line or nil).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: g_key = DAT_00434708, g_names = DAT_00434864

extern "C" {
void __cdecl FUN_00213550(LuaVMState* L, void* p);
void __cdecl FUN_00213600(LuaVMState* L, int i);
int __cdecl FUN_00212f00(LuaVMState* L, int i);
void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
void __cdecl FUN_00213360(LuaVMState* L, int n);
void __cdecl FUN_00213320(LuaVMState* L);
void __cdecl FUN_002139a0(LuaVMState* L, int a, int b);
}

extern "C" void __cdecl FUN_0033a620(LuaVMState* L, LuaVMDebug* ar) {
    FUN_00213550(L, (void*)DAT_00434708);
    FUN_00213600(L, -10000);
    FUN_00213550(L, L);
    FUN_00213600(L, -2);
    if (FUN_00212f00(L, -1) == 6) {
        FUN_002133d0(L, ((const char* const*)&DAT_00434864)[ar->event]);
        if (ar->currentline >= 0) {
            FUN_00213360(L, ar->currentline);
        } else {
            FUN_00213320(L);
        }
        FUN_002139a0(L, 2, 0);
    }
}
