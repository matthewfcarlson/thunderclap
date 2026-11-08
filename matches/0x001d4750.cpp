#include "compat/ptr.h"
#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void* __cdecl FUN_0008d690(int x);
extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
inline void* operator new(hulk_uintptr, void* p) throw() {
    return p;
}
// 0x001d4320 (matches/0x001d4320.cpp): the closure's constructor.
class Closure1 {
  public:
    Closure1(const char* s, int x0, int x1);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of closures.
struct Entry_1d1180;
class SortedList {
  public:
    bool FUN_001d1180(Entry_1d1180* e);
};
struct Owner_1d4750 {
    char pad[8];
    LuaVMState* L;    // 0x08
    SortedList list;  // 0x0c
    void FUN_001d4750(const char* a, int b, int c);
};
void Owner_1d4750::FUN_001d4750(const char* a, int b, int c) {
    Closure1* n = new (FUN_0008d690(0x24)) Closure1(a, b, c);  // 0x24: 32-bit size of Closure1
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    list.FUN_001d1180((Entry_1d1180*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
