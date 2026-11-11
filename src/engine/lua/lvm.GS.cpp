// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00217600..0x002192c0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f8247bb0 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8247bb0 {} using namespace fn_f8247bb0;
#include "engine/lua.h"
// (ren2) sprintf's own name (CRT, C linkage)
#if !defined(HULK_COMPAT_CRT)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif

// ---- declarations shared by the functions below
namespace fn_f8247bb0 {
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);


// 0x00217640 FUN_00217640 (128 B): equivalent/0x00217640.cpp
// sym: _FUN_00217640 @e348251c6e1c @w2946635b4585
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 4/4)
// luaV_tostring: convert a number in place to its string ("%.7g"); 0 when obj is not a number.
extern "C" int __cdecl FUN_00217640(LuaVMState* L, LuaVMTObject* obj) {
    char s[32];
    if (obj->tt != LUAVM_TNUMBER) {
        return 0;
    }
    sprintf(s, "%.7g", (double)obj->value.n);
    const char* e = s;
    while (*e != 0)
        e++;
    obj->value.gc = (LuaVMGCObject*)FUN_00219430(L, s, (unsigned int)(e - s));
    obj->tt = LUAVM_TSTRING;
    return 1;
}

} // namespace fn_f8247bb0
