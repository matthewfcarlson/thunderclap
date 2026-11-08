// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 8/8)
// arrayindex: a number key's integer value when it is an integer in (0, lim], else -1.
#include "decls/data/game/global.h"
#include "decls/data/lua.h"

// equiv-conv: FUN_00219980 esi stack
extern "C" int __cdecl FUN_00219980(const LuaVMTObject* key, float lim) {
    if (key->tt == LUAVM_TNUMBER) {
        float n = key->value.n;
        if (n > (*(float*)&DAT_003f32e0) && !(n > lim)) {
            int k = (int)n;
            if (key->value.n == (float)k)
                return k;
        }
    }
    return -1;
}
