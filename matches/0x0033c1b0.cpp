// writer (str_dump's lua_Writer): add the piece to the buffer in ud
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* B, const char* s, unsigned int l);

extern "C" int __cdecl FUN_0033c1b0(LuaVMState* L, const void* p, unsigned int size, void* ud) {
    FUN_003394b0((LuaVMLBuffer*)ud, (const char*)p, size);
    return 1;
}
