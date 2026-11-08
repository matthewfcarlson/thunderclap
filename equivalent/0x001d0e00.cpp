// STATUS: equivalent (tools/equiv.py level 3: 2566 inputs, branch coverage 12/12)
// FUN_001d0e00 @ 0x001d0e00
// cl-flags: /GS

#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00213fc0(LuaVMState *L, int level, LuaVMDebug *ar);
extern "C" int __cdecl FUN_00214bd0(LuaVMState *L, const char *options, LuaVMDebug *ar);

// Walks the call stack; frames whose first namewhat letter is not f, g, l or t get source cleared.
void FUN_001d0e00(LuaVMState *L)
{
    struct Frame {
        LuaVMDebug ar;
    } f;

    int level = 1;
    while (FUN_00213fc0(L, level, &f.ar)) {
        if (FUN_00214bd0(L, "Snl", &f.ar)) {
            switch (*f.ar.namewhat) {
            case 'f':
            case 'g':
            case 'l':
            case 't':
                break;
            default:
                f.ar.source = 0;
                break;
            }
        }
        level++;
    }
}
