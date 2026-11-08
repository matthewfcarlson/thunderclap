// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 16/16)
// checkArgMode: operand r is valid for argument mode mode (0 unused, 2 register, 3 register or constant).
#include "decls/data/lua.h"

// equiv-conv: FUN_00214280 ecx edx eax
extern "C" int FUN_00214280(int r, const LuaVMProto* pt, int mode) {
    if (mode == 0) return r == 0 ? 1 : 0;
    if (mode == 2) return r < pt->maxstacksize ? 1 : 0;
    if (mode == 3 && r >= pt->maxstacksize) {
        if (r < 250 || r - 250 >= pt->sizek) return 0;
    }
    return 1;
}
