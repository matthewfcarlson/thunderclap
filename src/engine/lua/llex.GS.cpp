// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021aeb0..0x0021c190 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f548ebf1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f548ebf1 {} using namespace fn_f548ebf1;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f548ebf1 {
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" const char* FUN_0021af60(int token, LuaVMLexState* ls);


// 0x0021afd0 FUN_0021afd0 (134 B): equivalent/0x0021afd0.cpp
// sym: _FUN_0021afd0
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 2/2)
// luaX_lexerror: "source:line: msg" (with "near `token'" when a token is given), then throw a syntax error.
// equiv-conv: FUN_0021af60 eax edi
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token) {
    char buff[0x50];
    FUN_00216340(buff, LUAVM_GETSTR(ls->source), 0x50);
    const char* s = FUN_00216320(ls->L, "%s:%d: %s", buff, ls->linenumber, msg);
    if (token)
        FUN_00216320(ls->L, "%s near `%s'", s, FUN_0021af60(token, ls));
    FUN_002152b0(ls->L, 3);
}

} // namespace fn_f548ebf1
