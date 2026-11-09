#include "compat/ptr.h"
#include "decls/data/script.h"
// ScriptHandler (include/decls/data/script.h): calls the global Lua function `name` with `args` on the handler's
// state (0x001d2190).
class Obj : public ScriptHandlerFields {
  public:
    virtual void v0();
    int FUN_001d2190(const char* name, ScriptCallArgs args, LuaVMState* state);
    int Fn(const char* name, ScriptCallArgs args);
};
int Obj::Fn(const char* name, ScriptCallArgs args) {
    return FUN_001d2190(name, args, L);
}
