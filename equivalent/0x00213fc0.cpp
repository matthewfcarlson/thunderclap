// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_00213fc0 @ 0x00213fc0
struct Obj_213fc0 { char pad[6]; char isC; };
struct CallInfo_213fc0 { Obj_213fc0 **func; int pad4; int pad8; int n; };
struct State_213fc0 { char pad0[0x14]; CallInfo_213fc0 *ci; char pad1[0x28 - 0x18]; CallInfo_213fc0 *base_ci; };
struct DebugInfo_213fc0 { char pad[0x5c]; int currentline; };

int FUN_00213fc0(State_213fc0 *L, int level, DebugInfo_213fc0 *ar)
{
    CallInfo_213fc0 *ci = L->ci;
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
