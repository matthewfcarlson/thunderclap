#include "compat/ptr.h"
#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void* __cdecl FUN_0008d690(int x);
extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
// 0x001d4210 (matches/0x001d4210.cpp): the closure's initializer (name, object, function); returns this.
class Closure1_1d4210 {
  public:
    Closure1_1d4210* Run(const char*, const char*, const char*);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of closures.
struct Entry_1d1180;
class SortedList {
  public:
    bool FUN_001d1180(Entry_1d1180* e);
};
struct Owner_1d4660 {
    char pad[8];
    LuaVMState* L;    // 0x08
    SortedList list;  // 0x0c
    void FUN_001d4660(const char* a, const char* b, const char* c);
};
void Owner_1d4660::FUN_001d4660(const char* a, const char* b, const char* c) {
    Closure1_1d4210* p = (Closure1_1d4210*)FUN_0008d690(0x24);  // 0x24: 32-bit size of Closure1_1d4210
    Closure1_1d4210* n;
    if (p)
        n = p->Run(a, b, c);
    else
        n = 0;
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    list.FUN_001d1180((Entry_1d1180*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
