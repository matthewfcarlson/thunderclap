#include "decls/data/lua.h"
extern "C" void __cdecl FUN_002151e0(LuaVMState* L);
struct Object_1d2760 {
    char pad[8];
    LuaVMState* L;  // 0x08
    char pad2[0x1064 - 12];
    unsigned char flag;  // 0x1064
    void FUN_001d2760();
};
void Object_1d2760::FUN_001d2760() {
    if (flag) {
        if (L) {
            FUN_002151e0(L);
            L = 0;
        }
        flag = 0;
    }
}
