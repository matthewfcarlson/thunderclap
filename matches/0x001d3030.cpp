#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"

extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
extern "C" const char* __cdecl FUN_00213190(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);

class Obj_1d3030 : public ScriptHandlerFields {
  public:
    virtual void v0();
    char Check(const char*, int, int);
    const char* Run(const char*, const char*);
};

const char* Obj_1d3030::Run(const char* a, const char* b) {
    const char* result = 0;
    if (Check(DAT_003f6378, 1, 1)) {
        if (Check(a, 0, 1)) {
            if (Check(DAT_00422618, 0, 1)) {
                FUN_002133d0(L, b);
                FUN_00213600(L, -2);
                result = FUN_00213190(L, -1);
            }
        }
    }
    FUN_00212d80(L, 0);
    return result;
}
