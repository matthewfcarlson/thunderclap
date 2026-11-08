// STATUS: equivalent (tools/equiv.py level 3: 2964 inputs, branch coverage 22/22)
// patchlistaux: patch every jump of the list (TESTs to ttarget / ftarget with their registers, others to dtarget).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);

// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00220650(int list, LuaVMFuncState* fs, int ttarget, int treg, int ftarget, int freg,
                                     int dtarget) {
    while (list != -1) {
        LuaVMInstruction* code = fs->f->code;
        LuaVMInstruction* cur = &code[list];
        int next;
        int delta = (int)((*cur >> 6) & 0x3ffff) - 0x1ffff;
        if (delta == -1)
            next = -1;
        else
            next = delta + list + 1;

        LuaVMInstruction* p = cur;
        if (list >= 1 && ((char*)&DAT_00426ba4)[code[list - 1] & 0x3f] < 0)
            p = &code[list - 1];

        LuaVMInstruction w = *p;
        int target;
        if ((w & 0x3f) != 0x18) {
            target = dtarget - list - 1;
        } else {
            unsigned int c;
            if ((w & 0x7fc0) != 0) {
                c = (unsigned int)treg;
                if (c == 0xff)
                    c = (w >> 15) & 0x1ff;
                *p = (w & 0xffffff) | (c << 24);
                target = ttarget;
            } else {
                c = (unsigned int)freg;
                if (c == 0xff)
                    c = (w >> 15) & 0x1ff;
                *p = (w & 0xffffff) | (c << 24);
                target = ftarget;
            }
            cur = &fs->f->code[list];
            target = target - list - 1;
        }
        int mag = target < 0 ? -target : target;
        if (mag > 0x1ffff)
            FUN_0021b060(fs->ls, "control structure too long");
        *cur ^= (*cur ^ (((unsigned int)(target + 0x1ffff)) << 6)) & 0xffffc0;
        list = next;
    }
}
