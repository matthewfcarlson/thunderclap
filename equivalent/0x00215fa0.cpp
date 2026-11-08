// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 10/10)
// luaO_rawequalObj: same type and the same value (numbers compare as floats).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2) {
    if ((unsigned int)t1->tt != (unsigned int)t2->tt)
        return 0;
    switch ((unsigned int)t1->tt) {
    case LUAVM_TNIL:
        return 1;
    case LUAVM_TNUMBER:
        return t1->value.n == t2->value.n;
    case LUAVM_TBOOLEAN:
        return t1->value.b == t2->value.b;
    default:
        return t1->value.p == t2->value.p;  // light userdata, or the same collectable object
    }
}
