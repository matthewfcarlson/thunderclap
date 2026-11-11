// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021c190..0x0021f800 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f7dcc985 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7dcc985 {} using namespace fn_f7dcc985;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f7dcc985 {
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_0021b160(LuaVMState* L, LuaVMLexState* ls, LuaVMZio* z, LuaVMString* source);
extern "C" void FUN_0021cac0(LuaVMLexState* ls, LuaVMFuncState* fs);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" void __cdecl FUN_0021f640(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" void __cdecl FUN_0021cb80(LuaVMLexState* ls);


// 0x0021f710 FUN_0021f710 (238 B): equivalent/0x0021f710.cpp
// sym: _FUN_0021f710
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 6/6)
// luaY_parser: compile the stream z (named name) into the main function's prototype.
// equiv-conv: FUN_0021cac0 ecx eax
extern "C" LuaVMProto* __cdecl FUN_0021f710(LuaVMState* L, LuaVMZio* z, LuaVMBuffer* buff, const char* name) {
    LuaVMLexState lexstate;
    LuaVMFuncState funcstate;
    lexstate.buff = buff;
    lexstate.nestlevel = 0;
    unsigned int length = 0;
    while (name[length])
        ++length;
    LuaVMString* source = FUN_00219430(L, name, length);
    FUN_0021b160(L, &lexstate, z, source);
    FUN_0021cac0(&lexstate, &funcstate);
    lexstate.lastline = lexstate.linenumber;
    int token = lexstate.lookahead.token;
    if (token != 0x11f) {
        lexstate.t.seminfo = lexstate.lookahead.seminfo;
        lexstate.lookahead.token = 0x11f;
    } else
        token = FUN_0021bbc0(&lexstate, &lexstate.t.seminfo);
    lexstate.t.token = token;
    FUN_0021f640(&lexstate);
    if (lexstate.t.token != 0x11f)
        FUN_0021b060(&lexstate, "<eof> expected");
    FUN_0021cb80(&lexstate);
    return funcstate.f;
}

} // namespace fn_f7dcc985
