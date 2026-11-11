// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d0620..0x001d4d50 (kind game, layer game, confidence high), dominant class ScriptHandler
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001d35a0 FUN_001d35a0 (95 B): matches/0x001d35a0.cpp [isolated: macros; on include/gen/ and not mergeable]
// sym: ?FUN_001d35a0@Obj_1d35a0@owners@@QAEHPBDHH@Z
#include "decls/data/lua.h"
#include "gen/owners.h"
#if !defined(HULK_COMPAT_CRT)

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif

#endif
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
// 0x001d2810 (equivalent/0x001d2810.cpp): ScriptHandler::DoLuaBuffer, `this` is the same object.
class ScriptHandler {
  public:
    int FUN_001d2810(LuaVMState* L, const char* buf, int len, const char* name);
};
// handle (include/gen/owners.h Obj_1d35a0 +0x08) is the lua_State, an int member there; x (the chunk name) and
// len are hulk_intptr there: cast at the use.
int owners::Obj_1d35a0::FUN_001d35a0(const char* text, hulk_intptr x, hulk_intptr len) {
    FUN_00212d80((LuaVMState*)(hulk_intptr)handle, 0);
    if (len == -1)
        len = strlen(text);
    int result = 3;
    if (((ScriptHandler*)this)->FUN_001d2810((LuaVMState*)(hulk_intptr)handle, text, (int)len, (const char*)x))
        result = 0;
    state = result;
    return result;
}

