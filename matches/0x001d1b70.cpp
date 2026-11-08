#include "decls/data/lua.h"
typedef unsigned int U32_1d1b70;
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" int __cdecl FUN_00339650(LuaVMState*, int);
class Obj_1d1b70 {
  public:
    char pad[8];
    LuaVMState* value;
    bool Target(U32_1d1b70* out);
};
bool Obj_1d1b70::Target(U32_1d1b70* out) {
    bool r = true;
    if (FUN_00212f00(value, -1) != 6) {
        r = false;
        FUN_00212d80(value, -2);
    } else {
        *out = ((unsigned int)FUN_00339650(value, -10000));
    }
    return r;
}
