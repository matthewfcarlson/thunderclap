#include "compat/ptr.h"
#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void* __cdecl FUN_0008d690(int x);
extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" char DAT_00422810[];
// 0x001d3250 (matches/0x001d3250.cpp): the base closure's initializer (name, function); returns this.
class Method4_1d3250 {
  public:
    Method4_1d3250* Create(const char*, const char*);
};
// the closure this function builds (0x24 bytes on 32-bit): vftable DAT_00422810, the object at +0x20.
struct Closure4_1d46d0 {
    void* vftable;
    char pad[0x1c];
    void* field20;  // 0x20
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of closures.
struct Entry_1d1180;
class SortedList {
  public:
    bool FUN_001d1180(Entry_1d1180* e);
};
struct ScriptHandlerView_1d46d0 {
    char pad[8];
    LuaVMState* L;    // 0x08
    SortedList list;  // 0x0c
};
// 0x001d4830 calls it as ScriptHandler::FUN_001d46d0("sh_CallFuncInGlobalState", this, FUN_001d4460).
class ScriptHandler {
  public:
    void FUN_001d46d0(const char* name, ScriptHandler* obj, LuaVMCFunction fn);
};
void ScriptHandler::FUN_001d46d0(const char* name, ScriptHandler* obj, LuaVMCFunction fn) {
    ScriptHandlerView_1d46d0* self = (ScriptHandlerView_1d46d0*)this;
    Closure4_1d46d0* p = (Closure4_1d46d0*)FUN_0008d690(0x24);  // 0x24: 32-bit size of the closure (Closure4_1d46d0)
    if (p) {
        ((Method4_1d3250*)p)->Create(name, (const char*)fn);
        p->vftable = (void*)DAT_00422810;
        p->field20 = obj;
    } else
        p = 0;
    ((owners::CAgent_1d04b0*)p)->FUN_001d04b0((hulk_intptr)name);
    self->list.FUN_001d1180((Entry_1d1180*)p);
    LuaVMState* x = self->L;
    FUN_00213550(x, p);
    FUN_002134a0(x, FUN_001d22a0, 1);
    FUN_00213790(x, -10001, name);
}
