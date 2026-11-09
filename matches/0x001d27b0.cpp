#include "compat/ptr.h"
#include "decls/data/script.h"
// sh_GetString: the Lua global `name` as a string (0x001d10e0 on the handler's state). The caller keeps ecx: the
// game declared 0x001d10e0 a member that does not use `this`; its source defines it as a __stdcall function, which
// the 64-bit build calls (a member call would pass `this` in the first argument register).
#if defined(HULK_PTR64)
const char* __stdcall FUN_001d10e0(const char* name, LuaVMState* L);
#endif
struct ScriptHandler_1d27b0 : public ScriptHandlerFields {
    virtual void v0();
#if !defined(HULK_PTR64)
    const char* FUN_001d10e0(const char* name, LuaVMState* L);
#endif
    const char* Fn(const char* name);
};
const char* ScriptHandler_1d27b0::Fn(const char* name) {
    return FUN_001d10e0(name, L);
}
