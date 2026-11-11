// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00217520..0x00217600 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f3f875ee {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3f875ee {} using namespace fn_f3f875ee;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f3f875ee {
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);


// 0x00217520 FUN_00217520 (89 B): equivalent/0x00217520.cpp
// sym: _FUN_00217520 @04afb8c74a9c @wc681c10ad78c
// STATUS: equivalent (tools/equiv.py level 3: 2768 inputs, branch coverage 4/4)
// luaT_init: intern the event names (luaT_eventname, DAT_00426a24) into the global state's tmname, fixed.
extern "C" void __cdecl FUN_00217520(LuaVMState* L) {
    for (int i = 0; i < LUAVM_TM_N; ++i) {
        const char* name = DAT_00426a24[i];
        const char* end = name;
        while (*end)
            ++end;
        L->l_G->tmname[i] = FUN_00219430(L, name, (unsigned int)(end - name));
        L->l_G->tmname[i]->marked |= 0x20;
    }
}


// 0x00217580 FUN_00217580 (45 B): matches/0x00217580.cpp
// sym: _FUN_00217580
// luaT_gettm: the event's metamethod in events, or 0 (an absent one is cached in the table's flags).
extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename) {
    const LuaVMTObject* tm = FUN_00219e50(events, ename);
    if (tm->tt == LUAVM_TNIL) {
        events->flags |= (unsigned char)(1 << event);
        return 0;
    }
    return tm;
}


// 0x002175b0 FUN_002175b0 (66 B): matches/0x002175b0.cpp
// sym: _FUN_002175b0
// luaT_gettmbyobj: the event's metamethod of a table or userdata's metatable, or luaO_nilobject.
extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event) {
    LuaVMTable* mt;
    switch (o->tt) {
    case LUAVM_TTABLE:
        mt = ((LuaVMTable*)o->value.gc)->metatable;
        break;
    case LUAVM_TUSERDATA:
        mt = ((LuaVMUdata*)o->value.gc)->metatable;
        break;
    default:
        return LUAVM_NILOBJECT;
    }
    if (mt != 0)
        return FUN_00219e50(mt, L->l_G->tmname[event]);
    return LUAVM_NILOBJECT;
}

} // namespace fn_f3f875ee
