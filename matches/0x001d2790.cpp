#include "compat/ptr.h"
#include "decls/data/script.h"
// sh_GetNumber: the Lua global `name` as a number (0x001d1010 on the handler's state). The caller keeps ecx: the
// game declared 0x001d1010 a member that does not use `this`; its source defines it as a __stdcall function, which
// the 64-bit build calls (a member call would pass `this` in the first argument register).
#if defined(HULK_PTR64)
float __stdcall FUN_001d1010(const char* name, LuaVMState* L);
#endif
class ScriptHandler_1d2790 : public ScriptHandlerFields {
  public:
    virtual void v0();
#if !defined(HULK_PTR64)
    float FUN_001d1010(const char* name, LuaVMState* L);
#endif
    hulk_freg run(const char* name);
};
hulk_freg ScriptHandler_1d2790::run(const char* name) {
    return FUN_001d1010(name, L);
}
