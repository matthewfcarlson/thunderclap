// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_00213fc0 @ 0x00213fc0
struct Obj { char pad[6]; char isC; };
struct CallInfo { Obj **func; int pad4; int pad8; int n; };
struct State { char pad0[0x14]; CallInfo *ci; char pad1[0x28 - 0x18]; CallInfo *base_ci; };
struct DebugInfo { char pad[0x5c]; int currentline; };

int FUN_00213fc0(State *L, int level, DebugInfo *ar)
{
    CallInfo *ci = L->ci;
    if (level > 0) {
        do {
            if (ci <= L->base_ci) {
                if (level > 0)
                    return 0;
                break;
            }
            level--;
            if (ci->func[-1]->isC == 0)
                level -= ci->n;
            ci--;
        } while (level > 0);
    }
    if (ci == L->base_ci)
        return 0;
    if (level < 0) {
        ar->currentline = 0;
        return 1;
    }
    ar->currentline = ci - L->base_ci;
    return 1;
}
